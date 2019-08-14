<?php
/**
 * @file
 * ct_advanced_poll.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_advanced_poll_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_advanced_poll_node_info() {
  $items = array(
    'advpoll' => array(
      'name' => t('Advanced poll'),
      'base' => 'node_content',
      'description' => t('Advanced poll adds additional poll functionality, cookie voting, write-ins and voting modes.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
