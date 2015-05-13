(function ($) {
  'use strict';

  Drupal.behaviors.calendarFilters = {
    attach: function (context, settings) {

      // Don't do anything in the Views UI.
      if ($('#views-ui-edit-form').length !== 0) {
        return;
      }

      /**
       * Adds passed select values to an array to be used in the Selectize
       * initialization.
       *
       * Also adds currently selected values to the optionsItems array.
       *
       * @param $select
       *   The jQuery with the SELECT to use options from.
       * @param allVal
       *   The value for the special 'View All' option.
       * @param groupName
       */
      function createOptionsList ($select, allVal, groupName) {
        var options = [{value: allVal, text: 'View All', group: groupName}];
        $select.find('option').each(function () {
          var $this = $(this);
          options.push({
            value: $this.attr('value'),
            text: $this.text(),
            group: groupName
          });
          if ($this.attr('selected')) {
            optionsItems.push($this.attr('value'));
          }
        });

        return options;
      }

      var $selectize;
      var selectizeControl;
      var $selectizeInput; // The area where the selected filters are displayed.

      // Select the view form elements to manipulate with the replacement
      // selectize UI and checkbox.
      var $viewForm;
      if ($(context).is('.view-id-calendar_view')) {
        $viewForm = $('.views-exposed-form', context);
      }
      else {
        $viewForm = $('.view-id-calendar_view .views-exposed-form', context);
      }
      var $typeSelect = $viewForm.find('.form-item-tid select');
      var $tagsSelect = $viewForm.find('.form-item-tid-1 select');
      var $accessSelect = $viewForm.find('.form-item-type select');

      // Create a new select element to use for creating a Selectize widget
      // based on the views term filters.
      var $combinedSelect = $('<select />');
      // Create a new checkbox element to control the 'Show Access Notices'
      // filter.
      var $showAccessElements = $('<p><label><input type="checkbox" /> Show Access Notices</label></p>');
      var $showAccessInput = $showAccessElements.find('input');

      // Set up options and items arrays for Selectize initialization and for
      // using in option value comparissons later.
      var optionsCombined = [];
      var optionsItems = [];
      var optionsType = createOptionsList($typeSelect, 'all', 'type');
      var typeValues = optionsType.map(function (i) {return i.value;});
      var optionsTags = createOptionsList($tagsSelect, 'all2', 'tags');
      var tagsValues = optionsTags.map(function (i) {return i.value;});
      optionsCombined = optionsCombined.concat(optionsType, optionsTags);

      // Add the combined select element to the document.
      $viewForm.parents('.view-calendar-view').prepend($combinedSelect);

      // Update the displayed filters text in the selectize UI.
      function updateSelectizeDisplay (values) {
        var values = values || [];
        var len = values.length;

        $selectizeInput.find('div').hide();

        if (len === 0) {
          $selectizeInput.prepend('<div>Calendar Filters: All</div>');
        }
        else {
          $selectizeInput.prepend('<div>Calendar Filters: ' + (len) + '</div>');
        }
      }

      // Apply the Selectize plugin to the new select element.
      $selectize = $combinedSelect.selectize({
        openOnFocus: true,
        maxItems: null,
        hideSelected: false,
        closeAfterSelect: false,
        allowEmptyOption: true,
        lockOptgroupOrder: true,
        options: optionsCombined,
        items: optionsItems,
        optgroups: [
          {value: 'type', label: 'Filter by Event Type'},
          {value: 'tags', label: 'Filter by Event Tags'}
        ],
        optgroupValueField: 'value',
        optgroupLabelField: 'label',
        optgroupField: 'group',
        onChange: function (values) {
          var setValues = values;

          // If either of the 'View All' options is chosen, remove any selected
          // filters in that optgroup.
          if (values) {
            if (values.indexOf('all') !== -1) {
              // Remove all values from the type select.
              setValues = values.filter(function (v) {
                return (tagsValues.indexOf(v) !== -1);
              });
              selectizeControl.setValue(setValues, false);
            }
            else if (values.indexOf('all2') !== -1) {
              // Remove all values from the tags select.
              setValues = values.filter(function (v) {
                return (typeValues.indexOf(v) !== -1);
              });
              selectizeControl.setValue(setValues, false);
            }

            selectizeControl.refreshOptions();
            updateSelectizeDisplay(setValues);
          }
        },
        onDropdownClose: function ($dropdown) {
          // Update the values of the actual view filter select elements when the
          // Selectize value changes.
          var values = $selectize.val() || [];
          var len = values.length;
          var currentTypeValues = $typeSelect.val() || [];
          var lenTypes = currentTypeValues.length;
          var currentTagsValues = $tagsSelect.val() || [];
          var lenTags = currentTagsValues.length;

          var selectionLengthsMatch = (len == (lenTypes + lenTags));
          var selectionsAllInValues = (values.every(function (v) {
            var inTypes = (currentTypeValues.indexOf(v) !== -1);
            var inTags = (currentTagsValues.indexOf(v) !== -1);
            return (inTypes || inTags);
          }));

          // If the user opened the filter widget, but didn't actually change
          // the current selections, don't update anything.
          if (!(selectionLengthsMatch && selectionsAllInValues)) {
            $typeSelect.val(values.filter(function (v) {return typeValues.indexOf(v) !== -1}));
            $tagsSelect.val(values.filter(function (v) {return tagsValues.indexOf(v) !== -1}));

            // Submit the filter form to apply the new values.
            $viewForm.find('.form-submit').click();
          }
        },
        render: {
          item: function (data, escape) {
            var currentVal = this.getValue() || [];
            var len = currentVal.length;

            // Remove other selected items, this will only display a single
            // summary value.
            if ($selectizeInput !== undefined) {
              $selectizeInput.find('div').hide();
            }

            // Add a selected item to display the current amount of enabled
            // filter values.
            return '<div>Calendar Filters: ' + (len + 1) + '</div>';
          }
        }
      });

      // The selectize input element and control object are needed for updating
      // the display of selected filter state (eg. 'Calendar Filters: 2').
      $selectizeInput = $selectize.parent().find('.selectize-input');
      selectizeControl = $selectize[0].selectize;

      // Update the display to the initial state, afterwards this will be
      // handled in the render, or onChange callback functions.
      updateSelectizeDisplay($selectize.val());

      // Set the initial state of the custom checkbox based on the state of the
      // view filter.
      if ($accessSelect.val() === 'All') {
        $showAccessInput.prop('checked', true);
      }
      else {
        $showAccessInput.prop('checked', false);
      }

      // Add checkbox toggle for the "Show Access Notices" filter above the view
      // header.
      $viewForm.parents('.view-id-calendar_view')
          .find('.view-header')
          .before($showAccessElements);

      // Update the filter when the checkbox is toggled.
      $showAccessInput.click(function () {
        var isChecked = $(this).prop('checked');
        // See the Calendar View filters for the reasoning behind these values.
        // The filter is set up negated so that when 'access_information' is
        // selected, they will not show, otherwise the filter is cleared (All).
        $accessSelect.val((isChecked) ? 'All' : 'access_information');

        // Submit the filter form to apply the new values.
        $viewForm.find('.form-submit').click();
      });

      // Hide the Views filters.
      //$viewForm.hide();
    }
  };

}(jQuery));
