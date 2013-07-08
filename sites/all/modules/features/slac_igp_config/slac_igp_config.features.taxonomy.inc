<?php
/**
 * @file
 * slac_igp_config.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function slac_igp_config_taxonomy_default_vocabularies() {
  return array(
    'related_links' => array(
      'name' => 'Related Links',
      'machine_name' => 'related_links',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'research_resource_subtype' => array(
      'name' => 'Research Resource Subtype',
      'machine_name' => 'research_resource_subtype',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'resource_category_research' => array(
      'name' => 'Resource category (Research)',
      'machine_name' => 'resource_category_research',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'resource_category_staff' => array(
      'name' => 'Resource category (Staff)',
      'machine_name' => 'resource_category_staff',
      'description' => 'Primary way to organize staff resource',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'staff_resource' => array(
      'name' => 'Staff Resource',
      'machine_name' => 'staff_resource',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
