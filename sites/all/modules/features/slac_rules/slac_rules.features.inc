<?php
/**
 * @file
 * slac_rules.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function slac_rules_flag_default_flags() {
  $flags = array();
  // Exported flag: "Comment flag".
  $flags['comment_flag'] = array(
    'entity_type' => 'comment',
    'title' => 'Comment flag',
    'global' => 0,
    'types' => array(
      0 => 'comment_node_news',
    ),
    'flag_short' => 'Report as Inappropriate',
    'flag_long' => 'Report as Inappropriate',
    'flag_message' => '',
    'unflag_short' => 'Reported as inappropriate',
    'unflag_long' => 'Reported as inappropriate',
    'unflag_message' => '',
    'unflag_denied_text' => 'Reported as inappropriate',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'ical' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'api_version' => 3,
    'module' => 'slac_rules',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
