<?php
/**
 * @file
 * slac_migrate_tag_store.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function slac_migrate_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_slac_migrate_tag_store'
  $field_bases['field_slac_migrate_tag_store'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slac_migrate_tag_store',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
