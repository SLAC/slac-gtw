<?php
/**
 * @file
 * slac_igp_feed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_igp_feed_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function slac_igp_feed_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function slac_igp_feed_image_default_styles() {
  $styles = array();

  // Exported image style: featured_news.
  $styles['featured_news'] = array(
    'name' => 'featured_news',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 575,
          'height' => 370,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
