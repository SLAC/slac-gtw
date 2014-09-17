<?php
/**
 * @file
 * slac_igp_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function slac_igp_config_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function slac_igp_config_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function slac_igp_config_image_default_styles() {
  $styles = array();

  // Exported image style: mailchimp_news_teaser.
  $styles['mailchimp_news_teaser'] = array(
    'name' => 'mailchimp_news_teaser',
    'effects' => array(
      0 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
          'height' => 350,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Imported from scientific, training and staff calendars'),
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
  return $items;
}
