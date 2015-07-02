<?php
/**
 * @file
 * slac_ip_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function slac_ip_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-maps-and-directions_slac-campus-map:https://www6.slac.stanford.edu/visiting-slac/maps-directions-visitormap.aspx
  $menu_links['menu-maps-and-directions_slac-campus-map:https://www6.slac.stanford.edu/visiting-slac/maps-directions-visitormap.aspx'] = array(
    'menu_name' => 'menu-maps-and-directions',
    'link_path' => 'https://www6.slac.stanford.edu/visiting-slac/maps-directions-visitormap.aspx',
    'router_path' => '',
    'link_title' => 'SLAC Campus Map',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-maps-and-directions_slac-campus-map:https://www6.slac.stanford.edu/visiting-slac/maps-directions-visitormap.aspx',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: menu-maps-and-directions_slac-meeting-rooms-map:https://www6.slac.stanford.edu/visiting-slac/maps-directions-meetingrooms.aspx
  $menu_links['menu-maps-and-directions_slac-meeting-rooms-map:https://www6.slac.stanford.edu/visiting-slac/maps-directions-meetingrooms.aspx'] = array(
    'menu_name' => 'menu-maps-and-directions',
    'link_path' => 'https://www6.slac.stanford.edu/visiting-slac/maps-directions-meetingrooms.aspx',
    'router_path' => '',
    'link_title' => 'SLAC Meeting Rooms Map',
    'options' => array(
      'identifier' => 'menu-maps-and-directions_slac-meeting-rooms-map:https://www6.slac.stanford.edu/visiting-slac/maps-directions-meetingrooms.aspx',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: menu-maps-and-directions_stanford-university-campus-map:https://www6.slac.stanford.edu/sites/www6.slac.stanford.edu/files/stanford_visitor_map.pdf
  $menu_links['menu-maps-and-directions_stanford-university-campus-map:https://www6.slac.stanford.edu/sites/www6.slac.stanford.edu/files/stanford_visitor_map.pdf'] = array(
    'menu_name' => 'menu-maps-and-directions',
    'link_path' => 'https://www6.slac.stanford.edu/sites/www6.slac.stanford.edu/files/stanford_visitor_map.pdf',
    'router_path' => '',
    'link_title' => 'Stanford University Campus Map',
    'options' => array(
      'identifier' => 'menu-maps-and-directions_stanford-university-campus-map:https://www6.slac.stanford.edu/sites/www6.slac.stanford.edu/files/stanford_visitor_map.pdf',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: menu-top-menu_slac-public-home:http://slac.stanford.edu
  $menu_links['menu-top-menu_slac-public-home:http://slac.stanford.edu'] = array(
    'menu_name' => 'menu-top-menu',
    'link_path' => 'http://slac.stanford.edu',
    'router_path' => '',
    'link_title' => 'SLAC Public Home',
    'options' => array(
      'identifier' => 'menu-top-menu_slac-public-home:http://slac.stanford.edu',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-top-menu_stanford-university:http://www.stanford.edu
  $menu_links['menu-top-menu_stanford-university:http://www.stanford.edu'] = array(
    'menu_name' => 'menu-top-menu',
    'link_path' => 'http://www.stanford.edu',
    'router_path' => '',
    'link_title' => 'Stanford University',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-top-menu_stanford-university:http://www.stanford.edu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('SLAC Campus Map');
  t('SLAC Meeting Rooms Map');
  t('SLAC Public Home');
  t('Stanford University');
  t('Stanford University Campus Map');


  return $menu_links;
}
