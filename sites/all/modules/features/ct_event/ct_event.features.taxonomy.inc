<?php
/**
 * @file
 * ct_event.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ct_event_taxonomy_default_vocabularies() {
  return array(
    'event_series' => array(
      'name' => 'Event Series',
      'machine_name' => 'event_series',
      'description' => 'Categorization for Event nodes that belong to an existing series.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
