/**
 * @file
 * Search form custom behaviors.
 */

(function ($) {
  'use strict';

  /**
   * Applies the Selectize plugin and adds dynamic placeholder text to the
   * search input.
   */
  Drupal.behaviors.slac_search = {
    attach: function(context, settings) {
      var placeholders = {
        'default': Drupal.t('Search SLAC Today'),
        'people': Drupal.t('Search People'),
        'enterprise': Drupal.t('Search SLAC Web')
      };
      var $searchInput = $('#slac-search-block-form .form-item-slac-search-block-form input');

      $('#slac-search-block-form select', context).selectize({
        onChange: function(value) {
          $searchInput.attr('placeholder', placeholders[value]);
        }
      });
    }
  };

})(jQuery);
