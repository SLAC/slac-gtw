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
      function getParameterByName(name) {
        name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
        var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
          results = regex.exec(location.search);
        return results === null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
      }
      var keyword = getParameterByName('search_api_views_fulltext');
      var re = new RegExp(keyword, 'gi');
      var viewContentDiv = $('div.view-content');
      var viewContent =  viewContentDiv.html();
      viewContent = viewContent.replace(re, function (match) {
        return '<strong>' + match + '</strong>';
      });
      viewContentDiv.html(viewContent);
      $('.view-header').append('containing the words: ' + keyword);
    }
  };

})(jQuery);
