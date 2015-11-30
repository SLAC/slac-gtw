<?php
/**
 * @file
 * ct_flea_market_item.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function ct_flea_market_item_workbench_moderation_export_states() {
  $items = array(
    'draft_flea_market_post' => array(
      'name' => 'draft_flea_market_post',
      'label' => 'Flea Market Post Draft',
      'description' => 'Work in progress',
      'weight' => -9,
    ),
  );
  return $items;
}
