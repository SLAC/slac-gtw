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

  // Exported permission: import og_tag_importer.
  $permissions['import og_tag_importer'] = array(
    'name' => 'import og_tag_importer',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'og_tag_importer',
  );

  return $permissions;
}
