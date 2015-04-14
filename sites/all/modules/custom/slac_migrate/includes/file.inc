<?php

/**
 * @file
 * SLAC Today file migration classes.
 */

/**
 * Copies image files over.
 *
 * TODO:
 * NOTE: PATH WILL NEED TO BE CHANGED
 */
class SlacFileCopyMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Images');
    $query = Database::getConnection('default', 'legacy')
             ->select('files', 'f')
             ->fields('f', array('fid', 'filename', 'filepath', 'filemime', 'timestamp', 'status', 'origname'))
             ->condition('f.filemime', 'image%', 'LIKE');
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationFile();
    $this->map = new MigrateSQLMap($this->machineName,
        array('fid' => array(
              'type' => 'int',
              'unsigned' => TRUE,
              'not null' => TRUE,
              'description' => 'Image ID.'
              )
           ),
        MigrateDestinationMedia::getKeySchema()
    );
    $this->destination = new MigrateDestinationMedia('image');

    // Map the filename to the D7 value field.
    // Filepatch set for both source and destination directories is correct.
    // They get adjusted in the prepare method.
    $this->addFieldMapping('value', 'filename');
    $this->addFieldMapping('source_dir', 'filepath');
    $this->addFieldMapping('destination_file', 'filepath');
  }

  // Make adjustments to the data.
  function prepare($entity, $row) {
    // Old version of some image module stored image paths differently.
    // Adjusting the path here.
    $entity->source_dir = '/Users/mickey/websites/slac-d6.local/' . str_replace($row->filename, '', $entity->source_dir);
    $entity->destination_file = str_replace('sites/default/files/', '', $entity->destination_file);
  }
}





/**
 * Migration class for media_youtube entities.
 */
class SlacVideoMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrationvideos');




    $query = Database::getConnection('default', 'legacy')
         ->select('node', 'n');
    $query->join('content_type_video', 'v', 'n.vid = v.vid');
    $query->join('node_revisions', 'nr', 'n.vid = nr.vid');
    $query->fields('n', array('nid', 'vid', 'type', 'title', 'uid', 'status', 'created', 'changed', 'promote', 'sticky'));
    $query->fields('v', array('vid', 'field_media_field_video_embed', 'field_media_field_video_value', 'field_media_field_video_provider', 'field_media_field_video_data'));
    $query->fields('nr', array('vid', 'body', 'teaser', 'format'));
    $query->condition('n.type', 'video', '=');
    $query->condition('v.field_media_field_video_provider', 'youtube', '=');
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationFile();






    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Video node ID.'
        )
      ),
      MigrateDestinationMedia::getKeySchema()
    );


    // In this case, we need to specify the file_class in the second paramter -
    // this class understands how to translate a http://www.youtube.com/ URI
    // into Drupal's Youtube file scheme (youtube://).
    $this->destination = new MigrateDestinationMedia('video',
      'MigrateExtrasFileYoutube');

    // We just need to map the 'value' in the media destination to the Youtube
    // URI.
    $this->addFieldMapping('value', 'field_media_field_video_value');
    $this->addFieldMapping('field_file_shared_caption', 'body');
    //$this->addFieldMapping('title', 'title');



/*
    $this->addUnmigratedDestinations(array('field_video_description:format',
      'field_video_description:language', 'timestamp'));
    if (module_exists('path')) {
      $this->addUnmigratedDestinations(array('path'));
    }
*/
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->field_media_field_video_value = 'https://www.youtube.com/watch?v=' . $row->field_media_field_video_value;
    https://www.youtube.com/watch?v=GZgQjN0aNHM
    //dsm($row, 'row');
  }

  public function prepare($entity, $row) {

    //dsm($entity, 'entity');
  }
}


