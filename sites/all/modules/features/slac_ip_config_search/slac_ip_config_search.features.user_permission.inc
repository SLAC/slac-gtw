<?php
/**
 * @file
 * slac_ip_config_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function slac_ip_config_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  return $permissions;
}
