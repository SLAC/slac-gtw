<?php
/**
 * @file
 * ledger_progress_complete.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ledger_progress_complete_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ledger_progress_complete_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ledger_progress_complete_node_info() {
  $items = array(
    'ledger_post' => array(
      'name' => t('Ledger Post'),
      'base' => 'node_content',
      'description' => t('A content type that allows the user to enter nodes for use in the \'Process Ledger\' pane on the main page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
