<?php
/**
 * @file
 * v_calendar.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function v_calendar_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-calendar_legend'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'calendar_legend',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'calendar*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'garland' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'garland',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'slac' => array(
        'region' => 'content_bottom',
        'status' => 1,
        'theme' => 'slac',
        'weight' => 0,
      ),
    ),
    'title' => 'Event Type Legend',
    'visibility' => 1,
  );

  return $export;
}
