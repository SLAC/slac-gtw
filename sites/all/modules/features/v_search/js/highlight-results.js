/**
 * @file
 * Search view custom behaviors.
 */

(function ($) {
  'use strict';

  /**
   * Wraps each instance of the search keyword in strong tags.
   */
  Drupal.behaviors.slac_highlight_results = {
    attach: function(context, settings) {

      /**
       * Get the keyword from the current search path
       * @param name
       * @returns {string}
       */
      function getParameterByName(name) {
        name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
        var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
          results = regex.exec(location.search);
        return results === null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
      }
      var keyword = getParameterByName('search_api_views_fulltext');
      var re = new RegExp(keyword, 'gi');

      // Wrap the keyword instances within the body divs with strong tags
      $('div.field-name-body').html(function (i, text) {
        return text.replace(re, function (match) {
          return '<strong>' + match + '</strong>';
        });
      });
      $('.view-header').append('containing the words: <strong>' + keyword + '</strong>');
    }
  };

})(jQuery);
