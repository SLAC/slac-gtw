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

/**
 * Implements hook_image_default_styles().
 */
function v_news_image_default_styles() {
  $styles = array();

  // Exported image style: news_-_featured_slideshow.
  $styles['news_-_featured_slideshow'] = array(
    'label' => 'News - Featured Slideshow',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 580,
          'height' => 361,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
