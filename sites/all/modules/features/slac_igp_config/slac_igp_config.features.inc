<?php
/**
 * @file
 * slac_igp_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_igp_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function slac_igp_config_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function slac_igp_config_node_info() {
  $items = array(
    'access_information' => array(
      'name' => t('Access Information'),
      'base' => 'node_content',
      'description' => t('Information regarding to access, constructions and closure around the lab'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'flea_market_post' => array(
      'name' => t('Flea market post'),
      'base' => 'node_content',
      'description' => t('A posting from SLAC today\'s Flea market feature'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news_article' => array(
      'name' => t('News Article'),
      'base' => 'node_content',
      'description' => t('News story imported regularly from various sites around SLAC'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
