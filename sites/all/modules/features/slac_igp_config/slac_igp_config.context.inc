<?php
/**
 * @file
 * slac_igp_config.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function slac_igp_config_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'weather_block-weather_block' => array(
          'module' => 'weather_block',
          'delta' => 'weather_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'boxes-search_people' => array(
          'module' => 'boxes',
          'delta' => 'search_people',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'boxes-web_search' => array(
          'module' => 'boxes',
          'delta' => 'web_search',
          'region' => 'header',
          'weight' => '-10',
        ),
        'boxes-footer' => array(
          'module' => 'boxes',
          'delta' => 'footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  $export['sitewide'] = $context;

  return $export;
}
