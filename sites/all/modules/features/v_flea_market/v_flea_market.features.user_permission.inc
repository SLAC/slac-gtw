<?php
/**
 * @file
 * v_flea_market.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function v_flea_market_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag flea_market_inappropriate'.
  $permissions['flag flea_market_inappropriate'] = array(
    'name' => 'flag flea_market_inappropriate',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag flea_market_inappropriate'.
  $permissions['unflag flea_market_inappropriate'] = array(
    'name' => 'unflag flea_market_inappropriate',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
