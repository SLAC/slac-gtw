<?php
/**
 * @file
 * slac_igp_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_igp_config_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function slac_igp_config_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function slac_igp_config_node_info() {
  $items = array(
    'access_information' => array(
      'name' => t('Access Information'),
      'base' => 'node_content',
      'description' => t('Information regarding to access, constructions and closure around the lab'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Imported from scientific, training and staff calendars'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'flea_market_post' => array(
      'name' => t('Flea market post'),
      'base' => 'node_content',
      'description' => t('A posting from SLAC today\'s Flea market feature'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news_article' => array(
      'name' => t('News Article'),
      'base' => 'node_content',
      'description' => t('News story imported regularly from various sites around SLAC'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
