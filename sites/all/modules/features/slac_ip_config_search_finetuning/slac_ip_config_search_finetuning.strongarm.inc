<?php
/**
 * @file
 * slac_ip_config_search_finetuning.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function slac_ip_config_search_finetuning_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_search_index';
  $strongarm->value = 1;
  $export['webform_search_index'] = $strongarm;

  return $export;
}
