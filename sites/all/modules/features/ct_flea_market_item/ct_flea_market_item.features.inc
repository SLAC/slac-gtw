<?php
/**
 * @file
 * ct_flea_market_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_flea_market_item_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function ct_flea_market_item_flag_default_flags() {
  $flags = array();
  // Exported flag: "Flea Market - Inappropriate".
  $flags['flea_market_inappropriate'] = array(
    'entity_type' => 'node',
    'title' => 'Flea Market - Inappropriate',
    'global' => 0,
    'types' => array(
      0 => 'flea_market_post',
    ),
    'flag_short' => 'Report as inappropriate',
    'flag_long' => 'Report as inappropriate',
    'flag_message' => '',
    'unflag_short' => 'Reported as inappropriate',
    'unflag_long' => 'Reported as inappropriate',
    'unflag_message' => '',
    'unflag_denied_text' => 'Reported as inappropriate',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'ical' => 0,
      'diff_standard' => 0,
      'link' => 0,
      'headline' => 0,
      'news_archive' => 0,
      'access_listing' => 0,
      'slac_term_listing' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ct_flea_market_item',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function ct_flea_market_item_node_info() {
  $items = array(
    'flea_market_post' => array(
      'name' => t('Flea Market Item'),
      'base' => 'node_content',
      'description' => t('An item posting for the Flea market feature.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
