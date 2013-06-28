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
      'value' => '<ul><li>Facebook</li><li>Flickr</li><li>RSS</li><li>Twitter</li><li>Youtube</li></ul>',
      'format' => 'full_html',
    ),
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
      'value' => '<p>7am - 6pm, Monday - Friday</p><p><a href="#">Building 50, First Floor Lobby</a></p><p>xHELP (650-926-4357)</p><p><a href="mailto:ithelp@slac.stanford.edu">ithelp@slac.stanford.edu</a></p><p><a href="#">Submit Request</a></p>',
      'format' => 'full_html',
    ),
  );
  $export['it_help_desk'] = $box;

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
<input id="search-button" width="27" type="image" height="22" name="submit" src="https://news.slac.stanford.edu/sites/default/files/search-submit.jpg" alt="go">
<a href="http://www-public.slac.stanford.edu/phonebook/search.aspx">Advanced People Search</a>
</form>',
      'format' => 'full_html',
    ),
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
  $box->title = 'Weather & Traffic';
  $box->description = 'Weather & Traffic';
  $box->options = array(
    'body' => array(
      'value' => '<iframe width="306" height="165" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="https://maps.google.com/maps?f=q&amp;source=s_q&amp;hl=en&amp;geocode=&amp;q=Stanford+Linear+Accelerator,+2575+Sand+Hill+Road,+Menlo+Park,+CA&amp;aq=0&amp;oq=SLAC&amp;sll=38.003385,-79.420925&amp;sspn=4.639537,9.876709&amp;ie=UTF8&amp;hq=&amp;hnear=SLAC+National+Accelerator+Laboratory,+2575+Sand+Hill+Rd,+Menlo+Park,+California+94025-7015&amp;t=m&amp;ll=37.418436,-122.205391&amp;spn=0.044991,0.104713&amp;z=12&amp;output=embed"></iframe><br /><small><a href="https://maps.google.com/maps?f=q&amp;source=embed&amp;hl=en&amp;geocode=&amp;q=Stanford+Linear+Accelerator,+2575+Sand+Hill+Road,+Menlo+Park,+CA&amp;aq=0&amp;oq=SLAC&amp;sll=38.003385,-79.420925&amp;sspn=4.639537,9.876709&amp;ie=UTF8&amp;hq=&amp;hnear=SLAC+National+Accelerator+Laboratory,+2575+Sand+Hill+Rd,+Menlo+Park,+California+94025-7015&amp;t=m&amp;ll=37.418436,-122.205391&amp;spn=0.044991,0.104713&amp;z=12" style="color:#0000FF;text-align:left">View Detailed Traffic Information</a></small>',
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
      'value' => '<form name="search" method="get" action="http://www-psearch.slac.stanford.edu/SLACSearch/app/slac/index?style=mainSite" id="form1">
  <input type="text" id="searchbox" maxlength="2047" class="searchbox" name="qt" size="18" value="Search" onfocus="value=\'\'">
  <input id="search-button" width="27" type="image" height="22" name="submit" src="https://news.slac.stanford.edu/sites/default/files/search-submit.jpg" alt="go">
</form>',
      'format' => 'full_html',
    ),
  );
  $export['web_search'] = $box;

  return $export;
}
