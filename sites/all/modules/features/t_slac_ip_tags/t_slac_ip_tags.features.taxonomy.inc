<?php
/**
 * @file
 * t_slac_ip_tags.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function t_slac_ip_tags_taxonomy_default_vocabularies() {
  return array(
    'slac_ip_tags' => array(
      'name' => 'Slac IP Tags',
      'machine_name' => 'slac_ip_tags',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
