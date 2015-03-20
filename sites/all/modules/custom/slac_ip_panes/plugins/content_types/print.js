/**
 * @file
 * For Butler Degrees jump menu functionality.
 */

(function ($) {
  'use strict';

  Drupal.behaviors.slac_ip_panes_print = {
    attach: function(context) {
      var link = '<a href="javascript:window.print();">Print</a>';
      $('.js-print-button').append(link);
    }
  };

})(jQuery);
