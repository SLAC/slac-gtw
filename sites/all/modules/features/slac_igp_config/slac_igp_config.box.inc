<?php
/**
 * @file
 * slac_igp_config.box.inc
 */

/**
 * Implements hook_default_box().
 */
function slac_igp_config_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'connect';
  $box->plugin_key = 'simple';
  $box->title = 'Connect';
  $box->description = 'Connect (Social media)';
  $box->options = array(
    'body' => array(
      'value' => '<ul class="socials"><li class="fb"><a href="https://www.facebook.com/SLAC.National.Lab" target="_blank">Facebook</a></li><li class="gplus"><a href="https://plus.google.com/+SLAC/posts" target="_blank">Google+</a></li><li class="flickr"><a href="http://www.flickr.com/photos/slaclab/" target="_blank">Flickr</a></li><li class="rss"><a href="https://news.slac.stanford.edu/tags/staff-benefits-resources/lab-news" target="_blank">RSS</a></li><li class="twitter"><a href="https://twitter.com/SLACLab" target="_blank">Twitter</a></li><li class="youtube"><a href="http://www.youtube.com/user/SLAC" target="_blank">Youtube</a></li></ul>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['connect'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'contact_information';
  $box->plugin_key = 'simple';
  $box->title = 'Contact Information';
  $box->description = 'Contact Information';
  $box->options = array(
    'body' => array(
      'value' => '<p>
<strong>Communications Office</strong>
<br />
Building 267 <br />
650-926-8703 <br />
<a link="mailto:communications@slac.stanford.edu">communications@slac.stanford.edu</a>
</p>
<p>
<strong>Web Solutions, OCIO</strong>
<br />
Building 50 <br />
650-926-5511 <br />
<a link="mailto:websiteservices@slac.stanford.edu">websiteservices@slac.stanford.edu</a>
</p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['contact_information'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'footer';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="http://slac.stanford.edu">SLAC NATIONAL ACCELERATOR LABORATORY</a> <br /> 2575 Sand Hill Road, Menlo Park, CA 94025<br>Operated by <a href="http://www.stanford.edu">Stanford University</a> for the <a href="http://science.energy.gov/">U.S. Department of Energy Office of Science</a></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => 'footer-info',
  );
  $export['footer'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'it_help_desk';
  $box->plugin_key = 'simple';
  $box->title = 'IT Help Desk';
  $box->description = 'IT Help Desk';
  $box->options = array(
    'body' => array(
      'value' => '<p>7am - 5pm, Monday - Friday</p><p><a href="https://www6.slac.stanford.edu/visiting-slac/maps-directions-visitormap.aspx">Building 50, First Floor Lobby</a></p><p>xHELP (650-926-4357)</p><p><a href="mailto:ithelp@slac.stanford.edu">ithelp@slac.stanford.edu</a></p><div class="view-footer"><a href="https://slacprod.service-now.com/ess/order_services.do">Submit IT Help Request</a></div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['it_help_desk'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'search_combined';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Search (Combined)';
  $box->options = array(
    'body' => array(
      'value' => '<form id="searchForm" name="searchForm"><input name="style" type="hidden" value="rebrand"> <input id="qt" name="qt" type="hidden"><input class="searchBox" id="keyword" name="keyword" style="color: rgb(204, 204, 204);" type="text"> <input alt="go" class="search-button" height="22" id="search-button" name="submit" src="/sites/all/themes/slac/images/search-icon.jpg" type="image" width="27"><div class="search_type"><input class="peopleSearch" id="people" name="searchType" type="radio" value="people"><span class="searchLabelIE"><a href="http://www-public.slac.stanford.edu/phonebook/search.aspx">People</a></span> <input class="webSearch" id="web" name="searchType" type="radio" value="web"><span class="searchLabelIE"><a href="http://www-psearch.slac.stanford.edu/SLACSearch/app/slac/index?style=mainSite">Web</a></span></div></form>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['search_combined'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'search_people';
  $box->plugin_key = 'simple';
  $box->title = 'People finder';
  $box->description = 'Search (People)';
  $box->options = array(
    'body' => array(
      'value' => '<form action="https://www-public.slac.stanford.edu/phonebook/dirsearch.aspx" id="people_search" method="get" name="people_search"><label for="searchbox_people">People Finder</label><input class="searchbox" id="searchbox_people" maxlength="2047" name="name" placeholder="People Finder" size="18" type="text"> <input name="gone" type="hidden" value="active"> <input name="lf" type="hidden" value="1"><input name="url" type="hidden" value=""><input alt="go" class="searchbutton" height="22" id="search-button" name="submit" src="https://news.slac.stanford.edu/sites/default/files/search-submit.jpg" type="submit" value="go" width="27"> <a class="advanced-search" href="http://www-public.slac.stanford.edu/phonebook/search.aspx">Advanced People Search</a></form>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['search_people'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'site_security';
  $box->plugin_key = 'simple';
  $box->title = 'Site Security';
  $box->description = 'Site Security';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="https://portal.slac.stanford.edu/info/esh/security">Site Entry Authorization Form</a></p><p><a href="https://www-internal.slac.stanford.edu/esh/security/gatehours.htm">Gate Hours &amp; Access Information</a></p><p>x5555 - Emergency</p><p>x2551 - Non-emergency</p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['site_security'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'slac_projects';
  $box->plugin_key = 'simple';
  $box->title = 'SLAC Projects';
  $box->description = 'SLAC Projects';
  $box->options = array(
    'body' => array(
      'value' => '<div class="img"><img alt="" src="/sites/all/themes/slac/images/linac-thumb.png"></div>
<ul>
	<li>&nbsp;</li>
	<li><a href="https://slacspace.slac.stanford.edu/sites/lcls/lcls-2/Pages/default.aspx">LCLS-II</a></li>
	<li><a href="https://portal.slac.stanford.edu/sites/ard_public/facet/Pages/default.aspx">FACET Upgrade</a></li>
	<li><a href="http://lsst.org/lsst/about/team"><span style="font-family: Arial, sans-serif; line-height: normal;">LSST</span></a></li>
	<li><a href="http://cdms.berkeley.edu/"><span style="font-family: Arial, sans-serif; line-height: normal;">SuperCDMS SNOLAB</span></a></li>
</ul>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['slac_projects'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'stanford_compliance';
  $box->plugin_key = 'simple';
  $box->title = 'Stanford Compliance Helpline';
  $box->description = 'Stanford Compliance Helpline';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="https://acp.stanford.edu/compliance/compliance-and-ethics-helpline">Helpline Request Form</a></p><p>650-721-2667 (650-721-COMP)</p><p><a href="mailto:compliance@stanford.edu">compliance@stanford.edu</a></p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['stanford_compliance'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'weather_traffic';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Traffic Map';
  $box->options = array(
    'body' => array(
      'value' => '    <script src="https://maps.googleapis.com/maps/api/js?v=3.exp&sensor=false"></script>
    <script>
		var map;
		function initialize() {
		  var mapOptions = {
			zoom: 11,
			center: new google.maps.LatLng(37.426569,-122.171059),
			mapTypeId: google.maps.MapTypeId.ROADMAP,
			disableDefaultUI: true,
			zoomControl: true
		  };
		  map = new google.maps.Map(document.getElementById(\'map-canvas\'),
			  mapOptions);
			var trafficLayer = new google.maps.TrafficLayer();
		  trafficLayer.setMap(map);
		}	
		google.maps.event.addDomListener(window, \'load\', initialize);
    </script>
    <div id="map-canvas" style="width:305px;height:165px"></div>
<small><a href="https://www.google.com/maps?q=Stanford+Linear+Accelerator,+2575+Sand+Hill+Road,+Menlo+Park,+CA&sll=38.003384999999994,-79.420925&sspn=6.67462170755311,11.315034649672635&t=m&dg=opt&hq=Stanford+Linear+Accelerator,&hnear=2575+Sand+Hill+Rd,+Menlo+Park,+California+94025&z=11&layer=t" target="_blank">View Detailed Traffic Information</a></small>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['weather_traffic'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'web_search';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Search (Web)';
  $box->options = array(
    'body' => array(
      'value' => '<form action="http://www-psearch.slac.stanford.edu/SLACSearch/app/slac/index" class="header-search" id="websearch" method="get" name="search"><label for="searchbox_web">Search SLAC</label><input class="searchbox" id="searchbox_web" maxlength="2047" name="qt" placeholder="Search SLAC" size="18" type="text"><input name="style" type="hidden" value="mainSite"><input alt="go" class="search-button" height="22" id="search-button" name="submit" src="/sites/all/themes/slac/images/search-icon.jpg" type="image" width="27">&nbsp;</form>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['web_search'] = $box;

  return $export;
}
