<?php

/**
* @file
* Field module functionality for the SLAC IP Event Date module.
*/

/**
 * Implements hook_field_formatter_info().
 */
function slac_ip_event_date_field_formatter_info() {
  return array(
    'slac_event_date_formatter' => array(
      'label' => t('SLAC Custom Event Date Format'),
      'description' => t('Custom, dynamic Event Date format for displaying a full date with range of times or range of dates and times.'),
      'field types' => array('datetime'),
    ),
    'slac_event_access_date_formatter' => array(
      'label' => t('SLAC Custom Access Notice Date Format'),
      'description' => t('Custom, dynamic Access Notice Date format for displaying a full date with range of times or range of dates and times.'),
      'field types' => array('datetime'),
    ),
    'slac_event_time_formatter' => array(
      'label' => t('SLAC Custom Event Time Format'),
      'description' => t('Custom, dynamic Event Date format for displaying only the time.'),
      'field types' => array('datetime'),
    ),
    'slac_event_date_detail_formatter' => array(
      'label' => t('SLAC Custom Event Date Detailed Format'),
      'description' => t('Custom, dynamic Event Date format for displaying only the time.'),
      'field types' => array('datetime'),
      'settings' => array('key' => NULL),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function slac_ip_event_date_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();

  if ($display['type'] == 'slac_event_date_detail_formatter') {

    $element['key'] = array(
      '#type' => 'select',
      '#title' => t('Display'),
      '#description' => t('Which value in the Date field to display.'),
      '#options' => array(
        'value' => t('Start Datetime'),
        'value2' => t('End Datetime'),
      ),
      '#default_value' => $settings['key'],
    );
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function slac_ip_event_date_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = '';
  $br = '<br />';

  switch ($display['type']) {
    case 'slac_event_date_formatter':
      $summary = t('Displays full range for start, end date of the date field.')
        . $br . t('Format examples:')
        . $br . '`Monday, February 16, 2015 (All Day)`,'
        . $br . '`Wednesday, August 10, 2016, 3-7 pm`'
        . $br . '`Tuesday, August 9, 2016, 3:15-7:30 pm`,'
        . $br . '`Tuesday, May 9, 2016, (All Day) - Thursday, Aug. 11, 2016, (All Day)`,'
        . $br . '`Tuesday, May 9, 2015, 6 pm - Thursday, Aug. 11, 2016, 9 pm`';
      break;

    case 'slac_event_access_date_formatter':
      $summary = t('Displays full range for start, end date of the date field.')
        . $br . t('Format examples:')
        . $br . '`Monday, February 16, 2015 (All Day)`,'
        . $br . '`Wednesday, August 10, 2016, 3-7 pm`'
        . $br . '`Tuesday, August 9, 2016, 3:15-7:30 pm`,'
        . $br . '`Tuesday, May 9, 2016, (All Day) - Thursday, Aug. 11, 2016, (All Day)`,'
        . $br . '`8 am, Monday, Feb. 9, 2015 to 7 am, Saturday, March 14, 2015`';
      break;

    case 'slac_event_time_formatter':
      $summary = t('Displays full range for start, end time of the date field, or "All Day".')
        . $br . t('Format examples:')
        . $br . '`(All Day)`,'
        . $br . '`3-7 pm`, `3:15-7:30 pm`,'
        . $br . '`3 am-7 pm`, `3:30 am-7:15 pm`';
      break;

    case 'slac_event_date_detail_formatter':
      $key_display = ($settings['key'] == 'value') ? t('Start Datetime') : t('End Datetime');
      $summary = t('Displays a full, detailed Date value.')
        . $br . t('Displaying @key. Format examples:', array(
          '@key' => $key_display,
        ))
        . $br . '`6 am, Saturday, Jun 13, 2015`,'
        . $br . '`6:32 pm, Sunday, Jun 14, 2015`';
      break;
  }

  return $summary;
}

/**
 * Implements hook_field_formatter_view().
 */
function slac_ip_event_date_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'slac_event_date_formatter':
      $element = _slac_event_date_formatter($items);
      break;

    case 'slac_event_access_date_formatter':
      $element = _slac_event_access_date_formatter($items);
      break;

    case 'slac_event_time_formatter':
      $element = _slac_event_time_formatter($items);
      break;

    case 'slac_event_date_detail_formatter':
      $element = _slac_event_date_detail_formatter($items, $display);
      break;
  }

  return $element;
}

/**
 * Helper function for slac_ip_event_date_field_formatter_view().
 * Processes items for the "slac_event_date_formatter" format.
 *
 * @param array $items
 *   The list of items to process passed from the formatter view hook.
 *
 * @return array
 *   The list of processed elements to be returned by the formatter view hook.
 *
 * @see slac_ip_event_date_field_formatter_view()
 */
function _slac_event_date_formatter($items) {
  $element = array();

  foreach ($items as $delta => $item) {
    $date_values = _slac_ip_event_date_create_datetimes($item);
    $value1 = $date_values['value'];
    $value2 = $date_values['value2'];

    $interval = $value1->diff($value2);

    // Format datetime strings for use with date_is_all_day().
    $v1str = $value1->format('Y-m-d H:i:s');
    $v2str = $value2->format('Y-m-d H:i:s');

    if ($interval->days == 0) {
      // Single day event.

      if (date_is_all_day($v1str, $v2str)) {
        // Single day, all day.
        // Format is `Tuesday, August 9, 2016 (All Day)`
        $markup = t(
          '!date (All Day)',
          array(
            '!date' => $value1->format('l, F j, Y'),
          ));
      }
      else {
        // Single day with start, end times.
        // If times are both 'am' or both 'pm', only display it on end time.
        // Format examples:
        //  `Wednesday, August 10, 2016, 3-7 pm`
        //  `Tuesday, August 9, 2016, 3:15-7:30 pm`
        $formats = _slac_ip_event_date_get_time_fmts($value1, $value2);
        $start_time_fmt = $formats['value'];
        $end_time_fmt = $formats['value2'];

        $start_fmt = 'l, F j, Y, ' . $start_time_fmt;

        $markup = t(
          '!start-date-!end-time',
          array(
            '!start-date' => $value1->format($start_fmt),
            '!end-time' => $value2->format($end_time_fmt),
          ));
      }
    }
    else {
      // Multiple day event.

      // Both these formats have arbitrary month abbreviations.
      $month_fmt1 = _slac_ip_event_date_get_month_fmt($value1);
      $month_fmt2 = _slac_ip_event_date_get_month_fmt($value2);

      if (date_is_all_day($v1str, $v2str)) {
        // Multi-day event, all day.
        // Format is:
        //   `Tuesday, May 9, 2015, (All Day) - Thursday, Aug. 11, 2016, (All Day)`
        $start_fmt = 'l, ' . $month_fmt1 . ' j, Y';
        $end_fmt = 'l, ' . $month_fmt2 . ' j, Y';

        $markup = t(
          '!start-date, (All Day) - !end-date, (All Day)',
          array(
            '!start-date' => $value1->format($start_fmt),
            '!end-date' => $value2->format($end_fmt),
          ));
      }
      else {
        // Multi-day event with start, end times.
        // Format is:
        //   `Tuesday, May 9, 2015, 6 pm - Thursday, Aug. 11, 2016, 9 pm`
        $formats = _slac_ip_event_date_get_time_fmts($value1, $value2);
        $start_time_fmt = $formats['value'];
        $end_time_fmt = $formats['value2'];

        $start_fmt = 'l, ' . $month_fmt1 . ' j, Y, ' . $start_time_fmt;
        $end_fmt = 'l, ' . $month_fmt2 . ' j, Y, ' . $end_time_fmt;

        $markup = t(
          '!start-date - !end-date',
          array(
            '!start-date' => $value1->format($start_fmt),
            '!end-date' => $value2->format($end_fmt),
          ));
      }
    }

    $element[$delta] = array('#markup' => $markup);
  }

  return $element;
}

/**
 * Helper function for slac_ip_event_date_field_formatter_view().
 * Processes items for the "slac_event_access_date_formatter" format.
 *
 * @param array $items
 *   The list of items to process passed from the formatter view hook.
 *
 * @return array
 *   The list of processed elements to be returned by the formatter view hook.
 *
 * @see slac_ip_event_date_field_formatter_view()
 */
function _slac_event_access_date_formatter($items) {
  $element = array();

  foreach ($items as $delta => $item) {
    $date_values = _slac_ip_event_date_create_datetimes($item);
    $value1 = $date_values['value'];
    $value2 = $date_values['value2'];

    $interval = $value1->diff($value2);

    // Format datetime strings for use with date_is_all_day().
    $v1str = $value1->format('Y-m-d H:i:s');
    $v2str = $value2->format('Y-m-d H:i:s');

    if ($interval->days == 0) {
      // Single day event for Access is the same as for Event.
      return _slac_event_date_formatter($items);
    }
    else {
      // Multiple day event.

      // Both these formats have arbitrary month abbreviations.
      $month_fmt1 = _slac_ip_event_date_get_month_fmt($value1);
      $month_fmt2 = _slac_ip_event_date_get_month_fmt($value2);

      if (date_is_all_day($v1str, $v2str)) {
        // All day format is the same as Event.
        return _slac_event_date_formatter($items);
      }
      else {
        // Multi-day event with start, end times.
        // Format is:
        //   `8 am, Monday, Feb. 9, 2015 to 7 am, Saturday, March 14, 2015`
        $formats = _slac_ip_event_date_get_time_fmts($value1, $value2);
        $start_time_fmt = $formats['value'];
        $end_time_fmt = $formats['value2'];

        $start_fmt = $start_time_fmt . ', l, ' . $month_fmt1 . ' j, Y';
        $end_fmt = $end_time_fmt . ', l, ' . $month_fmt2 . ' j, Y';

        $markup = t(
          '!start-date to !end-date',
          array(
            '!start-date' => $value1->format($start_fmt),
            '!end-date' => $value2->format($end_fmt),
          ));
      }
    }

    $element[$delta] = array('#markup' => $markup);
  }

  return $element;
}

/**
 * Helper function for printing an arbitrary month format based on date.
 *
 * @param $date
 *   The date object to get the proper month format string for.
 *
 * @return string
 *   The format string to use with date() to output this date's month, or
 *   literal "Sept.".
 */
function _slac_ip_event_date_get_month_fmt($date) {
  //Jan., Feb., Aug., Oct., Nov., and Dec.
  $abbrev_months = array(1, 2, 8, 10, 11, 12);
  // Sept. is an exception

  $month = $date->format('n');

  if (in_array($month, $abbrev_months)) {
    // M, A short textual representation of a month, three letters.
    $fmt = 'M.';
  }
  elseif ($month == 9) {
    // Literal "Sept." has to be escaped to it doesn't get parsed as date
    // formatting options.
    $fmt = t('\S\ep\t.');
  }
  else {
    // F, A full textual representation of a month, such as January or March.
    $fmt = 'F';
  }

  return $fmt;
}

/**
 * Helper function for slac_ip_event_date_field_formatter_view().
 * Processes items for the "slac_event_time_formatter" format.
 *
 * @param array $items
 *   The list of items to process passed from the formatter view hook.
 *
 * @return array
 *   The list of processed elements to be returned by the formatter view hook.
 *
 * @see slac_ip_event_date_field_formatter_view()
 */
function _slac_event_time_formatter($items) {
  $element = array();

  foreach ($items as $delta => $item) {
    $date_values = _slac_ip_event_date_create_datetimes($item);
    $value1 = $date_values['value'];
    $value2 = $date_values['value2'];

    // Format datetime strings for use with date_is_all_day().
    $v1str = $value1->format('Y-m-d H:i:s');
    $v2str = $value2->format('Y-m-d H:i:s');

    // Single day event.
    if (date_is_all_day($v1str, $v2str)) {
      // Single day, all day.
      // Format is `(All Day)`
      $markup = t('(All Day)');
    }
    else {
      // See _slac_ip_event_date_get_time_fmt() for format examples.
      $formats = _slac_ip_event_date_get_time_fmts($value1, $value2);
      $start_time_fmt = $formats['value'];
      $end_time_fmt = $formats['value2'];

      $markup = t(
        '!start-time-!end-time',
        array(
          '!start-time' => $value1->format($start_time_fmt),
          '!end-time' => $value2->format($end_time_fmt),
        ));
    }

    $element[$delta] = array('#markup' => $markup);
  }

  return $element;
}


/**
 * Helper function for slac_ip_event_date_field_formatter_view().
 * Processes items for the "slac_event_time_formatter" format.
 *
 * @param array $items
 *   The list of items to process passed from the formatter view hook.
 * @param array $display
 *   The display settings from slac_ip_event_date_field_formatter_view().
 *
 * @return array
 *   The list of processed elements to be returned by the formatter view hook.
 *
 * @see slac_ip_event_date_field_formatter_view()
 */
function _slac_event_date_detail_formatter($items, $display) {
  $element = array();

  foreach ($items as $delta => $item) {
    $date_values = _slac_ip_event_date_create_datetimes($item);

    $key = $display['settings']['key'];

    $date_obj = $date_values[$key];

    $value1 = $date_values['value'];
    $value2 = $date_values['value2'];

    // Format datetime strings for use with date_is_all_day().
    $v1str = $value1->format('Y-m-d H:i:s');
    $v2str = $value2->format('Y-m-d H:i:s');

    if (date_is_all_day($v1str, $v2str)) {
      // Format::
      //   `Saturday, Jun 13, 2015 (All Day)`
      $markup = $date_obj->format('l, M j, Y') .' ' . t('(All Day)');
    }
    else {
      // Format examples:
      //   `6 am, Saturday, Jun 13, 2015`
      //   `6:32 pm, Sunday, Jun 14, 2015`
      $time_fmt = 'g';
      if ($date_obj->format('i') != '00') {
        $time_fmt .= ':i';
      }
      $time_fmt .= ' a';
      $markup = $date_obj->format($time_fmt . ', l, M j, Y');
    }

    $element[$delta] = array('#markup' => $markup);
  }

  return $element;
}

/**
 * Helper function to determine the format strings for displaying an interval
 * between two DateTime values.
 *
 * @param $value1
 * @param $value2
 *   Start and end time values.
 *
 * @return array
 *   Array of two date format strings for displaying these time values as an
 *   interval.
 */
function _slac_ip_event_date_get_time_fmts($value1, $value2) {

  // Only minutes past the hour should be displayed.
  $start_min = $value1->format('i');
  $end_min = $value2->format('i');
  $start_fmt = ($start_min == '00') ? 'g' : 'g:i';
  $end_fmt = ($end_min == '00') ? 'g a' : 'g:i a';

  // If times are both 'am' or both 'pm', only display on end time.
  // Format examples `3-7 pm`, `3:15-7:30 pm`
  if ($value1->format('a') != $value2->format('a')) {
    // Times span am/pm, add to start time as well.
    // Format examples: `Wednesday, August 10, 2016, 3 am-7 pm`
    //  `Wednesday, August 10, 2016, 3:30 am-7:15 pm`
    $start_fmt .= ' a';
  }

  // Key the format strings the same way Date module keys the datetime field
  // values.
  $formats = array(
    'value' => $start_fmt,
    'value2' => $end_fmt,
  );

  return $formats;
}

/**
 * Helper function to construct DateTime objects from a datetime field item.
 *
 * @param $item
 *   The datetime field item array.
 *
 * @return array
 *   An array of constructed DateTime objects for both field values.
 */
function _slac_ip_event_date_create_datetimes($item) {
  $value = NULL;
  $value2 = NULL;

  try {
    $tz_db = new DateTimeZone($item['timezone_db']);
    $tz = new DateTimeZone($item['timezone']);
    $value = new DateTime($item['value'], $tz_db);
    $value->setTimezone($tz);
    $value2 = new DateTime($item['value2'], $tz_db);
    $value2->setTimezone($tz);
  }
  catch (Exception $e) {
    $message = 'There was an exception while creating a DateTime: %msg';
    watchdog('slac_ip_event_date', $message, array('%msg' => $e->getMessage()), WATCHDOG_ERROR);
  }

  // Key the date objects the same way Date module keys the datetime field
  // values, if DateTime construction failed, ensure these return valid objects.
  $values = array(
    'value' => ($value) ? $value : new DateTime(),
    'value2' => ($value2) ? $value2 : new DateTime(),
  );

  return $values;
}
