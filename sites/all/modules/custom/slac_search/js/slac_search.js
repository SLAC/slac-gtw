(function ($) {
  'use strict';

  Drupal.behaviors.slac_search = {
    attach: function(context, settings) {
      $('#search-block-form select', context).selectize();
    }
  };

})(jQuery);
