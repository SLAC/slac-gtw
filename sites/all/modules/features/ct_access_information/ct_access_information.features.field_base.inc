<?php
/**
 * @file
 * ct_access_information.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ct_access_information_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_access_start_publishing'.
  $field_bases['field_access_start_publishing'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_access_start_publishing',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
