<?php
/**
 * @file
 * ct_flea_market_item.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function ct_flea_market_item_workbench_moderation_export_transitions() {
  $items = array(
    'draft:published' => array(
      'from_name' => 'draft',
      'to_name' => 'published',
      'name' => 'Publish Flea Market Item',
    ),
  );
  return $items;
}
