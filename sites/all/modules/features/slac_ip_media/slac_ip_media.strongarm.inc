<?php
/**
 * @file
 * slac_ip_media.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function slac_ip_media_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_original_image';
  $strongarm->value = 1;
  $export['colorbox_original_image'] = $strongarm;

  return $export;
}
