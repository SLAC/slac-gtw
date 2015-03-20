/**
 * @file
 * For Butler Degrees jump menu functionality.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.slacIpPanesPrint = {
     attach: function(context) {
       if (context === document) {
          var $link = $('<a/>')
            .attr('href', 'javascript:window.print();')
            .text('Print');
         $('.js-print-button').append($link).once();
      }
     }
   };
})(jQuery);
