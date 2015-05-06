<?php
/**
 * @file
 * pm_calendar.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function pm_calendar_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'calendar_event_type_legend';
  $content->admin_title = 'Calendar - Event Type Legend';
  $content->admin_description = 'Event Type Legend block for display on Calendar pages.';
  $content->category = 'SLAC Today';
  $content->settings = array(
    'admin_title' => 'Calendar - Event Type Legend',
    'title' => 'Event Type Legend',
    'body' => '<ul>
<li class="access_notices">Access Notices</li>
<li class="summer_school_programs">Summer School Programs</li>
<li class="conference_workshops">Conference & Workshops</li>
<li class="talks_seminars_colloquia">Talks, Seminars, & Colloquia</li>
<li class="public_event_tours">Public Event & Tours</li>
<li class="training_development">Training & Development</li>
<li class="staff_celebrations">Staff Celebrations</li>
<li class="none">None</li>
</ul>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $export['calendar_event_type_legend'] = $content;

  return $export;
}
