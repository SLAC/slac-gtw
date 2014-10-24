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

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create event content.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create news_article content.
  $permissions['create news_article content'] = array(
    'name' => 'create news_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any event content.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any news_article content.
  $permissions['delete any news_article content'] = array(
    'name' => 'delete any news_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own event content.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own news_article content.
  $permissions['delete own news_article content'] = array(
    'name' => 'delete own news_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any event content.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any news_article content.
  $permissions['edit any news_article content'] = array(
    'name' => 'edit any news_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own event content.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own news_article content.
  $permissions['edit own news_article content'] = array(
    'name' => 'edit own news_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'author' => 'author',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'node',
  );

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
