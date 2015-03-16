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

  // Exported menu link: main-menu_calendar:<front>
  $menu_links['main-menu_calendar:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Calendar',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_calendar:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_news:<front>
  $menu_links['main-menu_news:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_news:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_staff-resources:node/139
  $menu_links['main-menu_staff-resources:node/139'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/139',
    'router_path' => 'node/%',
    'link_title' => 'Staff Resources',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_staff-resources:node/139',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-top-menu_slac-public-site:http://slac.stanford.edu
  $menu_links['menu-top-menu_slac-public-site:http://slac.stanford.edu'] = array(
    'menu_name' => 'menu-top-menu',
    'link_path' => 'http://slac.stanford.edu',
    'router_path' => '',
    'link_title' => 'SLAC Public Site',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-top-menu_slac-public-site:http://slac.stanford.edu',
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
  t('Calendar');
  t('Home');
  t('News');
  t('SLAC Public Site');
  t('Staff Resources');
  t('Stanford University');


  return $menu_links;
}