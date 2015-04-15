<?php

/**
 * Common mappings for the D6 node migrations.
 */
abstract class SlacNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

  }
}

class SlacStoryMigration extends SlacNodeMigration {

  public function __construct(array $arguments) {

    parent::__construct($arguments);

    // Field mappings.
    $this->addFieldMapping('field_news_subtitle', 'field_title_sub');
    $this->addFieldMapping('field_shared_byline', 'field_byline');
    $this->addFieldMapping('field_news_teaser', 'field_teaser');
    //$this->addFieldMapping('field_news_teaser:format', 'field_teaser:format');
    $this->addFieldMapping('field_shared_tags', '7')
      ->sourceMigration('Tags');
    $this->addFieldMapping('field_shared_tags:source_type')
     ->defaultValue('tid');
    $this->addFieldMapping('field_shared_video', 'field_video_reference')
      ->sourceMigration('Videos');
    $this->addFieldMapping('field_shared_video:file_class')
     ->defaultValue('MigrateFileFid');

    // Unmapped destination fields. Indented for grouping subfields.
    $this->addUnmigratedDestinations(array(
      'field_news_desired_publish_date', 'field_news_desired_publish_date:timezone',
        'field_news_desired_publish_date:rrule', 'field_news_desired_publish_date:to',
      'field_news_news_type',
      'field_news_subtitle:language',
      'field_news_teaser:language',
      'field_shared_byline:language',
      'field_shared_contact_email',
      'field_shared_contact_name',
      'field_shared_contact_name:language',
      'field_shared_contact_phone',
      'field_shared_existing_url', 'field_shared_existing_url:language',
      'field_shared_image:language', 'field_shared_image:preserve_files',
      'field_shared_location', 'field_shared_location:language',
      'field_shared_new_existing',
      'field_shared_note_editors', 'field_shared_note_editors:language',
      'field_shared_related_files', 'field_shared_related_files:file_class', 'field_shared_related_files:language',
        'field_shared_related_files:preserve_files', 'field_shared_related_files:destination_dir',
        'field_shared_related_files:destination_file', 'field_shared_related_files:file_replace',
        'field_shared_related_files:source_dir', 'field_shared_related_files:urlencode',
        'field_shared_related_files:description', 'field_shared_related_files:display',
      'field_shared_related_links', 'field_shared_related_links:title', 'field_shared_related_links:attributes',
        'field_shared_related_links:language',
      'field_shared_tags:create_term', 'field_shared_tags:ignore_case',
      'field_shared_video:language', 'field_shared_video:preserve_files', 'field_shared_video:description',
        'field_shared_video:display',
    ));

    // Unmapped destination metatag fields.
    $this->addUnmigratedDestinations(array(
      'metatag_title', 'metatag_description', 'metatag_abstract', 'metatag_keywords', 'metatag_robots',
      'metatag_news_keywords', 'metatag_standout', 'metatag_generator', 'metatag_rights', 'metatag_image_src',
      'metatag_canonical', 'metatag_shortlink', 'metatag_publisher', 'metatag_author', 'metatag_original-source',
      'metatag_revisit-after', 'metatag_content-language',
    ));

    // Unmigrated source fields.
    $this->addUnmigratedSources(array('revision', 'log', 'revision_uid',
      'field_issue_reference', 'field_title_short', 'field_image', 'field_content_links',
      'field_media_coverage', 'field_audio_reference', 'field_story_type', 'uid', 'name',
      // Node counter fields:
      'daycount', 'timestamp', 'totalcount'));
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
  }

  public function prepare($entity, $row) {

    // Check if user exists on D7 site.  If so, load the user by name and assign.
    // (Uids are not the same on both sites.)
    $d7_user = user_load_by_name($row->name);
    if (isset($d7_user->uid)) {
      $entity->uid = $d7_user->uid;
    }
  }


  /**
   * Extend basic query to include node author's username so we can map to username
   * on D7 site.
   */
  protected function query() {

    // Get the default query (all rows in the users table other than uid 1)
    $query = parent::query();

    // Get the username of the node author.
    $query->LeftJoin('users', 'u', 'n.uid = u.uid');
    $query->fields('u', array('name'));

    return $query;
  }
}
