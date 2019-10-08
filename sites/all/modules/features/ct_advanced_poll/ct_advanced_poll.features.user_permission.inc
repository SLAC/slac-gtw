<?php
/**
 * @file
 * ct_advanced_poll.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ct_advanced_poll_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access electoral list'.
  $permissions['access electoral list'] = array(
    'name' => 'access electoral list',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'add write-ins'.
  $permissions['add write-ins'] = array(
    'name' => 'add write-ins',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'administer polls'.
  $permissions['administer polls'] = array(
    'name' => 'administer polls',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'show vote results'.
  $permissions['show vote results'] = array(
    'name' => 'show vote results',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'show write-ins'.
  $permissions['show write-ins'] = array(
    'name' => 'show write-ins',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advpoll',
  );

  return $permissions;
}
