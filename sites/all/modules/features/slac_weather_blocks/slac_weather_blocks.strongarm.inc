<?php
/**
 * @file
 * slac_weather_blocks.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function slac_weather_blocks_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_api_key';
  $strongarm->value = '3d7d9cc54495a5da';
  $export['wunderground_weather_api_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_block_current_amount';
  $strongarm->value = '1';
  $export['wunderground_weather_block_current_amount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_block_forecast_amount';
  $strongarm->value = '1';
  $export['wunderground_weather_block_forecast_amount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_cache';
  $strongarm->value = 1;
  $export['wunderground_weather_cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_cache_expire';
  $strongarm->value = '86400';
  $export['wunderground_weather_cache_expire'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_current_1_fields';
  $strongarm->value = 'a:6:{s:10:"feels_like";a:2:{s:8:"#enabled";s:1:"0";s:7:"#weight";s:1:"0";}s:11:"temperature";a:2:{s:8:"#enabled";s:1:"1";s:7:"#weight";s:1:"1";}s:2:"uv";a:2:{s:8:"#enabled";s:1:"0";s:7:"#weight";s:1:"2";}s:10:"visibility";a:2:{s:8:"#enabled";s:1:"0";s:7:"#weight";s:1:"3";}s:7:"weather";a:2:{s:8:"#enabled";s:1:"0";s:7:"#weight";s:1:"4";}s:4:"wind";a:2:{s:8:"#enabled";s:1:"0";s:7:"#weight";s:1:"5";}}';
  $export['wunderground_weather_current_1_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_current_icons_1';
  $strongarm->value = 'k';
  $export['wunderground_weather_current_icons_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_degrees';
  $strongarm->value = 'fahrenheit';
  $export['wunderground_weather_degrees'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_distance';
  $strongarm->value = 'mi';
  $export['wunderground_weather_distance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_forecast_1_fields';
  $strongarm->value = 'a:5:{s:5:"image";a:2:{s:8:"#enabled";s:1:"1";s:7:"#weight";s:1:"0";}s:10:"conditions";a:2:{s:8:"#enabled";s:1:"0";s:7:"#weight";s:1:"1";}s:11:"temperature";a:2:{s:8:"#enabled";s:1:"1";s:7:"#weight";s:1:"2";}s:4:"rain";a:2:{s:8:"#enabled";s:1:"0";s:7:"#weight";s:1:"3";}s:4:"wind";a:2:{s:8:"#enabled";s:1:"0";s:7:"#weight";s:1:"4";}}';
  $export['wunderground_weather_forecast_1_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_forecast_date_format_1';
  $strongarm->value = 'calendar_item';
  $export['wunderground_weather_forecast_date_format_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_forecast_icons_1';
  $strongarm->value = 'k';
  $export['wunderground_weather_forecast_icons_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_language';
  $strongarm->value = 'EN';
  $export['wunderground_weather_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_location_current_1';
  $strongarm->value = 'Stanford, California [/q/zmw:94305.2.99999]';
  $export['wunderground_weather_location_current_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_location_forecast_1';
  $strongarm->value = 'Stanford, California [/q/zmw:94305.2.99999]';
  $export['wunderground_weather_location_forecast_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wunderground_weather_windspeed';
  $strongarm->value = 'mph';
  $export['wunderground_weather_windspeed'] = $strongarm;

  return $export;
}
