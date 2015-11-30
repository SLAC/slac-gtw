<?php
/**
 * @file
 * ct_access_information.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_access_information_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_access_information_node_info() {
  $items = array(
    'access_information' => array(
      'name' => t('Access Information'),
      'base' => 'node_content',
      'description' => t('Information regarding to access, constructions and closure around the lab.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
