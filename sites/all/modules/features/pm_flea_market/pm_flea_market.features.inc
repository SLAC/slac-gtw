<?php
/**
 * @file
 * pm_flea_market.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pm_flea_market_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
