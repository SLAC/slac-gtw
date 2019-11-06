/**
 * @file
 * Javascript behaviors for the v_calendar feature.
 *
 * Adds two behaviors unless the page is the Views UI: calendarFilters, and
 * calendarAccessNoticeToggle.
 */

(function ($) {
  'use strict';

  // Don't attach these behaviors in the Views UI.
  if ($('#views-ui-edit-form').length !== 0) {
    return;
  }

  // This will maintain the open/closed state of the filters dropwown between
  // attachBehaviors calls.
  var selectizeIsOpen = false;

  // This var has to be in closure to both Drupal.behaviors.calendarFilters and
  // the iOS touch event workaround callback so that when attachBehaviors runs
  // again, the new object is available to both functions.
  var $selectize;

  /**
   * Creates a custom widget for Calendar event filters based on the view
   * filters, which are hidden.
   */
  Drupal.behaviors.calendarFilters = {
    attach: function (context, settings) {

      // Views attaches behaviors twice on ajax, don't process the second one.
      if ($(context).is('form')) {
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

      var selectizeControl;
      var $selectizeInput; // The area where the selected filters are displayed.

      // Select the view form elements to manipulate with the replacement
      // selectize UI.
      var $viewForm = $('.views-exposed-form', context);

      var $typeSelect = $viewForm.find('.form-item-tid select');

      // Create a new select element to use for creating a Selectize widget
      // based on the views term filters.
      var $combinedSelect = $('<select />');

      // Set up options and items arrays for Selectize initialization and for
      // using in option value comparisons later.
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

      /**
       * Updates the values of the actual view filter select elements when the
       * Selectize values have changed.
       *
       * @param {string[]} values
       *   The values to update the view filter select element to.
       * @param {jQuery} $typeSelect
       *   The jQuery collection for the select element in the filters form to
       *   set values in.
       */
      function updateViewsFilters (values, $typeSelect) {
        var len;
        var currentTypeValues = $typeSelect.val() || [];
        var lenTypes = currentTypeValues.length;

        // Don't consider "all" values.
        values = values.filter(function (v) {
          return (v !== 'all' && v !== 'all2');
        });

        len = values.length;

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

          $typeSelect.trigger('change');

          // Submit the filter form to apply the new values.
          $viewForm.find('.form-submit').click();
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
        onInitialize: function () {
          // If the Selectize was open, start open again.
          // ie. after views ajax refresh from a filter update.
          if (selectizeIsOpen) {
            setTimeout(function () {
              selectizeControl.open();
            }, 0);
          }
        },
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
          var setValues = values || [];

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
          updateViewsFilters(setValues, $typeSelect);
        },
        onDropdownClose: function () {
          selectizeIsOpen = false;
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
          selectizeControl.setValue(selectizeControl.items, false);
          updateSelectizeDisplay(selectizeControl.items);
        }
      });

      // Update the display to the initial state, afterwards this will be
      // handled in the above click handler, or the onChange callback.
      updateSelectizeDisplay($selectize.val());

      // Handle input focusing manually so the dropdown is not triggered twice
      // causing it to immediately close.

      // touchstart event is needed to workaround iOS-Safari not handling click
      // events on document or body, remove focus from the dropdown if there is
      // a touch or click event outside the dropdown.
      $('body').once('calendarFiltersTouchStart', function () {
        var touchDevice = false;

        $(document).on('click touchstart', 'body', function (e) {

          // Only process the event once, if touchstart occurs, return without
          // doing anything on click.
          if (e.type === 'touchstart') {
            touchDevice = true;
          }
          else if (touchDevice) {
            // If this event is handled during touchstart, click doesn't need
            // handling here.
            return;
          }

          var $clicked = $(e.target);
          var $selectizeInput = $selectize.find('.selectize-input');
          var selectizeControl = $selectize[0].selectize;

          // Don't close the dropdown if it's being used.
          var $dropdownParents = $clicked.parents('.selectize-dropdown-content');
          var dropdownClicked = ($dropdownParents.length > 0);

          var $selectizeParents = $clicked.parents('.selectize-control');
          var selectizeClicked = ($selectizeParents.length > 0);

          if (!dropdownClicked && selectizeIsOpen) {
            $selectizeInput.blur();
            selectizeControl.close();
            selectizeIsOpen = false;
          }
          else if (!dropdownClicked && selectizeClicked) {
            if (selectizeIsOpen) {
              $selectizeInput.blur();
              selectizeControl.close();
              selectizeIsOpen = false;
            }
            else {
              $selectizeInput.focus();
              selectizeControl.open();
              selectizeIsOpen = true;
            }
          }
        });
      });

      if (!selectizeIsOpen) {
        // Workaround for the dropdown being empty the first time the input area
        // is clicked, hide it, then open the dropdown while it is hidden, then
        // after this function is done, close it and un-hide.
        selectizeControl.$dropdown_content.hide();
        selectizeControl.open();
        setTimeout(function () {
          selectizeControl.close();
          selectizeControl.$dropdown_content.show();
        }, 0);
      }

    }
  };

  /**
   * Creates a custom show/hide toggle checkbox for Access Notice calendar
   * items.
   */
  Drupal.behaviors.calendarAccessNoticeToggle = {
    attach: function (context, settings) {

      var cookieValue = document.cookie.replace(/(?:(?:^|.*;\s*)accesschecked\s*=\s*([^;]*).*$)|^.*$/, '$1');

      // Select the view form elements to add the checkbox to.
      var $viewForm = $('.views-exposed-form', context);
      var $accessItems = $('.view-content .all-day .type-access_information', context);

      // Create a new checkbox to control the 'Show Access Notices' filter.
      var $showAccessElements = $('<p><label><input type="checkbox" /> Show Access Notices</label></p>');
      var $showAccessInput = $showAccessElements.find('input');

      // Add checkbox toggle for the "Show Access Notices" filter above the view
      // header.
      $viewForm.parents('.view-id-calendar_view')
          .find('.view-header')
          .before($showAccessElements);

      if (cookieValue == 'false' || cookieValue == null || cookieValue == '') {
        if ($ ('.calendar-week-view').length ){
          $accessItems.closest('tr').hide();
        } else {
          $accessItems.parent().parent().hide();
        }
      }


      // Update the filter when the checkbox is toggled.
      $showAccessInput.change(function () {
        var isChecked = $(this).prop('checked');

        if (isChecked) {
          // Show Access Notice items.
          $accessItems.show();
          if ($ ('.calendar-week-view').length ){
            $accessItems.closest('tr').show();
          } else {
            $accessItems.parent().parent().show();
          }

          // Set the cookie value.
          document.cookie = 'accesschecked=true;path=/';
        }
        else {
          // Hide Access Notice items.
          $accessItems.hide();
          if ($ ('.calendar-week-view').length ){
            $accessItems.closest('tr').hide();
          } else {
            $accessItems.parent().parent().hide();
          }
          document.cookie = 'accesschecked=false;path=/';
        }
      });

      // Set the initial state of the custom checkbox and view contents based on
      // the state of the user's cookie.
      if ($showAccessInput.val() !== undefined) {
        if (cookieValue === 'true') {
          $showAccessInput.prop('checked', true);
        }
        else {
          $showAccessInput.prop('checked', false);
          // Hide Access Notice items.
          $accessItems.hide();
        }
      }

    }
  };

}(jQuery));
