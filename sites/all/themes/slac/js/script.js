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
      var $menu = $('.region-header #block-system-main-menu .menu:first'),
          $searchbox = $('.region-header #block-boxes-web-search');     
      $('<div id="mobile-menu-wrap"/>').insertBefore('#main')
      $('<ul class="mobile-menu">'+ $menu.html() +'</ul>').appendTo('#mobile-menu-wrap');
      $('<div class="mobile-search">'+ $searchbox.find('form').parent().html() +'</div>').appendTo('#mobile-menu-wrap');
      $('.mobile-search form').append('<input id="people" type="radio" name="searchType" checked="true" value="people" /><label for="search-people">People</label><input id="slac" type="radio" name="searchType" value="slac" /><label for="search-slac">SLAC</label>');
      $('.mobile-search #search-button').attr('src',$('.mobile-search #search-button').attr('src').replace('.jpg','')+'-mobile.jpg');

      //if( /Android|webOS|iPhone|iPad|iPod|BlackBerry|Opera Mini|IEMobile|Firefox/i.test(navigator.userAgent) ) {
        // touch device
        var $menuMobile = $('.mobile-menu'),
            $searchMobile = $('.mobile-search');

            $menuMobile.hide();
            $searchMobile.hide();

        var menuToggle = function(){
          if( $(window).width() < 620 ){
            $menu.parent().toggle(function(){
              if( $searchMobile.is(':visible') ) $searchbox.click();
              $menuMobile.stop(true,true).show();
            },function(){
              $menuMobile.stop(true,true).hide();
            });

            $searchbox.toggle(function(){
              if( $menuMobile.is(':visible') ) $menu.parent().click();
              $searchMobile.stop(true,true).show();
            },function(){
              $searchMobile.stop(true,true).hide();
            });
          } else{
            $searchbox.unbind('click'); $menu.parent().unbind('click');
          }
        }
        // on DOM ready
        menuToggle();
        // on window resize
        try{
          window.addEventListener("orientationchange", menuToggle);
        } catch(e){}
        $(window).resize(menuToggle);
    }
  }

  // search
  // this is a work-around because we can't have a true search form since the public search
  // is not https
  Drupal.behaviors.search = {
     attach: function (context, settings) {
       $('.mobile-search form').submit(function(e) {
          e.preventDefault();
         var search_type = $('.mobile-search form input[name="searchType"]:checked').val();
         var keyword = $('.mobile-search form #searchbox').val();
         // people search
         if (search_type == 'people') {
           var url = "https://www-public.slac.stanford.edu/phonebook/dirsearch.aspx?lf=1&url=&gone=active&NAME=" + keyword;
         } else {
           var url = "http://www-psearch.slac.stanford.edu/SLACSearch/app/slac/index?style=mainSite&qt=" + keyword;
         }
         document.location = url;
       });

       $('form#websearch').submit(function(e) {
          e.preventDefault();
          var keyword = $(this).children('input[type=text]').val();
          var url = "http://www-psearch.slac.stanford.edu/SLACSearch/app/slac/index?style=mainSite&qt=" + keyword;
          document.location = url;
       });
     }
   }

  // alpha pager
  Drupal.behaviors.alphapager = {
     attach: function (context, settings) {
        $('.alpha-link').each(function() {
          var name = $(this).attr('href').substring(1);
          if ($('a[name='+name+']').length == 0) {
            $(this).parent().html(name);
          }
        })
     }
   }
  
  // staff resources page, clicking on a tab goes to a permalink url
  Drupal.behaviors.staff_resource = {
     attach: function (context, settings) {
     var path = Drupal.settings.basePath + 'sites/all/themes/slac/images';
            var text = $('#quicktabs-staff_resources li.active a').text();
            text = text.replace('&', 'and');
            text = text.replace('@', 'at');
            text = text.replace(/ /g,"-");
            text = text.toLowerCase();
            $('.pane-quicktabs-staff-resources .quicktabs-tabpage').css('background', 'whitesmoke url("'+path+'/sr-'+text+'.jpg") no-repeat 0 0');  
        $('#quicktabs-staff_resources li a').unbind('click');
        $('#quicktabs-staff_resources li a').click(function() {
          if ($(this).hasClass('active')) {
              var tab_url = $(this).attr('href');
              document.location = tab_url;
          }
        })
     }
   }

  // Drupal.behaviors.researchLists = {
  //   attach: function (context, settings) {

 //     $('.section-research-resources .view-content .view-grouping-content').append('<span class="collapse">Collapse<img src="/sites/all/themes/slac/images/collapse.png" alt="" /></span>');  
  //    $(window).resize(function() {
  //      if (Modernizr.mq('(max-width: 620px)')) {
  //        $('.section-research-resources .view-content .view-grouping-header').click(function(){
  //          var $this = $(this);
  //          if (!$this.index() && !$this.hasClass('processed')) {
  //            $this.addClass('processed').toggleClass('expanded').siblings('.view-grouping-content').toggle(1, function() {
  //              $this.removeClass('processed');
  //            });
  //            $this.parent().siblings('.view-grouping').find('.view-grouping-content').hide()
  //                 .stop().siblings().removeClass('expanded');
  //          }
  //        });
  //        $('.section-research-resources .view-content .collapse').click(function(){
  //        $(this).closest('.view-grouping-content').hide().siblings().removeClass('expanded');
  //        });
  //        }


  //    });
  //   }
  // }


  Drupal.behaviors.staffCollapse = {
    attach: function (context, settings) {
      $('<div class="collapse-block">Collapse</div>').insertAfter('.section-staff-resources .ui-accordion-content .view-content');
        $('.collapse-block').click(function(){
        $(this).parents('.ui-accordion-content').eq(0).prev().click();
      });
    }
  }

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
      var $links = $('.view-id-research_resource .view-content ul:first > li');
      $links.each(function(){
        var $this = $(this);
        $this.addClass(( $this.find('.item-list').length == 1 ? 'parents no-children' : 'parents'));
      })
    }
  }

  Drupal.behaviors.mobileAccordion = {
    attach: function (context, settings) {
      var $links = $('.view-id-research_resource .parents');

      $links.siblings('.parents').find('.item-list:first').append('<div class="collapse-block">Collapse</div>');
      $('.collapse-block').click(function(){
        $(this).parents('.parents.expanded').find('a.active').click();
      });

      $links.find('.views-field-name:first a').click(function(e){
        e.preventDefault();
        if( $(window).width() > 620 ) return;
        var $this = $(this);
        if( $this.hasClass('active') ){
          $this.parents('.parents.expanded').removeClass('expanded').find('.item-list:first').stop(true,true).slideUp('fast');
          $this.removeClass('active');
        } else{
          $this.parents('.parents').parent().find('a.active').click();
          $this.parents('.parents').addClass('expanded').find('.item-list:first').stop(true,true).slideDown('fast');
          $this.addClass('active');
        }
      });

      // on window resize
      $(window).resize(function(){
        if( $(window).width() > 620 ) $links.find('.item-list:hidden').show();
        else  $links.find('.item-list:first').hide().parents('.parents').filter('.expanded').find('.item-list:first').show();
      })
    }

    /* Staff Resources collapse button */

    // $('.pane-quicktabs-staff-resources-mobile .ui-accordion-content').append('<div class="collapse-block">Collapse</div>');
    // $('.pane-quicktabs-staff-resources-mobile .ui-accordion-content').click(function(){
    //   $(this).closest('.ui-accordion-content').slideUp('fast').removeClass('ui-accordion-content-active')
    //     .prev('h3').removeClass('ui-state-active');
    // });
  }

  Drupal.behaviors.sliderResize = {
    attach: function (context, settings) {
      // fix slider width/height on screen resize
      resizer = function(){
          var slider = $('.views-slideshow-cycle-main-frame:visible'),
              h = slider.find('.views_slideshow_slide:visible img').height();
          slider.css({'width':'100%','height':h})
          .find('.views_slideshow_slide:visible').css({'width':'100%','height':'100%'});
          if( h != slider.find('.views_slideshow_slide:visible img').height() ){resizer()}

          try{setPosition()} catch(e){}
        }
      // on DOM ready
      $(window).load(resizer);
      // on window resize
      try{
        window.addEventListener("orientationchange", resizer);
      } catch(e){}
      $(window).resize(resizer);
      // on slider btns click
      $('.views-slideshow-controls-top *').click(resizer);

      // frontpage mobile fix
      if( $('body').hasClass('front')){
        var leftCol = $('.frontpage-left-col'),
            middleCol = $('.frontpage-middle-col'),
            setPosition = function(){
              if( $('#content').css('position') == 'relative' ){
                leftCol.addClass('layoutfix').css('top',middleCol.height()+12);
                middleCol.css('padding-bottom',leftCol.height()-3);
              } else{
                leftCol.attr('style','').removeClass('layoutfix');
                middleCol.attr('style','');
              }
            }
      }
    }
  }

  Drupal.behaviors.iePlaceholders = {
    attach: function (context, settings) {



    }
  }

})(jQuery, Drupal, this, this.document);
