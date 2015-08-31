<?php
/**
 * @file
 * Provides the Upcoming Events pane for the front page.
 */

$plugin = array(
  'title' => t('SLAC Upcoming Events'),
  'description' => t('Displays the Upcoming Events for the front page.'),
  'category' => t('SLAC IP'),
  'single' => TRUE,
  'render callback' => 'slac_ip_upcoming_events_render',
  'edit form' => 'slac_ip_upcoming_events_edit_form',
  'all contexts' => TRUE,
);

/**
 * 'Edit' callback for the content type.
 */
function slac_ip_upcoming_events_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @param $subtype
 *   Panel subtype.
 * @param $conf
 *   Configuration as done at admin time
 * @param array $args
 *   Panel arguments.
 * @param string $context
 *   Panel context.
 *
 * @return object
 *   An object with at least title and content values.
 */
function slac_ip_upcoming_events_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Upcoming Events');
  $today = date('Y-m-d');

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_event_date', 'value2', $today, '>=')
    ->fieldOrderBy('field_event_date', 'value', 'ASC');
  $result = $query->execute();

  // If there are no nodes, return early.
  if (empty($result['node'])) {
    $block->content = theme('slac_ip_upcoming_events', array('content' => 'There are no upcoming events at this time.'));
    return $block;
  }

  // Prepare the list of rendered event items, grouped by month, day.
  $events_content = _slac_ip_upcoming_events_render_events_content($result);

  $content = _slac_ip_upcoming_events_render_block_content($events_content);

  $block->content = theme('slac_ip_upcoming_events', array('content' => $content));

  return $block;
}

/**
 * Helper function that prepares the list of rendered events grouped into
 * days by month.
 *
 * If an Event starts in the past, the item will be modified to display today.
 *
 * @param $result
 *   The EFQ result with nodes to render event items for.
 *
 * @return array
 *   List of rendered event items grouped by month, day.
 */
function _slac_ip_upcoming_events_render_events_content($result) {
  $events_content = array();
  $now = new DateTime('now');
  $max_days = variable_get('slac_ip_panes_upcoming_events_max_days', 3);
  $day_count = 0;
  $max_per_day = variable_get('slac_ip_panes_upcoming_events_max_per_day', 2);

  foreach ($result['node'] as $nid => $node) {
    $node = node_load($nid);
    $date_field = field_get_items('node', $node, 'field_event_date');

    // Create a DateTime object using the date field TZ values.
    $date = _slac_ip_panes_events_create_datetime($date_field[0], 'value');
    if ($date == NULL) {
      // Error was logged if an exception occured in
      // _slac_ip_panes_events_create_datetime(), skip this item.
      continue;
    }

    $diff = $now->diff($date);

    // If the start date is on a past day, display for today instead.
    if ($diff->invert && $diff->d != 0) {
      $date->add(new DateInterval('P' . $diff->d . 'D'));
      $field = &$node->field_event_date[$node->language][0];
      $field['value'] = $date->format('Y-m-d H:i:s');
    }

    $days_to_render = _list_days_to_render($node, $date);

    // Make a row for each date this Event should appear under, respecting max
    // counts for days to display and events per day.
    foreach ($days_to_render as $date) {
      $month = $date->format('M');
      $day = $date->format('j');

      $day_event_count = 0;
      if (isset($events_content[$month][$day])) {
        $day_event_count = count($events_content[$month][$day]);
      }
      else {
        $day_count += 1;
        // If the day max has been reached, stop here (events were selected with
        // ascending date ordering.)
        if ($day_count > $max_days) {
          break;
        }
      }

      if ($day_event_count == $max_per_day) {
        $url_date = $date->format('Y-m-d');

        // Add a 'More events' link and do not add more items for this day.
        $link = l(t('More events'), 'calendar/day/' . $url_date);
        $events_content['#more'][$month][$day] = $link;
      }
      elseif ($day_event_count > $max_per_day) {
        // The max was already reached and the 'More events' link already added.
        continue;
      }
      else {
        // Otherwise, render the day and add to the list.
        $vars = array(
          'node' => $node,
        );
        $events_content[$month][$day][] = theme('slac_ip_upcoming_events_event', $vars);
      }
    }
  }

  return $events_content;
}

/**
 * Helper function that lists all the days this Event should appear under.
 *
 * @param $node
 *   The Event node.
 * @param DateTime $start_date
 *   The first date to render under. The returned list will always contain this
 *   date at least.
 *
 * @return DateTime[] array
 *   The array of dates to render this Event in.
 */
function _list_days_to_render($node, $start_date) {
  $max_days = variable_get('slac_ip_panes_upcoming_events_max_days', 3);

  $days_to_render = array(clone $start_date,);

  $date_field = field_get_items('node', $node, 'field_event_date');

  // If the Event occurs on future days as wall, add rows for them.
  $date2 = _slac_ip_panes_events_create_datetime($date_field[0], 'value2');
  if ($date2 == NULL) {
    return $days_to_render;
  }

  $diff = $start_date->diff($date2);

  if ($diff->d > 0) {
    $one_day = new DateInterval('P1D');

    // Don't bother going over max days.
    $num_days = $diff->d;
    if ($diff->d > $max_days) {
      $num_days = $max_days;
    }
    for ($i = 0; $i < $num_days; $i++) {
      $start_date->add($one_day);
      $days_to_render[] = clone $start_date;
    }
  }

  return $days_to_render;
}

/**
 * Helper function that renders the block content for the pane.
 *
 * @param $events_content
 *   The list of rendered event items grouped by month, day.
 *
 * @return string
 *   The rendered content for the pane.
 */
function _slac_ip_upcoming_events_render_block_content($events_content) {
  $content = '';

  foreach ($events_content as $month_key => $day_items) {
    if (strpos($month_key, '#') === 0) {
      // Skip metadata added in the render function
      // _slac_ip_upcoming_events_render_events_content().
      continue;
    }

    foreach ($day_items as $day => $day_rows) {
      $more = (isset($events_content['#more'][$month_key][$day]));

      $content .= '<div class="views-row-grouped">';
      $content .= '  <h3>';
      $content .= '    <span class="month">' . $month_key . '</span>';
      $content .= '    <span class="day">' . $day . '</span>';
      $content .= '  </h3>';

      $count = count($day_rows);
      for ($i = 0; $i < $count; $i++) {
        $class = 'views-row';
        $class .= ($i == 0) ? ' views-row-first' : '';
        if (!$more) {
          // The 'view more' row in views counts as the last row.
          $class .= ($i == $count - 1) ? ' views-row-last' : '';
        }

        $content .= '<div class="' . $class . '">' . $day_rows[$i] . '</div>';
      }

      if ($more) {
        $content .= '<div class="more views-row views-row-last">'
          . $events_content['#more'][$month_key][$day] . '</div>';
      }

      $content .= '</div>';
    }
  }

  return $content;
}

/**
 * Helper function to construct a DateTime object from a datetime field item.
 *
 * @param array $item
 *   The datetime field item.
 * @param string $key
 *   The datetime item key to create an object from.
 *
 * @return DateTime|null
 *   The DateTime object for the passed field value, or null if there was an
 *   error.
 */
function _slac_ip_panes_events_create_datetime($item, $key = 'value') {
  try {
    $tz_db = new DateTimeZone($item['timezone_db']);
    $tz = new DateTimeZone($item['timezone']);
    $value = new DateTime($item[$key], $tz_db);
    $value->setTimezone($tz);
  }
  catch (Exception $e) {
    $message = 'There was an exception while creating a DateTime: %msg';
    watchdog('slac_ip_panes', $message, array('%msg' => $e->getMessage()), WATCHDOG_ERROR);
    $value = NULL;
  }

  return $value;
}
