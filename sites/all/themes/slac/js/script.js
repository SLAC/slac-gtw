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
  
  // combo searchbox
  Drupal.behaviors.search = {
     attach: function (context, settings) {
       $('#searchForm').submit(function(e) {
          e.preventDefault();
         var search_type = $('#searchForm input[name="searchType"]:checked').val();
         var keyword = $('#searchForm #keyword').val();
         // people search
         if (search_type == 'people') {
           var url = "http://www-public.slac.stanford.edu/phonebook/dirsearch.aspx?lf=1&url=&gone=active&NAME=" + keyword;
         } else {
           var url = "http://www-psearch.slac.stanford.edu/SLACSearch/app/slac/index?style=mainSite&qt=" + keyword;
         }
         document.location = url;
       })
     }
   }

	Drupal.behaviors.researchLists = {
	  attach: function (context, settings) {

    	$('.section-research-resources .view-content .view-grouping-content').append('<span class="collapse">Collapse<img src="/sites/all/themes/slac/images/collapse.png" alt="" /></span>');	
			$(window).resize(function() {
				if (Modernizr.mq('(max-width: 600px)')) {		
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


			});
	  }
	}




	// Drupal.behaviors.staffMenu = {
	//   attach: function (context, settings) {

	//   	$(window).resize(function() {
	// 			if (Modernizr.mq('(max-width: 900px)')) {		
	// 				$('.pane-quicktabs-staff-resources .quicktabs-wrapper > .item-list li a').click(function(){
	// 				  var $destination = $(this).closest('li');
	// 				  $('.pane-quicktabs-staff-resources .quicktabs_main').insertAfter($destination).show(1);
	// 				});
	// 			}
	// 		});
	//   }
	// }


})(jQuery, Drupal, this, this.document);
