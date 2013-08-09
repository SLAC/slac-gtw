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

  Drupal.behaviors.mobileHeader = {
    attach: function (context, settings) {
      if( $('body').width() < 601 ){
        // width < 600px

        var $menu = $('.region-header #block-system-main-menu .menu:first'),
      	    $searchbox = $('.region-header #block-boxes-web-search');      
      	
      	$('<ul class="mobile-menu">'+ $menu.html() +'</ul>').insertBefore('#main');
      	$('<div class="mobile-search">'+ $searchbox.find('form').parent().html() +'</div>').insertBefore('#main');
      	$('.mobile-search form').append('<input id="search-people" type="radio" name="same" checked="true"/><label for="search-people">People</label><input id="search-slac" type="radio" name="same" /><label for="search-slac">SLAC</label>');
        $('.mobile-search #search-button').attr('src',$('.mobile-search #search-button').attr('src').replace('.jpg','')+'-mobile.jpg');

        if( /Android|webOS|iPhone|iPad|iPod|BlackBerry|Opera Mini|IEMobile/i.test(navigator.userAgent) ) {
          // touch device
          var $menuMobile = $('.mobile-menu'),
              $searchMobile = $('.mobile-search');

              $menuMobile.hide();
              $searchMobile.hide();

          $menu.parent().toggle(function(){
            if( $searchMobile.is(':visible') ) $searchbox.click();
          	$menuMobile.fadeIn('slow');
          },function(){
          	$menuMobile.hide();
          });
          
          $searchbox.toggle(function(){
            if( $menuMobile.is(':visible') ) $menu.parent().click();
            $searchMobile.fadeIn('slow');
          },function(){
          	$searchMobile.hide();
          });
        }
      }
    }
  }
  
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

	// Drupal.behaviors.researchLists = {
	//   attach: function (context, settings) {

 //    	$('.section-research-resources .view-content .view-grouping-content').append('<span class="collapse">Collapse<img src="/sites/all/themes/slac/images/collapse.png" alt="" /></span>');	
	// 		$(window).resize(function() {
	// 			if (Modernizr.mq('(max-width: 600px)')) {		
	// 	    	$('.section-research-resources .view-content .view-grouping-header').click(function(){
	// 				  var $this = $(this);
	// 	        if (!$this.index() && !$this.hasClass('processed')) {
	// 	          $this.addClass('processed').toggleClass('expanded').siblings('.view-grouping-content').toggle(1, function() {
	// 	            $this.removeClass('processed');
	// 	          });
	// 	          $this.parent().siblings('.view-grouping').find('.view-grouping-content').hide()
	// 	          	   .stop().siblings().removeClass('expanded');
	// 	        }
	// 				});
	// 	    	$('.section-research-resources .view-content .collapse').click(function(){
	// 	    	$(this).closest('.view-grouping-content').hide().siblings().removeClass('expanded');
	// 	    	});
	//  			}


	// 		});
	//   }
	// }

	Drupal.behaviors.listOddClass = {
	  attach: function (context, settings) {
		$('.brown-bodered-white .menu li').filter(function(index) {return index % 2 == 0}).addClass('odd');
	  }
	}

	Drupal.behaviors.backOnTop = {
	  attach: function (context, settings) {
	  	$('<a href="#" class="back-on-top"><span>Go to top</span></a>').insertBefore('.footer-wrapper')	
	  }
	}

  Drupal.behaviors.researchPage = {
    attach: function (context, settings) {
      // this function adds class 'no-children'
      var $container = $('.view-id-research_resource');
      if( $container.is(':visible') ){
        $container.find('.view-content ul:first > li').each(function(){
          var $this = $(this);
          if( ! $this.find('.item-list ul ul').is(':visible') ){
            $this.addClass('parents no-children');
          } else{
            $this.addClass('parents');
          }
        });
      }
    }
  }

  Drupal.behaviors.mobileAccordion = {
    attach: function (context, settings) {
      var $links = $('.view-id-research_resource .parents');
      
      $links.each(function(){
        $(this).find('.item-list:first').css({'display':'none','height':'auto'})
        .append('<div class="collapse-block">Collapse</div>')
      })
      $('.collapse-block').click(function(){
        $(this).parents('.parents').find('.views-field-name:first a').click();
      })
      $links.find('.views-field-name:first a').toggle(
        function(){
          var $this = $(this);
          $links.each(function(){if($(this).hasClass('expanded')) $(this).find('.views-field-name:first a').click()})
          $this.css('background-image', $this.css('background-image').replace('down','up'));
          $this.parents('.parents').addClass('expanded').find('.item-list:first').stop(true,true).slideDown(300);
          return false;
        },
        function(){
          var $this = $(this);
          $this.css('background-image', $this.css('background-image').replace('up','down'));
          $this.parents('.parents').removeClass('expanded').find('.item-list:first').stop(true,true).slideUp(300);
          return false;
        }
      );
    }
  }

})(jQuery, Drupal, this, this.document);
