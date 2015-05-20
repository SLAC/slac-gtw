<?php
/**
 * @file
 * v_calendar.box.inc
 */

/**
 * Implements hook_default_box().
 */
function v_calendar_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'calendar_legend';
  $box->plugin_key = 'simple';
  $box->title = 'Event Type Legend';
  $box->description = 'Calendar Legend';
  $box->options = array(
    'body' => array(
      'value' => '<ul class="events-color-legend"><li class="event-access-notices">Access Notices</li><li class="event-summer-school-programs">Summer School Programs</li><li class="event-conference-workshops">Conference &amp; Workshops</li><li class="event-talks-seminars-colloquia">Talks, Seminars, &amp; Colloquia</li><li class="event-public-event-tours">Public Event &amp; Tours</li><li class="event-training-development">Training &amp; Development</li><li class="event-staff-celebrations">Staff Celebrations</li><li class="event-none">None</li></ul>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['calendar_legend'] = $box;

  return $export;
}
