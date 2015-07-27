<?php

/**
 * @file
 * Theme functions for SLAC IP pane output.
 */

/**
 * Template preprocess function for slac_ip_upcoming_events_event.
 */
function template_preprocess_slac_ip_upcoming_events_event(&$variables) {
  $node = $variables['node'];

  $base_settings = array(
    'label' => 'hidden',
    'settings' => array(),
  );

  $display_settings = array_merge($base_settings, array(
    'type' => 'slac_existing_node_url_formatter',
  ));
  $path_field = field_view_field('node', $node, 'field_shared_new_existing', $display_settings);
  $url = $path_field[0]['#markup'];

  $variables['title'] = l($node->title, $url);

  $display_settings = array_merge($base_settings, array(
    'type' => 'date_default',
    'settings' => array(
      'format_type' => 'calendar_item_time',
      'fromto' => 'both',
    ),
  ));
  $times = field_view_field('node', $node, 'field_event_date', $display_settings);
  $variables['times'] = drupal_render($times);

  $display_settings = array_merge($base_settings, array(
    'type' => 'text_default',
  ));
  $location = field_view_field('node', $node, 'field_shared_location', $display_settings);
  $variables['location'] = drupal_render($location);
}
