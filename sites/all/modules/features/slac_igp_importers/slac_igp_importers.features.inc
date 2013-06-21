<?php
/**
 * @file
 * slac_igp_importers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_igp_importers_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function slac_igp_importers_node_info() {
  $items = array(
    'calendar_feed' => array(
      'name' => t('Calendar Feed'),
      'base' => 'node_content',
      'description' => t('Represents a specific calendar feed such as Scientific calendar, Training calendar and Staff Calendar'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news_feed' => array(
      'name' => t('News Feed'),
      'base' => 'node_content',
      'description' => t('Represents an RSS news feed such as SLAC today'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
