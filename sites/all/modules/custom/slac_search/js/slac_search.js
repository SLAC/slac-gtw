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
      var $searchInput = $('#search-block-form .form-item-search-block-form input');

      $('#search-block-form select', context).selectize({
        onChange: function(value) {
          $searchInput.attr('placeholder', placeholders[value]);
        }
      });
    }
  };

})(jQuery);
