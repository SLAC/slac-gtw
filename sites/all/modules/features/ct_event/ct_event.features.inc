<?php
/**
 * @file
 * ct_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_event_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_event_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Events appear in the events listings, can be promoted as news items, and can be added to a user\'s calendar listing. If categorized as an Access Notice, it will be listed there instead of with the normal events listing.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
