<?php
/**
 * @file
 * slac_igp_feed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_igp_feed_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function slac_igp_feed_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function slac_igp_feed_image_default_styles() {
  $styles = array();

  // Exported image style: featured_news.
  $styles['featured_news'] = array(
    'label' => 'featured_news',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 588,
          'height' => 378,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
