<?php
/**
 * @file
 * slac_seo.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function slac_seo_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer google tag manager'.
  $permissions['administer google tag manager'] = array(
    'name' => 'administer google tag manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'google_tag',
  );

  // Exported permission: 'administer hotjar'.
  $permissions['administer hotjar'] = array(
    'name' => 'administer hotjar',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'hotjar',
  );

  return $permissions;
}
