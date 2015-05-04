<?php
/**
 * @file
 * ct_flea_market_item.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ct_flea_market_item_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_flea_market_post';
  $strongarm->value = 0;
  $export['comment_anonymous_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_flea_market_post';
  $strongarm->value = 1;
  $export['comment_default_mode_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_flea_market_post';
  $strongarm->value = '50';
  $export['comment_default_per_page_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_flea_market_post';
  $strongarm->value = '1';
  $export['comment_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_flea_market_post';
  $strongarm->value = 1;
  $export['comment_form_location_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_flea_market_post';
  $strongarm->value = '1';
  $export['comment_preview_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_flea_market_post';
  $strongarm->value = 1;
  $export['comment_subject_field_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_popup_authored_enabled_flea_market_post';
  $strongarm->value = 1;
  $export['date_popup_authored_enabled_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_popup_authored_format_flea_market_post';
  $strongarm->value = 'm/d/Y - H:i';
  $export['date_popup_authored_format_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_popup_authored_year_range_flea_market_post';
  $strongarm->value = '3';
  $export['date_popup_authored_year_range_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_flea_market_post';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_flea_market_post';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_flea_market_post';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__flea_market_post';
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
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
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
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'news_archive' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'metatags' => array(
          'weight' => '9',
        ),
        'path' => array(
          'weight' => '7',
        ),
        'redirect' => array(
          'weight' => '8',
        ),
      ),
      'display' => array(
        'created' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
        ),
        'author' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-3',
            'visible' => TRUE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
        ),
        'content_type' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_flea_market_post';
  $strongarm->value = array();
  $export['menu_options_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_flea_market_post';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_flea_market_post';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_flea_market_post';
  $strongarm->value = '0';
  $export['node_preview_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_flea_market_post';
  $strongarm->value = 0;
  $export['node_submitted_flea_market_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_flea_market_post_pattern';
  $strongarm->value = 'fleamarket/[current-date:custom:Y]/[current-date:custom:m]/[node:title]';
  $export['pathauto_node_flea_market_post_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_flea_market_post';
  $strongarm->value = 'published';
  $export['workbench_moderation_default_state_flea_market_post'] = $strongarm;

  return $export;
}
