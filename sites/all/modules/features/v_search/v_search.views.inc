<?php
/**
 * @file
 * v_search.views.inc
 */

/**
 * Implements hook_search_api_views_query_alter().
 *
 * Resolves issue with filtering search by date which are unix time stamps.
 * We must adjust the time stamps to midnight for the from date and midnight
 * of the next day for the to date.
 */
function v_search_search_api_views_query_alter(view &$view, SearchApiViewsQuery &$query) {
  if ($view->name == 'search') {

    // Set from date to unix midnight unix time stamp.
    if (!empty($view->exposed_raw_input['published-from'])) {
      $from_date = new DateTime($view->exposed_raw_input['published-from'], new DateTimeZone('UTC'));
      $unix_from_date = $from_date->getTimestamp();

      // Find the correct condition to modify.
      foreach ($query->where[1]['conditions'] as $key => $condition) {
        if (in_array('published_at', $condition) && $condition[2] == '>=') {
          $query->where[1]['conditions'][$key][1] = $unix_from_date;
          break;
        }
      }
    }

    // Add 24 hours to the to date.
    if (!empty($view->exposed_raw_input['published-to'])) {
      $to_date = new DateTime($view->exposed_raw_input['published-to'], new DateTimeZone('UTC'));
      $unix_to_date = $to_date->getTimestamp();
      $new_to = strtotime('+1 day', $unix_to_date);

      // Find the correct condition to modify.
      foreach ($query->where[1]['conditions'] as $key => $condition) {
        if (in_array('published_at', $condition) && $condition[2] == '<=') {
          $query->where[1]['conditions'][$key][1] = $new_to;
          break;
        }
      }
    }
  }
}
