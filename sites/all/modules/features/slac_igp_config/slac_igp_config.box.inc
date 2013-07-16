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
      'value' => '<ul class="socials">
<li class="fb"><a href="#">Facebook</a></li>
<li class="flickr"><a href="#">Flickr</a></li>
<li class="rss"><a href="#">RSS</a></li>
<li class="twitter"><a href="#">Twitter</a></li>
<li class="youtube"><a href="#">Youtube</a></li>
</ul>',
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
      'value' => '<a href="http://slac.stanford.edu">SLAC NATIONAL ACCELERATOR LABORATORY</a> 2575 Sand Hill Road, Menlo Park, CA 94025 Operated by <a href="http://www.stanford.edu">Stanford University</a> for the <a href="http://science.energy.gov/">U.S. Department of Energy Office of Science</a>',
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
      'value' => '<p>7am - 6pm, Monday - Friday</p><p><a href="#">Building 50, First Floor Lobby</a></p><p>xHELP (650-926-4357)</p><p><a href="mailto:ithelp@slac.stanford.edu">ithelp@slac.stanford.edu</a></p>
<div class="view-footer">
<a href="#">Submit Request</a>
</div>
',
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
      'value' => '<form name="searchForm" id="searchForm">
                <input type="hidden" name="style" value="rebrand">
                <input type="hidden" name="qt" id="qt">
                <input class="searchBox" type="text" id="keyword" name="keyword" placeholder="Search" style="color: rgb(204, 204, 204);">      
                <input id="search-button" class="search-button" width="27" type="image" height="22" name="submit" src="/sites/all/themes/slac/images/search-icon.jpg" alt="go">          
                    <div class="search_type"><input type="radio" name="searchType" id="people" value="people" class="peopleSearch"><span class="searchLabelIE"><a href="http://www-public.slac.stanford.edu/phonebook/search.aspx">People</a></span>
                    <input type="radio" name="searchType" id="web" value="web" class="webSearch"><span class="searchLabelIE"><a href="http://www-psearch.slac.stanford.edu/SLACSearch/app/slac/index?style=mainSite">Web</a></span></div>
                </form>',
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
  $box->title = '';
  $box->description = 'Search (People)';
  $box->options = array(
    'body' => array(
      'value' => '<form name="people_search" method="get" action="http://www-public.slac.stanford.edu/phonebook/dirsearch.aspx" id="people_search">
<input type="text" id="searchbox" maxlength="2047" class="searchbox" name="name" size="18" value="Search" onfocus="value=\'\'">
<input type="hidden" name="gone" value="active" />
<input id="search-button" class="searchbutton" width="27" type="button" value="go" height="22" name="submit" src="https://news.slac.stanford.edu/sites/default/files/search-submit.jpg" alt="go">
<a href="http://www-public.slac.stanford.edu/phonebook/search.aspx" class="advanced-search">Advanced People Search</a>
</form>',
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
      'value' => '<p><a href="#">Site Entry Authorization Form</a></p><p><a href="#">Gate Hours &amp; Access Information</a></p><p>x5555 - Emergency</p><p>x2551 - Non-emergency</p>',
      'format' => 'full_html',
    ),
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
      'value' => '<ul><li>RSB Building Construction</li><li>SUSB Building Construction</li><li>Project Delta - ERP Site</li><li>LCLS II</li><li>FACET Upgrade</li></ul>',
      'format' => 'full_html',
    ),
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
      'value' => '<p><a href="#">Helpline Request Form</a></p><p>650-721-2667 (650-721-COMP)</p><p><a href="mailto:compliance@stanford.edu">compliance@stanford.edu</a></p>',
      'format' => 'full_html',
    ),
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
      'value' => '<form class="header-search" name="search" method="get" action="http://www-psearch.slac.stanford.edu/SLACSearch/app/slac/index?style=mainSite" id="form1">
  <input type="text" id="searchbox" maxlength="2047" class="searchbox" name="qt" size="18" value="Search" onfocus="value=\'\'">
  <input id="search-button" class="search-button" width="27" type="image" height="22" name="submit" src="/sites/all/themes/slac/images/search-icon.jpg" alt="go">
</form>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['web_search'] = $box;

  return $export;
}
