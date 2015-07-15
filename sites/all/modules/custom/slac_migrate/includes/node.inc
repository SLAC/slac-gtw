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



    // Image field mappings.
    $this->addFieldMapping('field_shared_image:file_class')
     ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_shared_image:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_shared_image:file_replace')
         ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    // Tags field mapping.
    $this->addFieldMapping('field_shared_tags', '7')
      ->sourceMigration('Tags');
    $this->addFieldMapping('field_shared_tags:source_type')
     ->defaultValue('tid');
    $this->addFieldMapping('field_shared_tags:create_term')
     ->defaultValue(TRUE);

    // Unmapped destination metatag fields.
    $this->addUnmigratedDestinations(array(
      'metatag_title', 'metatag_description', 'metatag_abstract', 'metatag_keywords', 'metatag_robots',
      'metatag_news_keywords', 'metatag_standout', 'metatag_generator', 'metatag_rights', 'metatag_image_src',
      'metatag_canonical', 'metatag_shortlink', 'metatag_publisher', 'metatag_author', 'metatag_original-source',
      'metatag_revisit-after', 'metatag_content-language',
    ));

    // Workbench moderation mappings
    $this->addFieldMapping('workbench_moderation_state_new', 'status')
      ->callbacks(array($this, 'getWorkbenchModerationStateForNodeStatus'))->defaultValue('published');
  }

  /**
   * Translates a node published status 1 or 0 into a Workbench moderation state
   * value string.
   *
   * @param $status
   * @return string
   */
  public function getWorkbenchModerationStateForNodeStatus($status) {
    return ($status == '1') ? 'published' : 'draft';
  }

   /**
   * Extend basic query to include node author's username so we can map to username
   * on D7 site.
   */
  protected function query() {

    // Get the default query so we can add to it.
    $query = parent::query();

    // Get the username of the node author.
    $query->LeftJoin('users', 'u', 'n.uid = u.uid');
    $query->fields('u', array('name'));

    return $query;
  }

  /*
   * Override the user id if it doesn't exist on the D7 site.
   */
  public function prepare($entity, $row) {
    $entity->revision = isset($entity->nid) ? FALSE : TRUE;

    // Check if user exists on D7 site.  If so, load the user by name and assign.
    // (Uids are not the same on both sites.)
    $d7_user = user_load_by_name($row->name);
    if (isset($d7_user->uid)) {
      $entity->uid = $d7_user->uid;
    }
    else {
      $entity->uid = 0;
    }
  }

  /*
   * Utility function to update image metadata.
   */
  public function update_image($row) {

    // Image references point to the image node that contain the image.
    // We need to point it to the actual fid of the image.
    // Then we need to grab all the image metadata and update the destination image file entity.
    if (isset($row->field_image)) {
      foreach ($row->field_image as $key => $image_fid) {

        // Update the image's metadata in the destination image file entity.
        // Seems strange to do it here but there was no way to grab the correct vid when doing
        // the bulk image import.
        if ($dest_image_id = $this->handleSourceMigration('Images', $image_fid)) {
          if ($dest_image = entity_load('file', array($dest_image_id))) {

            // Assign images new values and save.
            $dest_image[$dest_image_id]->field_file_image_alt_text[LANGUAGE_NONE][0]['value'] = substr($row->{"field_image:alt"}[$key], 0, 254);
            $dest_image[$dest_image_id]->field_file_image_title_text[LANGUAGE_NONE][0]['value'] = substr($row->{"field_image:title"}[$key], 0, 254);
            entity_save('file', $dest_image[$dest_image_id]);
          }
        }
      }
    }
  }

  /*
   * Utility function to convert html filter to D7 values.
   */
  public function convert_filter($row) {
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

  /*
   * Utility function to convert field_announcement_content field to D7 values.
   */
  public function convert_announcement($row) {
    if ($row->field_announcement_content == 'Link') {
      $row->field_announcement_content = 'Link to Existing URL';
    }
    elseif ($row->field_announcement_content == 'Body') {
      $row->field_announcement_content = 'Enter Details';
    }
  }

  /*
   * There appears to be an odd bug in the D6 site that causes dates to be incorrectly
   * stored in the database - 7 hours off.  This utility function corrects that.
   */
  public function correct_date($row) {

    $from_date = new DateTime($row->field_date);
    $from_date->sub(new DateInterval("PT7H"));
    $row->field_date = $from_date->format('Y-m-d H:i:s');

    $to_date = new DateTime($row->{'field_date:value2'});
    $to_date->sub(new DateInterval("PT7H"));
    $row->{'field_date:value2'} = $to_date->format('Y-m-d H:i:s');
  }

  /**
   * Converts D6 Tags of Lab News and SLAC Science to field_news_news_type selection.
   */
  public function convert_tag_to_news_type($entity, $row) {
    foreach ($row->{'7'} as $index => $tid) {
      if ($tid == '527') {
        $entity->field_news_news_type[LANGUAGE_NONE][0]['value'] = 'Lab News';
        unset($entity->field_shared_tags[LANGUAGE_NONE][$index]);
      }
      elseif ($tid == '528') {
        $entity->field_news_news_type[LANGUAGE_NONE][0]['value'] = 'SLAC Science';
        unset($entity->field_shared_tags[LANGUAGE_NONE][$index]);
      }
    }
  }

  public function complete($node, stdClass $row) {
    db_query("UPDATE {node_revision} SET status = 1 WHERE vid = :vid", array(':vid' => $node->vid));
  }
}


/**
 * Class SlacStoryMigration
 *
 * Migrates D6 Story nodes to D7 News nodes.
 */
class SlacStoryMigration extends SlacNodeMigration {

  public function __construct(array $arguments) {

    parent::__construct($arguments);

    // Field mappings.
    $this->addFieldMapping('field_news_subtitle', 'field_title_sub');
    $this->addFieldMapping('field_shared_byline', 'field_byline');
    $this->addFieldMapping('field_news_teaser', 'field_teaser');

    // Video field mappings.
    $this->addFieldMapping('field_shared_video', 'field_video_reference')
      ->sourceMigration('Videos');
    $this->addFieldMapping('field_shared_video:file_class')
     ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_shared_video:preserve_files')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_shared_video:file_replace')
         ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    $this->addFieldMapping('field_shared_image', 'field_image_reference')
      ->sourceMigration('Images');

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
      'field_shared_image:language', 'field_shared_image:alt', 'field_shared_image:title',
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
      'field_shared_tags:ignore_case',
      'field_shared_video:language', 'field_shared_video:description',
        'field_shared_video:display',
      'field_shared_promote_news',
    ));

    // Unmigrated source fields.
    $this->addUnmigratedSources(array('revision', 'log', 'revision_uid',
      'field_issue_reference', 'field_title_short', 'field_image', 'field_image:list', 'field_image:alt',
      'field_image:title', 'field_content_links', 'field_teaser:format',
      'field_media_coverage', 'field_audio_reference', 'field_story_type', 'uid', 'name',
      // Node counter fields:
      'daycount', 'timestamp', 'totalcount'));
  }


  /*
   * Alter D6 record.
   */
  public function prepareRow($row) {

    // Get the query from the parent so we can add to it.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Strip html tags from teaser.
    $row->field_teaser[0] = strip_tags($row->field_teaser[0]);

    // Image references point to the image node that contain the image.
    // We need to point it to the actual fid of the image.
    // Then we need to grab all the image metadata and update the destination image file entity.
    // This is similar to the update_image method in the parent class but different.
    if (isset($row->field_image_reference)) {
      foreach ($row->field_image_reference as $key => $image_node_nid) {

        // Grab the fields from the legacy database.
        $image_query = Database::getConnection('default', $this->sourceConnection)
          ->select('node', 'n')
          ->fields('n', array('nid', 'vid'))
          ->condition('n.nid', $image_node_nid, '=');
        $image_query->LeftJoin('node_revisions', 'nr', 'n.vid = nr.vid');
        $image_query->fields('nr', array('title', 'body', 'format'));
        $image_query->LeftJoin('content_field_image', 'cfi', 'n.vid = cfi.vid');
        $image_query->fields('cfi', array('field_image_fid', 'field_image_data'));
        $image_query->LeftJoin('content_type_image', 'cti', 'n.vid = cti.vid');
        $image_query->fields('cti', array('field_photo_credit_value'));
        $image = $image_query->execute()->fetchAssoc();

        // Set the image reference field to the fid instead of the image nid we originally had.
        $row->field_image_reference[$key] = $image['field_image_fid'];

        // Convert image format.
        if ($image['format'] == '2') {
          $image['format'] = 'full_html';
        }
        elseif ($image['format'] == '1') {
          $image['format'] = 'filtered_html';
        }
        else {
          $image['format'] = 'full_html';
        }

        // Update the image's metadata in the destination image file entity.
        // Seems strange to do it here but there was no way to grab the correct vid when doing
        // the bulk image import.
        if ($dest_image_id = $this->handleSourceMigration('Images', $image['field_image_fid'])) {
          if ($dest_image = entity_load('file', array($dest_image_id))) {

            // Alt and title fields were stored in serialized data field.
            $source_alt_title = unserialize($image['field_image_data']);

            // Assign images new values and save.
            $dest_image[$dest_image_id]->field_file_image_alt_text[LANGUAGE_NONE][0]['value'] = substr($source_alt_title['alt'], 0, 254);
            $dest_image[$dest_image_id]->field_file_image_title_text[LANGUAGE_NONE][0]['value'] = substr($source_alt_title['title'], 0, 254);
            $dest_image[$dest_image_id]->field_file_shared_caption[LANGUAGE_NONE][0]['value'] = $image['body'] . ' (' . $image['field_photo_credit_value'] . ')';
            $dest_image[$dest_image_id]->field_file_shared_caption[LANGUAGE_NONE][0]['format'] = $image['format'];
            $dest_image[$dest_image_id]->filename = $image['title'];
            entity_save('file', $dest_image[$dest_image_id]);
          }
        }
      }
    }
  }

  /**
   * Modify resulting entity.
   */
  public function prepare($entity, $row) {
    if (isset($row->{'7'})) {
      $this->convert_tag_to_news_type($entity, $row);
    }
  }
}

/**
 * Class SlacLabAnnouncementMigration
 *
 * Migrates D6 Announcement->Lab Announcement nodes to D7 News nodes.
 */
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

    // Related links mapping.
    $this->addFieldMapping('field_shared_related_links', 'field_announcement_links');
    $this->addFieldMapping('field_shared_related_links:title', 'field_announcement_links:title');
    $this->addFieldMapping('field_shared_related_links:attributes', 'field_announcement_links:attributes');

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
      'field_shared_tags:ignore_case',
      'field_shared_video', 'field_shared_video:file_class', 'field_shared_video:language',
        'field_shared_video:preserve_files', 'field_shared_video:destination_dir',
        'field_shared_video:destination_file', 'field_shared_video:file_replace', 'field_shared_video:source_dir',
        'field_shared_video:urlencode', 'field_shared_video:description', 'field_shared_video:display',
      'field_shared_promote_news',

    ));

    // Unmigrated source fields.
    $this->addUnmigratedSources(array('body', 'format', 'uid', 'revision', 'log', 'revision_uid', 'field_pre_announce',
      'field_publish_dates', 'field_publish_dates:value2', 'field_image:list', 'field_image:alt', 'field_image:title',
      'field_event_series', 'field_event_science_area', 'field_event_org', '19', '20', 'name', 'field_date',
      'field_date:value2',
      // Node counter fields:
      'daycount', 'timestamp', 'totalcount'));
  }

   /*
   * Filter to Announcement node type with Announcement type of "Lab Announcement".
   */
  protected function query() {

    // Get the default query (all rows in the users table other than uid 1)
    $query = parent::query();

    // Filter by announcement type of Lab Announcement.
    $query->condition('f.field_announcement_type_value', 'Lab Announcement', '=');

    return $query;
  }

  /*
   * Adjust $row data for D7 equivalent.
   */
  public function prepareRow($row) {

    // Get the query from the parent so we can add to it.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Convert filter to D7 values.
    $this->convert_filter($row);

    // Update field_announcement_content with D7 equivalent.
    $this->convert_announcement($row);

    // Update image metadata.
    $this->update_image($row);
  }

  /**
   * Modify resulting entity.
   */
  public function prepare($entity, $row) {
    if (isset($row->{'7'})) {
      $this->convert_tag_to_news_type($entity, $row);
    }
  }
}

/**
 * Class SlacCalendarsMigration
 *
 * Migrates D6 Announcement->Staff and Scientific Calendar nodes to D7 Event nodes.
 */
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

    // Related links mappings.
    $this->addFieldMapping('field_shared_related_links', 'field_announcement_links');
    $this->addFieldMapping('field_shared_related_links:title', 'field_announcement_links:title');
    $this->addFieldMapping('field_shared_related_links:attributes', 'field_announcement_links:attributes');

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
      'field_shared_tags:ignore_case',
      'field_event_type', 'field_event_type:source_type', 'field_event_type:create_term',
        'field_event_type:ignore_case',
      'field_event_series',
      'field_news_news_type',
      'field_shared_news_title',
      'field_shared_news_title:language',

    ));

    // Unmigrated source fields.
    $this->addUnmigratedSources(array('body', 'format', 'uid', 'revision', 'log', 'revision_uid', 'field_pre_announce',
      'field_publish_dates', 'field_publish_dates:value2', 'field_image:list', 'field_image:alt', 'field_image:title',
      'field_event_science_area', 'field_event_org', '19', '20', 'name', 't_name', 'field_event_series',
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

  /*
   * Convert D6 data to D7 values.
   */
  public function prepareRow($row) {

    // Get the query from the parent so we can add to it.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Update field_announcement_content with D7 equivalent.
    $this->convert_announcement($row);

    // Convert filter to D7 values.
    $this->convert_filter($row);

    // Correct D6 date/time. They were 7 hours off in database.
    $this->correct_date($row);

    // Update image metadata.
    $this->update_image($row);
  }

  /*
   * Adjust data for d7.
   */
  public function prepare($entity, $row) {

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

/**
 * Class SlacAccessNoticeMigration
 *
 * Migrates D6 Announcement->Access Notice nodes to D7 Access Information Nodes.
 */
class SlacAccessNoticeMigration extends SlacNodeMigration {

  public function __construct(array $arguments) {

    parent::__construct($arguments);

    $this->addFieldMapping(NULL, 'field_announcement_type');

    // Miscellaneous field mappings.
    $this->addFieldMapping('field_shared_location', 'field_announcement_loc');
    $this->addFieldMapping('field_event_date', 'field_date');
    $this->addFieldMapping('field_event_date:to', 'field_date:value2');
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

    // Related links mappings.
    $this->addFieldMapping('field_shared_related_links', 'field_announcement_links');
    $this->addFieldMapping('field_shared_related_links:title', 'field_announcement_links:title');
    $this->addFieldMapping('field_shared_related_links:attributes', 'field_announcement_links:attributes');

    // Unmapped destination fields. Indented for grouping subfields.
    $this->addUnmigratedDestinations(array(
      'field_event_date:timezone', 'field_event_date:rrule',
      'field_shared_byline', 'field_shared_byline:language',
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
      'field_shared_tags:ignore_case',
      'field_access_start_publishing',
      'field_news_news_type',
      'field_shared_news_title', 'field_shared_news_title:language',
    ));

    // Unmigrated source fields.
    $this->addUnmigratedSources(array('body', 'format', 'uid', 'revision', 'log', 'revision_uid', 'field_pre_announce',
      'field_byline', 'field_image:list', 'field_image:alt', 'field_image:title', 'field_publish_dates', 'field_publish_dates:value2',
      'field_event_series', 'field_event_science_area', 'field_event_org', '19', '20', 'name',
      // Node counter fields:
      'daycount', 'timestamp', 'totalcount'));
  }

   /*
   * Extend basic query to include node author's username so we can map to username
   * on D7 site.
   */
  protected function query() {

    // Get the default query (all rows in the users table other than uid 1)
    $query = parent::query();

    // Filter by announcement type of Lab Announcement.
    $query->condition('f.field_announcement_type_value', 'Access Notice', '=');

    return $query;
  }

  /*
   * Convert data to D7 values.
   */
  public function prepareRow($row) {

    // Get the query from the parent so we can add to it.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Update field_announcement_content with D7 equivalent.
    $this->convert_announcement($row);

    // Convert filter to D7 values.
    $this->convert_filter($row);

    // Correct D6 date/time. They were 7 hours off in database.
    $this->correct_date($row);

    // Update image metadata.
    $this->update_image($row);
  }
}




class SlacNewsArticleMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    parent::__construct($arguments);

    $this->addFieldMapping('field_news_news_type', 'field_news_type');
    $this->addFieldMapping('field_shared_existing_url', 'field_link');
    $this->addFieldMapping('field_shared_tags', 'field_slac_migrate_tag_store');
    $this->addFieldMapping('field_shared_tags:source_type')
     ->defaultValue('tid');
    $this->addFieldMapping('field_shared_tags:create_term')
     ->defaultValue(TRUE);
    $this->addFieldMapping('field_shared_image', 'field_news_image');
    $this->addFieldMapping('field_shared_image:preserve_files')
      ->defaultValue(TRUE);

    // Workbench moderation mappings
    $this->addFieldMapping('workbench_moderation_state_new', 'status')
      ->callbacks(array($this, 'getWorkbenchModerationStateForArticleNodeStatus'))->defaultValue('published');
  }

  /**
   * Translates a node published status 1 or 0 into a Workbench moderation state
   * value string.
   *
   * @param $status
   * @return string
   */
  public function getWorkbenchModerationStateForArticleNodeStatus($status) {
    return ($status == '1') ? 'published' : 'draft';
  }

  /*
   * Convert values for News nodes.
   */
  function prepareRow($row) {

     // Get the query from the parent so we can add to it.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Grab the tag terms from the temporary tag store field added on install.
    // Look up the term in the tags vocab.
    if (!empty($row->field_slac_migrate_tag_store)) {
      $tags = explode(',', $row->field_slac_migrate_tag_store[0]);
      $tids = array();
      foreach ($tags as $tag) {
        $term = taxonomy_get_term_by_name($tag, 'tags');
        if (empty($term)) {
          $vob = taxonomy_vocabulary_machine_name_load('tags');
          $new_term = new stdClass();
          $new_term->name = $tag;
          $new_term->vid = $vob->vid;
          taxonomy_term_save($new_term);
          $term[$new_term->tid] = $new_term;
        }
        foreach ($term as $tid => $object) {
          $tids[] = $tid;
        }
      }
      $row->field_slac_migrate_tag_store = $tids;
    }

    if ($row->field_news_type[0] == 'internal') {
      $row->field_news_type[0] = 'Lab News';
    }
    elseif ($row->field_news_type[0] == 'external') {
      $row->field_news_type[0] = 'SLAC Science';
    }
  }

  /*
   * Typically a migration includes migrations for users and images.  We don't need them since we're
   * just changing node types.  So we map user and image metadata here.
   */
  function prepare($entity, $row) {

    // There's no user migration as expected by migrate so manually mapping uids.
    $entity->uid = $row->uid;
    $entity->revision = isset($entity->nid) ? FALSE : TRUE;

    // There is also no image migration needed so we map the fid and then transfer alt and title texts
    // to the image file entity.
    if (isset($row->field_news_image)) {
      $fid = $row->field_news_image[0];

      $entity->field_shared_image[LANGUAGE_NONE][0]['fid'] = $fid;

      // Update the alt and title of the image fid only if they're empty on the image entity.
      if (!empty($row->{'field_news_image:alt'}[0]) || !empty($row->{'field_news_image:title'}[0])) {

        // Only go through the update if the file entity loads.
        if ($dest_image = entity_load('file', array($row->field_news_image[0]))) {

          // If the image entity's alt text is empty and the attached image's alt test is not empty,
          // the update the image entity alt text.
          // We use db_merge because entity_save fails if the image file isn't present on the server
          // which is a problem for testing.
          if (empty($dest_image[$fid]->field_file_image_alt_text[LANGUAGE_NONE][0]['value']) &&
              !empty($row->{'field_news_image:alt'}[0])) {
            $this->image_update('alt', $fid, substr($row->{'field_news_image:alt'}[0], 0, 254));
          }

          // If the image entity's title text is empty and the attached image's title test is not empty,
          // the update the image entity title text.
          if (empty($dest_image[$fid]->field_file_image_title_text[LANGUAGE_NONE][0]['value']) &&
              !empty($row->{'field_news_image:title'}[0])) {
            $this->image_update('title', $fid, substr($row->{'field_news_image:title'}[0], 0, 254));
          }
        }
      }
    }
  }

  /**
   * A utility function used to update an image's alt or title attribute.
   *
   * @param $type
   *   The type of image attribute to update. 'alt' or 'title' expected.
   *
   * @param $fid
   *   The fid of the image to update.
   *
   * @param $value
   *   The value to set the alt or title attribute to.
   */
  protected function image_update($type, $fid, $value) {

    // Set the table name.
    $table = $type == 'alt' ? 'field_data_field_file_image_alt_text' : 'field_data_field_file_image_title_text';

    // Set the column name.
    $column = $type == 'alt' ? 'field_file_image_alt_text_value' : 'field_file_image_title_text_value';

    // If a record already exists for the image, update it.  If not create a new record.
    db_merge($table)
      ->key(array('entity_id' => $fid))
      ->fields(array(
        'entity_type' => 'file',
        'bundle' => 'image',
        'revision_id' => $fid,
        'language' => 'und',
        $column => $value,
        'delta' => 0,
      ))
      ->execute();
  }
}
