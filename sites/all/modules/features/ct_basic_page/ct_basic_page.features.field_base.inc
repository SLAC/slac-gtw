<?php
/**
 * @file
 * ct_basic_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ct_basic_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_page_subtitle'
  $field_bases['field_page_subtitle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_page_subtitle',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 160,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
