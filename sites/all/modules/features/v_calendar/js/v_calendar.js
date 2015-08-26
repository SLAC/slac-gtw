(function ($) {
  'use strict';

  /**
   * Creates a custom widget for Calendar event filters based on the view
   * filters, which are hidden.
   */
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
      var $accessSelect = $viewForm.find('.form-item-type select');

      // Create a new select element to use for creating a Selectize widget
      // based on the views term filters.
      var $combinedSelect = $('<select />');

      // Create a new checkbox to control the 'Show Access Notices' filter.
      var $showAccessElements = $('<p><label><input type="checkbox" /> Show Access Notices</label></p>');
      var $showAccessInput = $showAccessElements.find('input');

      // Set up options and items arrays for Selectize initialization and for
      // using in option value comparissons later.
      var optionsItems = [];
      var optionsType = createOptionsList($typeSelect, 'all', 'type');
      var typeValues = optionsType.map(function (i) {return i.value;});

      // Set the 'All Items' value for each group if no other options in the
      // group are selected.
      var itemsContainsTypeOption = (optionsItems.some(function (elem) {
        return (typeValues.indexOf(elem) !== -1);
      }));
      if (!itemsContainsTypeOption) {
        optionsItems.push('all');
      }

      // Add the combined select element to the document.
      $viewForm.parents('.view-calendar-view').prepend($combinedSelect);

      // Update the displayed filters text in the selectize UI.
      function updateSelectizeDisplay (values) {
        values = values || [];
        // Don't consider "all" values for display update.
        var currentValues = values.filter(function (v) {
          return (v !== 'all' && v !== 'all2');
        });
        var len = currentValues.length;

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
        openOnFocus: false, // handled in $.on function below
        maxItems: null,
        hideSelected: false,
        closeAfterSelect: false,
        allowEmptyOption: true,
        selectOnTab: true,
        lockOptgroupOrder: true,
        options: optionsType,
        items: optionsItems,
        optgroups: [
          {value: 'type', label: 'Filter by Event Type'}
        ],
        optgroupValueField: 'value',
        optgroupLabelField: 'label',
        optgroupField: 'group',
        onDelete: function () {
          return false;
        },
        onItemAdd: function (value, $item) {
          var inTypes;
          var allIndex = -1;

          // If either of the 'View All' options is chosen, remove any selected
          // filters in that optgroup.
          if (value === 'all') {
            // Remove all other values from the type select.
            this.items = this.items.filter(function (v) {
              return (v === 'all' || v === 'all2');
            });
          }
          else {
            // Otherwise, if any other option was selected, remove that group's
            // 'View all' selection, if it was active.
            inTypes = (typeValues.indexOf(value) !== -1);
            if (inTypes) {
              allIndex = this.items.indexOf('all');
            }
            if (allIndex !== -1) {
              this.items.splice(allIndex, 1);
            }
          }
        },
        onChange: function (values) {
          var setValues = values;

          // If either of the 'View All' options is chosen, remove any selected
          // filters in that optgroup.
          if (values) {
            if (values.indexOf('all') !== -1) {
              // Remove all other values from the type select.
              setValues = values.filter(function (v) {
                return (v === 'all' || v === 'all2');
              });
              selectizeControl.setValue(setValues, true);
            }

            selectizeControl.refreshOptions();
            updateSelectizeDisplay(setValues);
          }
        },
        onDropdownClose: function () {
          // Update the values of the actual view filter select elements when the
          // Selectize value changes.
          var values = $selectize.val() || [];

          // Don't consider "all" values.
          values = values.filter(function (v) {
            return (v !== 'all' && v !== 'all2');
          });

          var len = values.length;
          var currentTypeValues = $typeSelect.val() || [];
          var lenTypes = currentTypeValues.length;

          var selectionLengthsMatch = (len === lenTypes);
          // Test if every current selection is already in the values list.
          var selectionsAllInValues = (values.every(function (v) {
            return (currentTypeValues.indexOf(v) !== -1);
          }));

          // If the user opened the filter widget, but didn't actually change
          // the current selections, don't update anything.
          if (!(selectionLengthsMatch && selectionsAllInValues)) {
            $typeSelect.val(values.filter(function (v) {
              return typeValues.indexOf(v) !== -1;
            }));

            // Submit the filter form to apply the new values.
            $viewForm.find('.form-submit').click();
          }
        },
        render: {
          item: function () {
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
      $selectizeInput.find('input').prop('disabled', true);
      selectizeControl = $selectize[0].selectize;

      // Add custom click handler to allow de-select of selected options.
      selectizeControl.$dropdown_content.on('click', function (e) {
        var itemValue = $(e.target).data('value').toString();
        var itemSelectedIndex = selectizeControl.items.indexOf(itemValue);
        if (itemSelectedIndex !== -1) {
          selectizeControl.items.splice(itemSelectedIndex, 1);
          selectizeControl.setValue(selectizeControl.items, true);
          updateSelectizeDisplay(selectizeControl.items);
        }
      });

      // Update the display to the initial state, afterwards this will be
      // handled in the render, or onChange callback functions.
      updateSelectizeDisplay($selectize.val());

      // Open the dropdown control when the input area is clicked as well.
      // Toggle the dropdown closed if the selectize is clicked again.
      $selectizeInput.on('click', function () {
        if (selectizeControl.$dropdown_content.is(':visible')) {
          selectizeControl.close();
        }
        else {
          selectizeControl.open();
        }
      });

      // Handle input focus manually so the dropdown is not triggered twice
      // causing it to immediately close.
      $selectizeInput.on('focus', function () {
        if (!selectizeControl.$dropdown_content.is(':visible')) {
          selectizeControl.open();
        }
      });

      // Workaround for the dropdown being empty the first time the input area
      // is clicked, hide it, then open the dropdown while it is hidden, then
      // after this function is done, close it and un-hide.
      selectizeControl.$dropdown_content.hide();
      selectizeControl.open();
      setTimeout(function () {
        selectizeControl.close();
        selectizeControl.$dropdown_content.show();
      }, 0);

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

    }
  };

}(jQuery));
