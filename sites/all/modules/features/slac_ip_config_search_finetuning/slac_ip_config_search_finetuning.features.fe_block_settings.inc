<?php
/**
 * @file
 * slac_ip_config_search_finetuning.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function slac_ip_config_search_finetuning_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['slac_search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'slac_search',
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
        'region' => 'dashboard_inactive',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'slac' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'slac',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
