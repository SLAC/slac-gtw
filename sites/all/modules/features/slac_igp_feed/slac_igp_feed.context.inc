<?php
/**
 * @file
 * slac_igp_feed.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function slac_igp_feed_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'all elements associated with the home page';
  $context->tag = 'Home Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-news-block_1' => array(
          'module' => 'views',
          'delta' => 'news-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-news-block_3' => array(
          'module' => 'views',
          'delta' => 'news-block_3',
          'region' => 'content',
          'weight' => '-8',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'sidebar_first',
          'weight' => '-23',
        ),
        'views-calendar-block' => array(
          'module' => 'views',
          'delta' => 'calendar-block',
          'region' => 'sidebar_first',
          'weight' => '-22',
        ),
        'views-access_information-block' => array(
          'module' => 'views',
          'delta' => 'access_information-block',
          'region' => 'sidebar_first',
          'weight' => '-21',
        ),
        'boxes-weather_traffic' => array(
          'module' => 'boxes',
          'delta' => 'weather_traffic',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'boxes-slac_projects' => array(
          'module' => 'boxes',
          'delta' => 'slac_projects',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'boxes-it_help_desk' => array(
          'module' => 'boxes',
          'delta' => 'it_help_desk',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'boxes-site_security' => array(
          'module' => 'boxes',
          'delta' => 'site_security',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-flea_market-block' => array(
          'module' => 'views',
          'delta' => 'flea_market-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'boxes-stanford_compliance' => array(
          'module' => 'boxes',
          'delta' => 'stanford_compliance',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'boxes-connect' => array(
          'module' => 'boxes',
          'delta' => 'connect',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'boxes-feedback' => array(
          'module' => 'boxes',
          'delta' => 'feedback',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page');
  t('all elements associated with the home page');
  $export['homepage'] = $context;

  return $export;
}
