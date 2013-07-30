<?php
/**
 * @file
 * slac_igp_importers.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function slac_igp_importers_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'slac_news-blank_source_1-set_default_value';
  $feeds_tamper->importer = 'slac_news';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '0',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['slac_news-blank_source_1-set_default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'slac_news-blank_source_2-set_default_value';
  $feeds_tamper->importer = 'slac_news';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'Internal',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['slac_news-blank_source_2-set_default_value'] = $feeds_tamper;

  return $export;
}
