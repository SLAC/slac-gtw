<?php
/**
 * @file
 * slac_ip_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function slac_ip_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-maps-and-directions.
  $menus['menu-maps-and-directions'] = array(
    'menu_name' => 'menu-maps-and-directions',
    'title' => 'Maps and Directions',
    'description' => 'Event menu links for the right sidebar.',
  );
  // Exported menu: menu-top-menu.
  $menus['menu-top-menu'] = array(
    'menu_name' => 'menu-top-menu',
    'title' => 'Top Menu',
    'description' => 'Menu links that appear at the top of the page near the Search form.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Event menu links for the right sidebar.');
  t('Main menu');
  t('Maps and Directions');
  t('Menu links that appear at the top of the page near the Search form.');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('Top Menu');


  return $menus;
}
