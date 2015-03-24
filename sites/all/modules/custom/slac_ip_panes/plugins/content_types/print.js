/**
 * @file
 * Javascript behaviors for the SLAC IP Custom Panel Panes module.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.slacIpPanesPrint = {
    attach: function(context) {
      if (context === document) {
        $('.js-print-button').once('slacIpPanesPrint', function () {
          var $link = $('<a/>')
          .attr('href', 'javascript:window.print();')
          .text('Print');
          $(this).append($link);
        });
      }
    }
  };
})(jQuery);
