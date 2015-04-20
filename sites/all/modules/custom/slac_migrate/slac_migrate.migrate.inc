<?php

/**
 * @file
 * SLAC Today migration main file. Declares the migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function slac_migrate_migrate_api() {

  // Declare the api version, migration group, and migrations.
  $api = array(
    'api' => 2,
    'groups' => array(
      'slac' => array(
        'title' => t('SLAC migration'),
      ),
    ),
    'migrations' => array(
      'Images' => array(
        'class_name' => 'SlacImageMigration',
        'group_name' => 'slac',
      ),
      'Videos' => array(
        'class_name' => 'SlacVideoMigration',
        'group_name' => 'slac',
      ),
    ),
  );

  // Using migrate_d2d for nodes and tags.  Setting common arguments here.
  $common_arguments = array(
    'source_connection' => 'legacy',
    'source_version' => 6,
    'group_name' => 'slac',
  );

  // For vocabulary migrations, source_vocabulary and destination_vocabulary are
  // required arguments. Note that in Drupal 6 vocabularies did not have machine
  // names, so we use the vocabulary ID to uniquely identify them.
  $vocabulary_arguments = array(
    'Tags' => array(
      'class_name' => 'DrupalTerm6Migration',
      'description' => t('Migration of tag terms from Drupal 6'),
      'source_vocabulary' => '7',  // D6 Vocabulary ID for Tags
      'destination_vocabulary' => 'slac_ip_tags',
    ),
  );

  //  Vocabulary arguments.
  $common_vocabulary_arguments = $common_arguments + array();
  foreach ($vocabulary_arguments as $migration_name => $arguments) {
    $arguments += $common_vocabulary_arguments;
    $api['migrations'][$migration_name] = $arguments;
  }

  // Node migrations - each has its own class derived from the migrate_d2d class,
  // specifying its particular field mappings and transformations. source_type
  // and destination_type are required arguments.
  $node_arguments = array(
    'Story' => array(
      'class_name' => 'SlacStoryMigration',
      'description' => t('Migration of Story nodes in D6 to News nodes in D7.'),
      'source_type' => 'story',
      'destination_type' => 'news',
      'dependencies' => array('Images', 'Tags', 'Videos'),
    ),
    'Lab_Announcement' => array(
      'class_name' => 'SlacLabAnnouncementMigration',
      'description' => t('Migration of Announcement -> Lab Announcement nodes in D6 to
          News nodes in D7.'),
      'source_type' => 'announcement',
      'destination_type' => 'news',
      'dependencies' => array('Images', 'Tags', 'Videos'),
    ),
    'Calendars' => array(
      'class_name' => 'SlacCalendarsMigration',
      'description' => t('Migration of Announcement -> Scientific Calendar and Announcement -> Staff Calendar
          in D6 to Event nodes in D7'),
      'source_type' => 'announcement',
      'destination_type' => 'event',
      'dependencies' => array('Images', 'Tags', 'Videos'),
    ),
  );

  $common_node_arguments = $common_arguments + array();
  foreach ($node_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }

  return $api;
}