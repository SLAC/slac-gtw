/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  // Drupal.behaviors.header = {
  //   attach: function (context, settings) {
  //     $('.region-header .block').prepend('<div class="icon"></div>');
  //   }
  // }


	Drupal.behaviors.researchLists = {
	  attach: function (context, settings) {
		

			if (Modernizr.mq('(max-width: 800px)')) {		


	    	$('.section-research-resources .view-content .view-grouping-content').append('<span class="collapse">Collapse</span>');
	    	$('.section-research-resources .view-content .view-grouping-header').click(function(){
				  var $this = $(this);
	        if (!$this.index() && !$this.hasClass('processed')) {
	          $this.addClass('processed').toggleClass('expanded').siblings('.view-grouping-content').toggle(1, function() {
	            $this.removeClass('processed');
	          });
	          $this.parent().siblings('.view-grouping').find('.view-grouping-content').hide()
	          	   .stop().siblings().removeClass('expanded');
	        }
				});
	    	$('.section-research-resources .view-content .collapse').click(function(){
	    	$(this).closest('.view-grouping-content').hide().siblings().removeClass('expanded');
	    	});
 			
 			}

	  }
	}




})(jQuery, Drupal, this, this.document);
