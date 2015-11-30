<?php
#!/usr/bin/env drush
/**
 * Deletes all content of a specific type
 */

/**
 * Implements hook_drush_command().
 */
function  slac_migrate_drush_command() {
  $items = array();
  $items['delete-content'] = array(
    'description' => "Deletes all content of a type.",
    'callback' => 'drush_slac_migrate_delete_content',
    'arguments' => array(
      'type' => 'The content type to whose nodes you wish to delete.',
    ),
  );
  $items['delete-terms'] = array(
    'description' => "Deletes all terms from a vocabulary",
    'callback' => 'drush_slac_migrate_delete_terms',
    'arguments' => array(
      'vocabulary' => 'The vocabulary to whose terms you wish to delete.',
    ),
  );
  $items['delete-feed-nodes'] = array(
    'description' => "Deletes all slac_news feed nodes",
    'callback' => 'drush_slac_migrate_delete_feed_nodes',
  );

  return $items;
}

/**
 * Drush callback for deleting all content of a type.
 */
function drush_slac_migrate_delete_content() {
  $types = func_get_args();
  foreach($types as $type) {
    $query = new EntityFieldQuery;
    $result = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', $type)
      ->execute();

    if (isset($result['node']) && count($result['node'])) {

      $node_ids = array_keys($result['node']);

      node_delete_multiple($node_ids);
      drush_print('Deleted ' . count($node_ids) . ' ' . $type . ' nodes');
    }
  }
}

/**
 * Drush callback for deleting all terms of a vocabulary.
 */
function drush_slac_migrate_delete_terms() {
  $vocabs = func_get_args();
  foreach($vocabs as $vocab) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocab);
    $query = new EntityFieldQuery;
    $result = $query->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('vid', $vocabulary->vid)
      ->execute();

    if (isset($result['taxonomy_term']) && count($result['taxonomy_term'])) {
      $tids = array_keys($result['taxonomy_term']);
      foreach($result['taxonomy_term'] as $term) {
        taxonomy_term_delete($term->tid);
      }
      drush_print('Deleted ' . count($tids) . ' ' . $vocab . ' taxonomy terms.');
    }
  }
}

/**
 * Drush callback for deleting nodes created by slac_news feed importers.
 */
function drush_slac_migrate_delete_feed_nodes() {
  $feed_ids = array(219);
  foreach($feed_ids as $feed_id) {
    $results = db_query("SELECT entity_id FROM feeds_item WHERE id = 'slac_news' AND feed_nid = :feed_id", array(':feed_id' => $feed_id));
    foreach($results as $result) {
      node_delete($result->entity_id);
      drush_print('Deleted node ' . $result->entity_id);
    }
    feeds_source('slac_news', $feed_id)->delete();
  }
}
