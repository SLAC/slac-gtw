(function ($) {
  'use strict';

  /**
   * Process the flag toggle links to add a confirm dialog.
   */
  Drupal.behaviors.fleaMarketConfirm = {
    attach: function (context, settings) {
      $('span.flag-wrapper a.flag-link-toggle', context).once('fleaMarketConfirm', function () {
        var confirmDialog;
        var flagLink = $(this);

        if (!flagLink.parents('.flag-wrapper').hasClass('flag-flea-market-inappropriate')) {
          // Don't modify flags that are not on flea market items.
          return;
        }
        if (flagLink.hasClass('unflag-action')) {
          // Don't modify unflag toggle behavior.
          return;
        }

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
          .after(Drupal.theme('fleaMarketConfirm', href, nid));

        // Close the confirm dialog if either close button is clicked.
        confirmDialog = $('#flea_market_flag_confirm', context);
        confirmDialog.find('.close').bind('click', function (e) {
          e.preventDefault();
          confirmDialog.toggle();
        });

        // Attach the flag toggle to the custom submit link.
        confirmDialog.find('.submit').addClass('flag flag-action flag-link-toggle');
        Drupal.attachBehaviors(confirmDialog, settings);
      });

      // Re-attach the fleaMarketConfirm behavior after the flag-link changes.
      $('body').once('fleaMarketConfirm', function () {
        $(document).bind('flagGlobalAfterLinkUpdate', function() {
          Drupal.attachBehaviors('.pane-flag-link', settings);
        });
      });
    }
  };

  /**
   * Provides the HTML to create the modal dialog.
   */
  Drupal.theme.fleaMarketConfirm = function (href, nid) {
    var html = '';

    html += '<div id="flea_market_flag_confirm" class="report-as-inappropriate" style="display:none;">';
    html += '  <h4 class="report-inappropriate-title">Report Flea Market Ad as Inappropriate</h4>';
    html += '  <button class="close top-close">X</button>';
    html += '  <p class="report-message">Flagged ad content will be reviewed by the Office of Communications to determine whether SLAC\'s <a href="https://intranet.slac.stanford.edu/about-flea-market">Flea Market guidelines</a> have been violated.</p>';
    html += '  <p class="flag-wrapper flag-flea-market-inappropriate flag-flea-market-inappropriate-' + nid + '">';
    html += '    <a href="' + href + '" class="submit report-button">Submit</a>';
    html += '    <span>or</span>';
    html += '    <button class="close bottom-close"><span class="close-x">X</span>I\'ve changed my mind, close dialog box</button>';
    html += '  </p>';
    html += '</div>';

    return html;
  };

})(jQuery);
