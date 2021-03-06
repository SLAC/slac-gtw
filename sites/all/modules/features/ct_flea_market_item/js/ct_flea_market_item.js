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
    html += '  <h4 class="report-inappropriate-title">Report Community Bulletin Board Post as Inappropriate</h4>';
    html += '  <button class="close top-close">X</button>';
    html += '  <p class="report-message">Flagged ad content will be reviewed by the Office of Communications to determine whether SLAC\'s <a href="https://intranet.slac.stanford.edu/about-community-bulletin-board">Bulletin Board guidelines</a> have been violated.</p>';
    html += '  <p class="flag-wrapper flag-flea-market-inappropriate flag-flea-market-inappropriate-' + nid + '">';
    html += '    <a href="' + href + '" class="submit report-button">Submit</a>';
    html += '    <span>or</span>';
    html += '    <button class="close bottom-close"><span class="close-x">X</span>I\'ve changed my mind, close dialog box</button>';
    html += '  </p>';
    html += '</div>';

    return html;
  };


    /**
   * Process the flag toggle links to add a confirm dialog.
   */
  Drupal.behaviors.commentConfirm = {
    attach: function (context, settings) {
      $('span.flag-wrapper a.flag-link-toggle', context).once('commentConfirm', function () {
        var confirmDialog;
        var flagLink = $(this);

        if (!flagLink.parents('.flag-wrapper').hasClass('flag-comment-flag')) {
          // Don't modify flags that are not on flea market items.
          return;
        }
        if (flagLink.hasClass('unflag-action')) {
          // Don't modify unflag toggle behavior.
          return;
        }

        var href = flagLink.attr('href');
        var nid = /comment_flag\/(\d+)/.exec(href)[1];

        // Unbind the Flag click handler from the flag link and show the confirm
        // form instead.
        var random_id = Math.floor((Math.random() * 100000) + 1);
        $(this)
          .unbind('click')
          .bind('click', function (e) {
            e.preventDefault();
            confirmDialog.toggle();
          })
          .after(Drupal.theme('commentConfirm', href, nid, random_id));

        // Close the confirm dialog if either close button is clicked.
        confirmDialog = $('#comment_confirm' + random_id, context);
        confirmDialog.find('.close').bind('click', function (e) {
          e.preventDefault();
          confirmDialog.toggle();
        });

        // Attach the flag toggle to the custom submit link.
        confirmDialog.find('#comment_confirm' + random_id + ' .submit').addClass('flag flag-action flag-link-toggle');
        Drupal.attachBehaviors(confirmDialog, settings);
      });

      // Re-attach the fleaMarketConfirm behavior after the flag-link changes.
      $('body').once('commentConfirm', function () {
        $(document).bind('flagGlobalAfterLinkUpdate', function() {
          Drupal.attachBehaviors('.flag-comment_flag', settings);
        });
      });
    }
  };

  /**
   * Provides the HTML to create the modal dialog.
   */
  Drupal.theme.commentConfirm = function (href, nid, random_id) {
    var html = '';

    html += '<div id="comment_confirm' + random_id + '" class="report-as-inappropriate" style="display:none;">';
    html += '  <h4 class="report-inappropriate-title">Report Comment as Inappropriate</h4>';
    html += '  <button class="close top-close">X</button>';
    html += '  <p class="report-message">Flagged comment will be reviewed by the Office of Communications to determine whether SLAC\'s guidelines have been violated.</p>';
    html += '  <p class="flag-wrapper flag-comment-inappropriate flag-comment-inappropriate-' + nid + '">';
    html += '    <a href="' + href + '" class="submit report-button">Submit</a>';
    html += '    <span>or</span>';
    html += '    <button class="close bottom-close"><span class="close-x">X</span>I\'ve changed my mind, close dialog box</button>';
    html += '  </p>';
    html += '</div>';

    return html;
  };

})(jQuery);
