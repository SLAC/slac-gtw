<?php
/**
 * @file
 * pm_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pm_calendar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
