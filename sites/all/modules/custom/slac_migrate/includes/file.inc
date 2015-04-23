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
class SlacImageMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Images');
    $query = Database::getConnection('default', 'legacy')
             ->select('files', 'f')
             ->fields('f', array('fid', 'filename', 'filepath', 'filemime', 'timestamp', 'status', 'origname'))
             ->condition('f.filemime', 'image%', 'LIKE');
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));
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
    $this->description = t('Slac Video Migration');

    $query = Database::getConnection('default', 'legacy')
         ->select('node', 'n');
    $query->join('content_type_video', 'v', 'n.vid = v.vid');
    $query->join('node_revisions', 'nr', 'n.vid = nr.vid');
    $query->fields('n', array('nid', 'vid', 'type', 'title', 'uid', 'created'));
    $query->fields('v', array('vid', 'field_media_field_video_value', 'field_media_field_video_provider'));
    $query->fields('nr', array('vid', 'body', 'format'));
    $query->condition('n.type', 'video', '=');
    $or = db_or();
    $or->condition('v.field_media_field_video_provider', 'youtube', '=');
    $or->condition('v.field_media_field_video_provider', 'vimeo', '=');
    $query->condition($or);
    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));

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

    // In this case, we need to specify the file_class in the second parameter -
    // this class understands how to translate a http://www.youtube.com/ URI
    // into Drupal's Youtube file scheme (youtube://).
    $this->destination = new MigrateDestinationMedia('video',
      'SlacMigrateAllVideos');

    // Field mappings.
    $this->addFieldMapping('value', 'field_media_field_video_value');
    $this->addFieldMapping('field_file_shared_caption', 'body');
    $this->addFieldMapping('field_file_shared_caption:format', 'format');
    $this->addFieldMapping('timestamp', 'created');
    $this->addFieldMapping(NULL, 'title');

    // Unmigrated destination fields.
    $this->addUnmigratedDestinations(array('field_file_shared_caption:language', 'path'));

    // Unmapped destination metatag fields.
    $this->addUnmigratedDestinations(array(
      'metatag_title', 'metatag_description', 'metatag_abstract', 'metatag_keywords', 'metatag_robots',
      'metatag_news_keywords', 'metatag_standout', 'metatag_generator', 'metatag_rights', 'metatag_image_src',
      'metatag_canonical', 'metatag_shortlink', 'metatag_publisher', 'metatag_author', 'metatag_original-source',
      'metatag_revisit-after', 'metatag_content-language',
    ));

    // Unmigrated source fields.
    $this->addUnmigratedSources(array('vid', 'type', 'v_vid', 'field_media_field_video_provider', 'nr_vid', 'title'));
  }

  /**
   * Implements prepareRow method.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Convert filter formats.
    if ($row->format == 2) {
      $row->format = 'full_html';
    }
    elseif ($row->format == 1) {
      $row->format = 'filtered_html';
    }
    else {
      $row->format = 'full_html';
    }
  }

  /**
   * Implements complete method.
   */
  public function complete($entity, stdClass $row) {

    // Import custom file fields and overwrite title field.
    // Youtube module automatically sets Youtube title.
    $entity->field_file_shared_caption[LANGUAGE_NONE][0]['value'] = $row->body;
    $entity->field_file_shared_caption[LANGUAGE_NONE][0]['format'] = $row->format;
    $entity->filename = $row->title;
    entity_save('file', $entity);
  }
}


/**
 * Class for creating Youtube file entities.
 */
class SlacMigrateAllVideos implements MigrateFileInterface {
  /**
   * Implementation of MigrateFileInterface::fields().
   *
   * @return array
   */
  static public function fields() {
    return array();
  }

  /**
   * Implementation of MigrateFileInterface::processFiles().
   *
   * @param $value
   *  The URI or local filespec of a file to be imported.
   * @param $owner
   *  User ID (uid) to be the owner of the file.
   * @return object
   *  The file entity being created or referenced.
   */
  public function processFile($value, $owner) {

    $settings = array();

    // Video is a Vimeo video.
    if (is_numeric($value)) {
      $settings['handler'] = 'MediaInternetVimeoHandler';
      $settings['video_type'] = 'Vimeo';
      $value = 'http://vimeo.com/' . $value;
    }
    // Video is a Flash video.
    elseif (substr($value, 0, 4) === "http") {
      $settings['video_type'] = 'Flash';
    }
    // Video is a YouTube video.
    else {
      $settings['handler'] = 'MediaInternetYouTubeHandler';
      $settings['video_type'] = 'Youtube';
      $value = 'https://www.youtube.com/watch?v=' . $value;
    }

    // Convert the Youtube URI into a local stream wrapper.
    if (class_exists($settings['handler'])) {
      $handler = new $settings['handler']($value);
      $destination = $handler->parse($value);
      $file = file_uri_to_object($destination, TRUE);
    }
    elseif (class_exists('MediaInternetOEmbedHandler')) {
      $handler = new MediaInternetOEmbedHandler($value);
      $file = $handler->getFileObject();
    }
    else {
      MigrationBase::displayMessage(t('Could not find a handler for @video_type videos', array('@video_type' => $settings['video_type'])));
      return FALSE;
    }

    // Create a file entity object for this Youtube reference, and see if we
    // can get the video title.
    if (empty($file->fid) && $info = $handler->getOEmbed()) {
      $file->filename = truncate_utf8($info['title'], 255);
    }
    $file = file_save($file);
    if (is_object($file)) {
      return $file;
    }
    else {
      return FALSE;
    }
  }
}
