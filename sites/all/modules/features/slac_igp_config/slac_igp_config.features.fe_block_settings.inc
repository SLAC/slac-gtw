<?php
/**
 * @file
 * slac_igp_config.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function slac_igp_config_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-weather_traffic'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'weather_traffic',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
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
        'region' => '',
        'status' => 0,
        'theme' => 'slac',
        'weight' => 18,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['panels_mini-new_weather_traffic'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'new_weather_traffic',
    'module' => 'panels_mini',
    'node_types' => array(),
    'pages' => '',
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
        'region' => '',
        'status' => 0,
        'theme' => 'slac',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['wunderground_weather-wunderground_weather_current_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'wunderground_weather_current_1',
    'module' => 'wunderground_weather',
    'node_types' => array(),
    'pages' => '',
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
        'region' => '',
        'status' => 0,
        'theme' => 'slac',
        'weight' => 0,
      ),
    ),
    'title' => 'Current Conditions',
    'visibility' => 0,
  );

  $export['wunderground_weather-wunderground_weather_forecast_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'wunderground_weather_forecast_1',
    'module' => 'wunderground_weather',
    'node_types' => array(),
    'pages' => '',
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
        'region' => '',
        'status' => 0,
        'theme' => 'slac',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
