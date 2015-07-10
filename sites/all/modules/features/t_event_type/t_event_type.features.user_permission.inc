<?php
/**
 * @file
 * t_event_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function t_event_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in event_type'.
  $permissions['delete terms in event_type'] = array(
    'name' => 'delete terms in event_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_type'.
  $permissions['edit terms in event_type'] = array(
    'name' => 'edit terms in event_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
