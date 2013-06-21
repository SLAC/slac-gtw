<?php
/**
 * @file
 * slac_igp_feed.box.inc
 */

/**
 * Implements hook_default_box().
 */
function slac_igp_feed_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'feedback';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'feedback';
  $box->options = array(
    'body' => array(
      'value' => '<a href="/feedback">Submit Site Feedback</a> ',
      'format' => 'full_html',
    ),
  );
  $export['feedback'] = $box;

  return $export;
}
