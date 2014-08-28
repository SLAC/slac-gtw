<?php
/**
 * @file
 * slac_mail_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function slac_mail_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_mail';
  $strongarm->value = 'communications@slac.stanford.edu';
  $export['site_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_mail_name';
  $strongarm->value = 'SLAC Office of Communications';
  $export['site_mail_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'slac_igp_from_name';
  $strongarm->value = 'SLAC Office of Communications';
  $export['slac_igp_from_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'slac_igp_mail';
  $strongarm->value = 'communications@slac.stanford.edu';
  $export['slac_igp_mail'] = $strongarm;

  return $export;
}
