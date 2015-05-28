(function ($) {
  'use strict';

  Drupal.behaviors.ct_access_informationNodeForm = {
    attach: function (context, settings) {
      var $publishOn = $('#edit-publish-on-datepicker-popup-0', context);
      var $publishOnTime = $('#edit-publish-on-timeEntry-popup-1', context);

      var year, month;

      // When the Access Notice start date changes, set the Publish On date.
      $('#edit-field-event-date-und-0-value-datepicker-popup-0', context).change(function () {
        var date = new Date($(this).val());
        var day = date.getDate();

        if (!isNaN(day)) {
          // Subtract five (5) days from the start date.
          date.setDate((day - 5));
          day = date.getDate();
          year = date.getFullYear();
          // Date will calculate the correct month based on the new day set in
          // getDate.
          month = (date.getMonth() + 1);

          // The form expects YYYY-mm-dd format.
          $publishOn.val(year + '-' + month + '-' + day);
          if ($publishOnTime.val() === '') {
            $publishOnTime.val('07:00:00am');
          }
        }
      });
    }
  };

}(jQuery));
