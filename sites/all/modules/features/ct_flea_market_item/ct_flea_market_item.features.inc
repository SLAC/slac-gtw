<?php
/**
 * @file
 * ct_flea_market_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_flea_market_item_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ct_flea_market_item_node_info() {
  $items = array(
    'flea_market_post' => array(
      'name' => t('Flea Market Item'),
      'base' => 'node_content',
      'description' => t('An item posting for the Flea market feature.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
