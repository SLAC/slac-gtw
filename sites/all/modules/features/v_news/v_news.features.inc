<?php
/**
 * @file
 * v_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function v_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function v_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function v_news_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_news
  $nodequeues['featured_news'] = array(
    'name' => 'featured_news',
    'title' => 'Featured News',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'access_information',
      1 => 'event',
      2 => 'news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: lab_news
  $nodequeues['lab_news'] = array(
    'name' => 'lab_news',
    'title' => 'Lab News',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'access_information',
      1 => 'event',
      2 => 'news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: slac_science_news
  $nodequeues['slac_science_news'] = array(
    'name' => 'slac_science_news',
    'title' => 'SLAC Science',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'access_information',
      1 => 'event',
      2 => 'news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
