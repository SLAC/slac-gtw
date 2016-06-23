<?php
/**
 * @file
 * slac_igp_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function slac_igp_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer scheduler'.
  $permissions['administer scheduler'] = array(
    'name' => 'administer scheduler',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'administer stanford date timepicker'.
  $permissions['administer stanford date timepicker'] = array(
    'name' => 'administer stanford date timepicker',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stanford_date_timepicker',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'view scheduled content'.
  $permissions['view scheduled content'] = array(
    'name' => 'view scheduled content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'scheduler',
  );

  return $permissions;
}
