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
    $this->addFieldMapping('field_shared_tags', '7')
      ->sourceMigration('Tags');
    $this->addFieldMapping('field_shared_tags:source_type')
     ->defaultValue('tid');
    $this->addFieldMapping('field_shared_video', 'field_video_reference')
      ->sourceMigration('Videos');
    $this->addFieldMapping('field_shared_video:file_class')
     ->defaultValue('MigrateFileFid');
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
  }
}