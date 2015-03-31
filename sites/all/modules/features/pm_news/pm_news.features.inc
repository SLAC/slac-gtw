<?php
/**
 * @file
 * pm_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pm_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
