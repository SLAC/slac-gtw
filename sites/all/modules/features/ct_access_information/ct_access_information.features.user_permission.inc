<?php
/**
 * @file
 * ct_access_information.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ct_access_information_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create access_information content'.
  $permissions['create access_information content'] = array(
    'name' => 'create access_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any access_information content'.
  $permissions['delete any access_information content'] = array(
    'name' => 'delete any access_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own access_information content'.
  $permissions['delete own access_information content'] = array(
    'name' => 'delete own access_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any access_information content'.
  $permissions['edit any access_information content'] = array(
    'name' => 'edit any access_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own access_information content'.
  $permissions['edit own access_information content'] = array(
    'name' => 'edit own access_information content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
