<?php
/**
 * @file
 * slac_seo.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function slac_seo_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_blacklist_classes';
  $strongarm->value = 'customScripts
customPixels';
  $export['google_tag_blacklist_classes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_compact_snippet';
  $strongarm->value = 1;
  $export['google_tag_compact_snippet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_container_id';
  $strongarm->value = 'GTM-WVCZDCN';
  $export['google_tag_container_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_data_layer';
  $strongarm->value = 'dataLayer';
  $export['google_tag_data_layer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_debug_output';
  $strongarm->value = 0;
  $export['google_tag_debug_output'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_environment_id';
  $strongarm->value = '';
  $export['google_tag_environment_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_environment_token';
  $strongarm->value = '';
  $export['google_tag_environment_token'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_include_classes';
  $strongarm->value = 0;
  $export['google_tag_include_classes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_include_environment';
  $strongarm->value = 0;
  $export['google_tag_include_environment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_include_file';
  $strongarm->value = 1;
  $export['google_tag_include_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_path_list';
  $strongarm->value = 'admin*
batch*
node/add*
node/*/edit
node/*/delete
user/*/edit*
user/*/cancel*';
  $export['google_tag_path_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_path_toggle';
  $strongarm->value = 'exclude listed';
  $export['google_tag_path_toggle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_role_list';
  $strongarm->value = array(
    'anonymous user' => 0,
    'authenticated user' => 0,
    'site_member' => 0,
    'author' => 0,
    'editor' => 0,
    'manager' => 0,
    'administrator' => 0,
  );
  $export['google_tag_role_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_role_toggle';
  $strongarm->value = 'exclude listed';
  $export['google_tag_role_toggle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_status_list';
  $strongarm->value = '403 Forbidden
404 Not Found';
  $export['google_tag_status_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_status_toggle';
  $strongarm->value = 'exclude listed';
  $export['google_tag_status_toggle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_tag_whitelist_classes';
  $strongarm->value = 'google
nonGooglePixels
nonGoogleScripts
nonGoogleIframes';
  $export['google_tag_whitelist_classes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hotjar_settings';
  $strongarm->value = array(
    'hotjar_account' => '1423725',
    'hotjar_snippet_version' => '6',
    'hotjar_visibility_pages' => '0',
    'hotjar_pages' => 'admin
admin/*
batch
node/add*
node/*/*
user/*/*',
    'hotjar_visibility_roles' => '0',
    'hotjar_roles' => array(
      1 => 0,
      2 => 0,
      5 => 0,
      4 => 0,
      6 => 0,
      7 => 0,
      3 => 0,
    ),
  );
  $export['hotjar_settings'] = $strongarm;

  return $export;
}
