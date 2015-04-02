<?php
/**
 * @file
 * slac_ip_config_moderation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_ip_config_moderation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
