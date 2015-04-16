<?php
/**
 * @file
 * ct_flea_market_item.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ct_flea_market_item_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create flea_market_post content'.
  $permissions['create flea_market_post content'] = array(
    'name' => 'create flea_market_post content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
      'site_member' => 'site_member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any flea_market_post content'.
  $permissions['delete any flea_market_post content'] = array(
    'name' => 'delete any flea_market_post content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own flea_market_post content'.
  $permissions['delete own flea_market_post content'] = array(
    'name' => 'delete own flea_market_post content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
      'site_member' => 'site_member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any flea_market_post content'.
  $permissions['edit any flea_market_post content'] = array(
    'name' => 'edit any flea_market_post content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own flea_market_post content'.
  $permissions['edit own flea_market_post content'] = array(
    'name' => 'edit own flea_market_post content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
      'site_member' => 'site_member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'moderate content from draft to draft_flea_market_post'.
  $permissions['moderate content from draft to draft_flea_market_post'] = array(
    'name' => 'moderate content from draft to draft_flea_market_post',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'site_member' => 'site_member',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from draft_flea_market_post to published'.
  $permissions['moderate content from draft_flea_market_post to published'] = array(
    'name' => 'moderate content from draft_flea_market_post to published',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'site_member' => 'site_member',
    ),
    'module' => 'workbench_moderation',
  );

  return $permissions;
}
