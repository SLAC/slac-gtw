<?php
/**
 * @file
 * slac_igp_importers.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function slac_igp_importers_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_feeds_importer';
  $strongarm->value = array(
    'slac_access_info' => TRUE,
    'slac_events' => TRUE,
    'slac_flea_market' => TRUE,
    'slac_news' => FALSE,
    'organization_term' => TRUE,
    'research_resource_term' => TRUE,
    'slac_research_resource' => TRUE,
    'staff_resource_modern' => TRUE,
  );
  $export['default_feeds_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__calendar_feed';
  $strongarm->value = array(
    'view_modes' => array(
      'link' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'headline' => array(
        'custom_settings' => FALSE,
      ),
      'news_archive' => array(
        'custom_settings' => FALSE,
      ),
      'access_listing' => array(
        'custom_settings' => FALSE,
      ),
      'slac_term_listing' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'content_type' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
        'created' => array(
          'default' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
        ),
        'published_at' => array(
          'default' => array(
            'weight' => '-3',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '-3',
            'visible' => FALSE,
          ),
        ),
        'author' => array(
          'default' => array(
            'weight' => '-2',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-2',
            'visible' => TRUE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__calendar_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__news_feed';
  $strongarm->value = array(
    'view_modes' => array(
      'link' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'headline' => array(
        'custom_settings' => FALSE,
      ),
      'news_archive' => array(
        'custom_settings' => FALSE,
      ),
      'access_listing' => array(
        'custom_settings' => FALSE,
      ),
      'slac_term_listing' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'content_type' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
        'created' => array(
          'default' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
        ),
        'published_at' => array(
          'default' => array(
            'weight' => '-3',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '-3',
            'visible' => FALSE,
          ),
        ),
        'author' => array(
          'default' => array(
            'weight' => '-2',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-2',
            'visible' => TRUE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__news_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_calendar_feed';
  $strongarm->value = array();
  $export['menu_options_calendar_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_news_feed';
  $strongarm->value = array();
  $export['menu_options_news_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_calendar_feed';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_calendar_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_news_feed';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_news_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_calendar_feed';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_calendar_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_news_feed';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_news_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_calendar_feed';
  $strongarm->value = '1';
  $export['node_preview_calendar_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_news_feed';
  $strongarm->value = '1';
  $export['node_preview_news_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_calendar_feed';
  $strongarm->value = 0;
  $export['node_submitted_calendar_feed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_news_feed';
  $strongarm->value = 0;
  $export['node_submitted_news_feed'] = $strongarm;

  return $export;
}
