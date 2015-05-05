<?php
/**
 * @file
 * ct_access_information.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ct_access_information_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_access_information';
  $strongarm->value = 'edit-scheduler';
  $export['additional_settings__active_tab_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_access_information';
  $strongarm->value = '1';
  $export['comment_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_access_information';
  $strongarm->value = 0;
  $export['comment_anonymous_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_access_information';
  $strongarm->value = 1;
  $export['comment_default_mode_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_access_information';
  $strongarm->value = '50';
  $export['comment_default_per_page_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_access_information';
  $strongarm->value = 1;
  $export['comment_form_location_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_access_information';
  $strongarm->value = '1';
  $export['comment_preview_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_access_information';
  $strongarm->value = 1;
  $export['comment_subject_field_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_access_information';
  $strongarm->value = 'D, M j';
  $export['date_format_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_slac_ip_access_date';
  $strongarm->value = 'g:i a, l, M j, Y';
  $export['date_format_slac_ip_access_date'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_access_information';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_access_information';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_access_information';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__access_information';
  $strongarm->value = array(
    'view_modes' => array(
      'link' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
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
        'custom_settings' => TRUE,
      ),
      'access_listing' => array(
        'custom_settings' => TRUE,
      ),
      'slac_term_listing' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'metatags' => array(
          'weight' => '20',
        ),
        'path' => array(
          'weight' => '18',
        ),
        'redirect' => array(
          'weight' => '19',
        ),
      ),
      'display' => array(
        'created' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'news_archive' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'search_result' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'access_listing' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'slac_term_listing' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'author' => array(
          'default' => array(
            'weight' => '-3',
            'visible' => FALSE,
          ),
          'news_archive' => array(
            'weight' => '7',
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
          'access_listing' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'slac_term_listing' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
          'news_archive' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
          'access_listing' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'slac_term_listing' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'content_type' => array(
          'search_result' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'news_archive' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'access_listing' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'slac_term_listing' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_access_information';
  $strongarm->value = array();
  $export['menu_options_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_access_information';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_access_information';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_access_information';
  $strongarm->value = '1';
  $export['node_preview_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_access_information';
  $strongarm->value = 0;
  $export['node_submitted_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_access_information_pattern';
  $strongarm->value = 'access/[current-date:custom:Y]/[current-date:custom:m]/[node:title]';
  $export['pathauto_node_access_information_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_expand_fieldset_access_information';
  $strongarm->value = '0';
  $export['scheduler_expand_fieldset_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_access_information';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_past_date_access_information';
  $strongarm->value = 'error';
  $export['scheduler_publish_past_date_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_access_information';
  $strongarm->value = 0;
  $export['scheduler_publish_required_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_access_information';
  $strongarm->value = 0;
  $export['scheduler_publish_revision_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_access_information';
  $strongarm->value = 0;
  $export['scheduler_publish_touch_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_access_information';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_access_information';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_access_information';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_use_vertical_tabs_access_information';
  $strongarm->value = '1';
  $export['scheduler_use_vertical_tabs_access_information'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_access_information';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_access_information'] = $strongarm;

  return $export;
}
