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
        'title' => t('SLAC D6 to D7 migration'),
      ),
    ),
  );

  // Using migrate_d2d for nodes, files, and tags.  Setting common arguments here.
  $common_arguments = array(
    'group_name' => 'slac',
    'default_uid' => 0,
  );

  // Create file migrations.
  $file_arguments = array(
    'Videos' => array(
      'class_name' => 'SlacVideoMigration',
      'description' => t('Migration of Videos urls from D6 to D7 video entities'),
      'source_version' => 6,
      'source_connection' => 'legacy',

      ),
    'Images' => array(
      'class_name' => 'SlacImageMigration',
      'description' => t('Migration of Images from D6 to D7 Image entities'),
      'source_version' => 6,
      'source_connection' => 'legacy',
    ),
  );

  //  File arguments.
  $common_file_arguments = $common_arguments + array();
  foreach ($file_arguments as $migration_name => $arguments) {
    $arguments += $common_file_arguments;
    $api['migrations'][$migration_name] = $arguments;
  }

  // For vocabulary migrations, source_vocabulary and destination_vocabulary are
  // required arguments. Note that in Drupal 6 vocabularies did not have machine
  // names, so we use the vocabulary ID to uniquely identify them.
  $vocabulary_arguments = array(
    'Tags' => array(
      'class_name' => 'DrupalTerm6Migration',
      'description' => t('Migration of tag terms from Drupal 6'),
      'source_vocabulary' => '7',  // D6 Vocabulary ID for Tags
      'destination_vocabulary' => 'tags',
      'source_version' => 6,
      'source_connection' => 'legacy',
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
      'source_version' => 6,
      'source_connection' => 'legacy',

    ),
    'Lab_Announcement' => array(
      'class_name' => 'SlacLabAnnouncementMigration',
      'description' => t('Migration of Announcement -> Lab Announcement nodes in D6 to
          News nodes in D7.'),
      'source_type' => 'announcement',
      'destination_type' => 'news',
      'dependencies' => array('Images', 'Tags', 'Videos'),
      'source_version' => 6,
      'source_connection' => 'legacy',

    ),
    'Calendars' => array(
      'class_name' => 'SlacCalendarsMigration',
      'description' => t('Migration of Announcement -> Scientific Calendar and Announcement -> Staff Calendar
          in D6 to Event nodes in D7'),
      'source_type' => 'announcement',
      'destination_type' => 'event',
      'dependencies' => array('Images', 'Tags', 'Videos'),
      'source_version' => 6,
      'source_connection' => 'legacy',

    ),
    'Access_Notice' => array(
      'class_name' => 'SlacAccessNoticeMigration',
      'description' => t('Migration of Announcement -> Access Notice in D6 to Access Information nodes in D7'),
      'source_type' => 'announcement',
      'destination_type' => 'access_information',
      'dependencies' => array('Images', 'Tags', 'Videos'),
      'source_version' => 6,
      'source_connection' => 'legacy',

    ),
    'News_Articles' => array(
      'class_name' => 'SlacNewsArticleMigration',
      'description' => t('Migration of News Articles in D7 to News nodes in D7'),
      'source_type' => 'news_article',
      'destination_type' => 'news',
       'dependencies' => array('Images', 'Tags', 'Videos', 'Story', 'Lab_Announcement', 'Calendars', 'Access_Notice'),
      'source_version' => 7,
      'source_connection' => 'default',
    ),
  );

  $common_node_arguments = $common_arguments + array();
  foreach ($node_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }

  return $api;
}