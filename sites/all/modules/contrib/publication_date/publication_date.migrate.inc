<?php

/**
 * @file
 * Support for the migrate module.
 */

/**
 * Field handler.
 */
class MigratePublicationDateHandler extends MigrateDestinationHandler {
  public function __construct() {
    $this->registerTypes(array('node'));
  }

  /**
   * Make the destination field visible.
   */
  public function fields() {
      return array(
        'published_at' =>
          t('publication date'),
      );
  }

  public function prepare($entity, stdClass $row) {
    if (isset($entity->published_at)) {
      $entity->published_at = strtotime($entity->published_at);
    }
  }
}
