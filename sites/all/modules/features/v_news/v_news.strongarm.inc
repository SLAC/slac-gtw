<?php
/**
 * @file
 * v_news.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function v_news_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_subqueue_expiration_featured_news_4';
  $strongarm->value = array(
    'date' => '2',
    'exclude' => '5',
  );
  $export['nodequeue_subqueue_expiration_featured_news_4'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_subqueue_expiration_lab_news_5';
  $strongarm->value = array(
    'date' => '1',
    'exclude' => '5',
  );
  $export['nodequeue_subqueue_expiration_lab_news_5'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_subqueue_expiration_slac_science_news_6';
  $strongarm->value = array(
    'date' => '1',
    'exclude' => '4',
  );
  $export['nodequeue_subqueue_expiration_slac_science_news_6'] = $strongarm;

  return $export;
}
