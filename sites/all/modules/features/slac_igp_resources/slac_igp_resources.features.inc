<?php
/**
 * @file
 * slac_igp_resources.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_igp_resources_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function slac_igp_resources_views_api() {
  return array("api" => "3.0");
}
