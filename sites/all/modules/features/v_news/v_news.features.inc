<?php
/**
 * @file
 * v_news.features.inc
 */

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

  // Exported nodequeues: lab_news
  $nodequeues['lab_news'] = array(
    'name' => 'lab_news',
    'title' => 'Lab News',
    'subqueue_title' => '',
    'size' => 10,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
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
