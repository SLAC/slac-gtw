(function ($) {
  'use strict';

  Drupal.behaviors.fleaMarketConfirm = {
    attach: function (context, settings) {
      $('span.flag-wrapper a.flag-link-toggle', context).once('fleaMarketConfirm', function () {
        var confirmDialog;
        var flagLink = $(this);

        var href = flagLink.attr('href');
        var nid = /flea_market_inappropriate\/(\d+)/.exec(href)[1];

        // Unbind the Flag click handler from the flag link and show the confirm
        // form instead.
        $(this)
          .unbind('click')
          .bind('click', function (e) {
            e.preventDefault();
            confirmDialog.toggle();
          })
          .after(Drupal.theme('FleaMarketConfirm', href, nid));

        // Close the confirm dialog if either close button is clicked.
        confirmDialog = $('#flea_market_flag_confirm', context);
        confirmDialog.find('.close').bind('click', function (e) {
          e.preventDefault();
          confirmDialog.toggle();
        });

        // Attach the flag toggle to the custom submit link.
        confirmDialog.find('.submit').addClass('flag flag-action flag-link-toggle');
        Drupal.attachBehaviors(confirmDialog);
      });
    }
  };

  /**
   * Provide the HTML to create the modal dialog.
   */
  Drupal.theme.FleaMarketConfirm = function (href, nid) {
    var html = '';

    html += '<div id="flea_market_flag_confirm" class="report-as-inappropriate" style="display:none;">';
    html += '  <h4 class="report-inappropriate-title">Report Flea Market Ad as Inappropriate</h4>';
    html += '  <button class="close top-close">X</button>';
    html += '  <p class="report-message">Flagged ad content will be reviewed by the Office of Communications to determine whether SLAC\'s appropriate use policy of the web have been violated.</p>';
    html += '  <p class="flag-wrapper flag-flea-market-inappropriate flag-flea-market-inappropriate-' + nid + '">';
    html += '    <a href="' + href + '" class="submit report-button">Submit</a>';
    html += '    <span>or</span>';
    html += '    <button class="close bottom-close"><span class="close-x">X</span>I\'ve changed my mind, close dialog box</button>';
    html += '  </p>';
    html += '</div>';

    return html;
  };

})(jQuery);
