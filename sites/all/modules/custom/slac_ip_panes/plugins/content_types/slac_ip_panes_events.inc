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
  $now = date('c');

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'event')
    ->fieldCondition('field_event_date', 'value2', $now, '>')
    ->fieldOrderBy('field_event_date', 'value', 'ASC')
    ->range(0, 3);
  $result = $query->execute();

  // If there are no nodes, return early.
  if (empty($result['node'])) {
    $block->content = theme('slac_ip_upcoming_events', array('content' => 'There are no upcoming events at this time.'));
    return $block;
  }

  // Prepare the list of rendered event items, gropued by month, day.
  $events_content = _slac_ip_upcoming_events_render_events_content($result);

  $content = _slac_ip_upcoming_events_render_block_content($events_content);

  $block->content = theme('slac_ip_upcoming_events', array('content' => $content));

  return $block;
}

/**
 * Helper function that prepares the list of rendered events grouped into
 * days by month.
 *
 * @param $result
 *   The EFQ result with nodes to render event items for.
 *
 * @return array
 *   List of rendered event items grouped by month, day.
 */
function _slac_ip_upcoming_events_render_events_content($result) {
  $events_content = array();

  foreach ($result['node'] as $nid => $node) {
    $node = node_load($nid);
    $date_field = field_get_items('node', $node, 'field_event_date');

    try {
      $date = new DateTime($date_field[0]['value']);
    }
    catch (Exception $e) {
      continue;
    }

    $month = $date->format('M');
    $day = $date->format('j');

    $vars = array(
      'node' => $node,
    );
    $events_content[$month][$day][] = theme('slac_ip_upcoming_events_event', $vars);
  }

  return $events_content;
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

  foreach ($events_content as $month => $day_items) {
    foreach ($day_items as $day => $day_rows) {
      $content .= '<div class="views-row-grouped">';
      $content .= '  <h3>';
      $content .= '    <span class="month">' . $month . '</span>';
      $content .= '    <span class="day">' . $day . '</span>';
      $content .= '  </h3>';

      $count = count($day_rows);
      for ($i = 0; $i < $count; $i++) {
        $class = 'views-row';
        $class .= ($i == 0) ? ' views-row-first' : '';
        $class .= ($i == $count - 1) ? ' views-row-last' : '';

        $content .= '<div class="' . $class . '">' . $day_rows[$i] . '</div>';
      }

      $content .= '</div>';
    }
  }

  return $content;
}
