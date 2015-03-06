<?php
/**
 * @file
 * slac_igp_resources.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_igp_resources_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function slac_igp_resources_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
