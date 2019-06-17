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
    'alphabets' => array(
      'name' => 'Alphabets',
      'machine_name' => 'alphabets',
      'description' => 'Alphabets that will be used for alpha pagers',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'organization' => array(
      'name' => 'Organization',
      'machine_name' => 'organization',
      'description' => 'Organizations in SLAC',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'related_links' => array(
      'name' => 'Related Links',
      'machine_name' => 'related_links',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'research_resource' => array(
      'name' => 'Research Resource',
      'machine_name' => 'research_resource',
      'description' => 'manages research resources stored in the system',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'staff_resource' => array(
      'name' => 'Staff Resource',
      'machine_name' => 'staff_resource',
      'description' => 'Staff resource to handle new modern view and A-Z index',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => 2,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'top_links' => array(
      'name' => 'Featured Links',
      'machine_name' => 'top_links',
      'description' => 'Top links that will appear on the home page',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
