<?php
/**
 * @file
 * slac_ip_config_moderation.features.workbench_email.inc
 */

/**
 * Implements hook_workbench_email_export().
 */
function slac_ip_config_moderation_workbench_email_export() {
  $items = array(
    'draft:needs_review:editor' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'author' => 0,
      'automatic' => 1,
      'role' => 'editor',
    ),
    'needs_review:published:editor' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
      'author' => 0,
      'automatic' => 1,
      'role' => 'editor',
    ),
  );
  return $items;
}
