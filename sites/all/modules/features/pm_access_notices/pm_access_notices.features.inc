<?php
/**
 * @file
 * pm_access_notices.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pm_access_notices_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
