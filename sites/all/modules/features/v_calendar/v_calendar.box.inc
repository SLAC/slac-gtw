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
      'value' => '<ul><li class="access_notices">Access Notices</li><li class="summer_school_programs">Summer School Programs</li><li class="conference_workshops">Conference &amp; Workshops</li><li class="talks_seminars_colloquia">Talks, Seminars, &amp; Colloquia</li><li class="public_event_tours">Public Event &amp; Tours</li><li class="training_development">Training &amp; Development</li><li class="staff_celebrations">Staff Celebrations</li><li class="none">None</li></ul>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['calendar_legend'] = $box;

  return $export;
}
