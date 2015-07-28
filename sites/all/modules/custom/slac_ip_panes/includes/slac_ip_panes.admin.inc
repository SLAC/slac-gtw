<?php

/**
 * @file
 * Provides admin page callbacks for SLAC IP Panes module.
 */

function slac_ip_panes_settings_upcoming_events($form, &$form_state) {
  $form = array();

  $form['slac_ip_panes_upcoming_events'] = array(
    '#type' => 'fieldset',
    '#title' => t('Upcoming Events Settings'),
    '#collapsible' => FALSE,
  );
  $fieldset = &$form['slac_ip_panes_upcoming_events'];

  $varname = 'slac_ip_panes_upcoming_events_max_days';
  $fieldset[$varname] = array(
    '#type' => 'textfield',
    '#size' => 5,
    '#title' => t('Max Displayed Upcoming Days'),
    '#default_value' => variable_get($varname, '3'),
  );

  $varname = 'slac_ip_panes_upcoming_events_max_per_day';
  $fieldset[$varname] = array(
    '#type' => 'textfield',
    '#size' => 5,
    '#title' => t('Max Displayed Upcoming Events Per Day'),
    '#description' => t('Days with more than this number of events will display a link to the calendar.'),
    '#default_value' => variable_get($varname, '2'),
  );

  return system_settings_form($form);
}
