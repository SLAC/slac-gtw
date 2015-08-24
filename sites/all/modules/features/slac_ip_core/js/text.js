(function ($) {

  /**
   * Hides Body textarea if 'Existing / New' is set to 'Link to Existing URL.
   *
   * Unhides the summary, reverses modules/field/modules/text/text.js
   * behavior which will hide the summary if empty.
   */
  Drupal.behaviors.slacIpTextBody = {
    attach: function (context, settings) {
      $('#edit-body', context).once('slacIpTextBody', function () {
        var $body = $(this);
        var $summary = $body.find('.text-summary-wrapper');
        var $bodyFullField = $body.find('div[class*="form-item-body-"][class$="-value"], .filter-wrapper');
        var $radio = $body.siblings('#edit-field-shared-new-existing');

        // Remove the 2nd required asterisk added by states api.
        $bodyFullField.find('label .form-required:nth-child(2n)').remove();

        // If the summary is hidden by field, show it anyway.
        if ($summary.is(':hidden')) {
          $body.find('.link-edit-summary').click();
        }

        // When 'Existing / New' changes, update body field visibility.
        $radio.find('input').change(function (e) {
          if (e.target.value === 'Link to Existing URL') {
            $bodyFullField.hide();
          }
          else {
            $bodyFullField.show();
          }
        });

      });
    }
  };

}(jQuery));
