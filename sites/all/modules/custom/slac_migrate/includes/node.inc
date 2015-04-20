<?php

/**
 * @file
 * SLAC Today node migration classes.
 */

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
    $this->addFieldMapping('field_shared_video:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_shared_video:file_replace')
         ->defaultValue(FILE_EXISTS_REUSE);

    $this->addFieldMapping('field_shared_image', 'field_image_reference')
      ->sourceMigration('Images');
    $this->addFieldMapping('field_shared_image:file_class')
     ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_shared_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_shared_image:file_replace')
         ->defaultValue(FILE_EXISTS_REUSE);

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

  public function prepareRow($row) {

    // Get the query from the parent so we can add to it.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Image references point to the image node that contain the image.
    // We need to point it to the actual fid of the image.
    if (isset($row->field_image_reference)) {
      foreach ($row->field_image_reference as $key => $image_node_nid) {

        $image_query = Database::getConnection('default', $this->sourceConnection)
          ->select('node', 'n')
          ->fields('n', array('nid', 'vid'))
          ->condition('n.nid', $image_node_nid, '=');
        $image_query->LeftJoin('content_field_image', 'cfi', 'n.vid = cfi.vid');
        $image_query->fields('cfi', array('field_image_fid'));

        $image = $image_query->execute()->fetchAssoc();

        $row->field_image_reference[$key] = $image['field_image_fid'];
      }
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

}


class SlacLabAnnouncementMigration extends SlacNodeMigration {

  public function __construct(array $arguments) {

    parent::__construct($arguments);

    // Field mappings.
    $this->addFieldMapping(NULL, 'field_announcement_type');
    $this->addFieldMapping('field_shared_location', 'field_announcement_loc');
    $this->addFieldMapping('field_news_desired_publish_date', 'field_publish_dates');
    $this->addFieldMapping('field_shared_byline', 'field_byline');
    $this->addFieldMapping('field_shared_new_existing', 'field_announcement_content');
    $this->addFieldMapping('field_shared_existing_url', 'field_announcement_redirect');
    $this->addFieldMapping('field_shared_note_editors', 'field_announcement_note');

    // The default body field mappings need to be removed first so we can
    // map to different fields.
    $this->removeFieldMapping('body');
    $this->removeFieldMapping('body:format');
    $this->addFieldMapping('body', 'field_announcement_body');
    $this->addFieldMapping('body:format', 'field_announcement_body:format');

    // Image field mapping.
    $this->addFieldMapping('field_shared_image', 'field_image')
        ->sourceMigration('Images');
    $this->addFieldMapping('field_shared_image:file_class')
        ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_shared_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_shared_image:file_replace')
         ->defaultValue(FILE_EXISTS_REUSE);

    // Related links mapping.
    $this->addFieldMapping('field_shared_related_links', 'field_announcement_links');
    $this->addFieldMapping('field_shared_related_links:title', 'field_announcement_links:title');
    $this->addFieldMapping('field_shared_related_links:attributes', 'field_announcement_links:attributes');

    // Tags field mapping.
    $this->addFieldMapping('field_shared_tags', '7')
      ->sourceMigration('Tags');
    $this->addFieldMapping('field_shared_tags:source_type')
     ->defaultValue('tid');

    // Unmapped destination fields. Indented for grouping subfields.
    $this->addUnmigratedDestinations(array(
      'field_news_desired_publish_date:timezone',
        'field_news_desired_publish_date:rrule', 'field_news_desired_publish_date:to',
      'field_news_news_type',
      'field_news_subtitle', 'field_news_subtitle:language',
      'field_news_teaser', 'field_news_teaser:language',
      'field_shared_byline:language',
      'field_shared_contact_email',
      'field_shared_contact_name', 'field_shared_contact_name:language',
      'field_shared_contact_phone',
      'field_shared_existing_url:language',
      'field_shared_image:language',
      'field_shared_image:alt',
      'field_shared_image:title',
      'field_shared_location:language',
      'field_shared_note_editors:language',
      'field_shared_related_files', 'field_shared_related_files:file_class', 'field_shared_related_files:language',
        'field_shared_related_files:preserve_files', 'field_shared_related_files:destination_dir',
        'field_shared_related_files:destination_file', 'field_shared_related_files:file_replace',
        'field_shared_related_files:source_dir', 'field_shared_related_files:urlencode',
        'field_shared_related_files:description', 'field_shared_related_files:display',
      'field_shared_related_links:language',
      'field_shared_tags:create_term', 'field_shared_tags:ignore_case',
      'field_shared_video', 'field_shared_video:file_class', 'field_shared_video:language',
        'field_shared_video:preserve_files', 'field_shared_video:destination_dir',
        'field_shared_video:destination_file', 'field_shared_video:file_replace', 'field_shared_video:source_dir',
        'field_shared_video:urlencode', 'field_shared_video:description', 'field_shared_video:display',

    ));

    // Unmapped destination metatag fields.
    $this->addUnmigratedDestinations(array(
      'metatag_title', 'metatag_description', 'metatag_abstract', 'metatag_keywords', 'metatag_robots',
      'metatag_news_keywords', 'metatag_standout', 'metatag_generator', 'metatag_rights', 'metatag_image_src',
      'metatag_canonical', 'metatag_shortlink', 'metatag_publisher', 'metatag_author', 'metatag_original-source',
      'metatag_revisit-after', 'metatag_content-language',
    ));

    // Unmigrated source fields.
    $this->addUnmigratedSources(array('body', 'format', 'uid', 'revision', 'log', 'revision_uid', 'field_pre_announce',
      'field_publish_dates', 'field_publish_dates:value2', 'field_image:list', 'field_image:alt', 'field_image:title',
      'field_event_series', 'field_event_science_area', 'field_event_org', '19', '20', 'name', 'field_date',
      'field_date:value2',
      // Node counter fields:
      'daycount', 'timestamp', 'totalcount'));
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

    // // Filter by announcement type of Lab Announcement.
    $query->condition('f.field_announcement_type_value', 'Lab Announcement', '=');
    return $query;
  }

  public function prepareRow($row) {

    // Get the query from the parent so we can add to it.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if ($row->field_announcement_content == 'Link') {
      $row->field_announcement_content = 'Link to Existing URL';
    }
    elseif ($row->field_announcement_content == 'Body') {
      $row->field_announcement_content = 'Enter Details';
    }

    // Convert filter formats.
    if ($row->{'field_announcement_body:format'} == '2') {
      $row->{'field_announcement_body:format'} = 'full_html';
    }
    elseif ($row->{'field_announcement_body:format'} == '1') {
      $row->{'field_announcement_body:format'} = 'filtered_html';
    }
    else {
      $row->{'field_announcement_body:format'} = 'full_html';
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
}


class SlacCalendarsMigration extends SlacNodeMigration {

  public function __construct(array $arguments) {

    parent::__construct($arguments);

    $this->addFieldMapping(NULL, 'field_announcement_type');

    // Miscellaneous field mappings.
    $this->addFieldMapping('field_shared_location', 'field_announcement_loc');
    $this->addFieldMapping('field_event_date', 'field_date');
    $this->addFieldMapping('field_event_date:to', 'field_date:value2');
    $this->addFieldMapping('field_shared_byline', 'field_byline');
    $this->addFieldMapping('field_shared_new_existing', 'field_announcement_content');
    $this->addFieldMapping('field_shared_existing_url', 'field_announcement_redirect');
    $this->addFieldMapping('field_shared_note_editors', 'field_announcement_note');

    // The default body field mappings need to be removed first so we can
    // map to different fields.
    $this->removeFieldMapping('body');
    $this->removeFieldMapping('body:format');
    $this->addFieldMapping('body', 'field_announcement_body');
    $this->addFieldMapping('body:format', 'field_announcement_body:format');

    // Image mappings.
    $this->addFieldMapping('field_shared_image', 'field_image')
        ->sourceMigration('Images');
    $this->addFieldMapping('field_shared_image:file_class')
        ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_shared_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_shared_image:file_replace')
         ->defaultValue(FILE_EXISTS_REUSE);

    // Related links mappings.
    $this->addFieldMapping('field_shared_related_links', 'field_announcement_links');
    $this->addFieldMapping('field_shared_related_links:title', 'field_announcement_links:title');
    $this->addFieldMapping('field_shared_related_links:attributes', 'field_announcement_links:attributes');

    // Tags mappings.
    $this->addFieldMapping('field_shared_tags', '7')
      ->sourceMigration('Tags');
    $this->addFieldMapping('field_shared_tags:source_type')
     ->defaultValue('tid');

    // Unmapped destination fields. Indented for grouping subfields.
    $this->addUnmigratedDestinations(array(
      'field_event_date:timezone', 'field_event_date:rrule',
      'field_event_series:source_type', 'field_event_series:create_term', 'field_event_series:ignore_case',
      'field_shared_byline:language',
      'field_shared_contact_email',
      'field_shared_contact_name', 'field_shared_contact_name:language',
      'field_shared_contact_phone',
      'field_shared_existing_url:language',
      'field_shared_image:language', 'field_shared_image:alt', 'field_shared_image:title',
      'field_shared_location:language',
      'field_shared_note_editors:language',
      'field_shared_promote_news',
      'field_shared_related_files', 'field_shared_related_files:file_class', 'field_shared_related_files:language',
        'field_shared_related_files:preserve_files', 'field_shared_related_files:destination_dir',
        'field_shared_related_files:destination_file', 'field_shared_related_files:file_replace',
        'field_shared_related_files:source_dir', 'field_shared_related_files:urlencode',
        'field_shared_related_files:description', 'field_shared_related_files:display',
      'field_shared_related_links:language',
      'field_shared_tags:create_term', 'field_shared_tags:ignore_case',
      'field_event_type', 'field_event_type:source_type', 'field_event_type:create_term',
        'field_event_type:ignore_case',
    ));

    // Unmapped destination metatag fields.
    $this->addUnmigratedDestinations(array(
      'metatag_title', 'metatag_description', 'metatag_abstract', 'metatag_keywords', 'metatag_robots',
      'metatag_news_keywords', 'metatag_standout', 'metatag_generator', 'metatag_rights', 'metatag_image_src',
      'metatag_canonical', 'metatag_shortlink', 'metatag_publisher', 'metatag_author', 'metatag_original-source',
      'metatag_revisit-after', 'metatag_content-language',
    ));

    // Unmigrated source fields.
    $this->addUnmigratedSources(array('body', 'format', 'uid', 'revision', 'log', 'revision_uid', 'field_pre_announce',
      'field_publish_dates', 'field_publish_dates:value2', 'field_image:list', 'field_image:alt', 'field_image:title',
      'field_event_science_area', 'field_event_org', '19', '20', 'name', 't_name',
      // Node counter fields:
      'daycount', 'timestamp', 'totalcount'));
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

    // Get event series field term.
    $query->LeftJoin('term_data', 't', 'f.field_event_series_value = t.tid');
    $query->fields('t', array('name'));

    // Filter by announcement type of Scientific Calendar and Staff Calendar.
    $or = db_or();
    $or->condition('f.field_announcement_type_value', 'Staff Calendar', '=');
    $or->condition('f.field_announcement_type_value', 'Scientific Calendar', '=');
    $query->condition($or);

    return $query;
  }

  public function prepareRow($row) {

    // Get the query from the parent so we can add to it.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if ($row->field_announcement_content == 'Link') {
      $row->field_announcement_content = 'Link to Existing URL';
    }
    elseif ($row->field_announcement_content == 'Body') {
      $row->field_announcement_content = 'Enter Details';
    }

    // Convert filter formats.
    if ($row->{'field_announcement_body:format'} == '2') {
      $row->{'field_announcement_body:format'} = 'full_html';
    }
    elseif ($row->{'field_announcement_body:format'} == '1') {
      $row->{'field_announcement_body:format'} = 'filtered_html';
    }
    else {
      $row->{'field_announcement_body:format'} = 'full_html';
    }

    // There appears to be an odd bug in the D6 site that causes dates to incorrectly
    // stored in the database - 7 hours off.
    $from_date = new DateTime($row->field_date);
    $from_date->sub(new DateInterval("PT7H"));
    $row->field_date = $from_date->format('Y-m-d H:i:s');

    $to_date = new DateTime($row->{'field_date:value2'});
    $to_date->sub(new DateInterval("PT7H"));
    $row->{'field_date:value2'} = $to_date->format('Y-m-d H:i:s');
  }

  public function prepare($entity, $row) {

    // Check if user exists on D7 site.  If so, load the user by name and assign.
    // (Uids are not the same on both sites.)
    $d7_user = user_load_by_name($row->name);
    if (isset($d7_user->uid)) {
      $entity->uid = $d7_user->uid;
    }

    // Convert Event Series taxonomy terms from D6 to corresponding term on D7.
    // Terms were not done via migration so no existing mapping to use for conversion.
    // There's an issue with one of the terms because it has a single quote in it.
    // Mapping this one manually.  htmlspecialchars with ENT_QUOTE wasn't working. :(
    // May come back and troubleshoot if time allows but this works for now.
    if ($row->field_event_series == 443) {
      $entity->field_event_series[LANGUAGE_NONE][0] = array('tid' => '2556');
    }
    else {
      $terms = taxonomy_get_term_by_name($row->t_name, 'event_series');
      foreach ($terms as $tid => $term) {
        $entity->field_event_series[LANGUAGE_NONE][0] = array('tid' => (string)$tid);
      }
    }
  }
}
