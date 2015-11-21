<?php
/**
 * @file
 * slac_ip_config_search_finetuning.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_ip_config_search_finetuning_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
