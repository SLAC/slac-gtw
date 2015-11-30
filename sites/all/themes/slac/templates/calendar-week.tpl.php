<?php
/**
 * @file
 * Template to display a view as a calendar week.
 *
 * @see template_preprocess_calendar_week.
 *
 * $day_names: An array of the day of week names for the table header.
 * $rows: The rendered data for this week.
 *
 * For each day of the week, you have:
 * $rows['date'] - the date for this day, formatted as YYYY-MM-DD.
 * $rows['datebox'] - the formatted datebox for this day.
 * $rows['empty'] - empty text for this day, if no items were found.
 * $rows['all_day'] - an array of formatted all day items.
 * $rows['items'] - an array of timed items for the day.
 * $rows['items'][$time_period]['hour'] - the formatted hour for a time period.
 * $rows['items'][$time_period]['ampm'] - the formatted ampm value, if any for a time period.
 * $rows['items'][$time_period]['values'] - An array of formatted items for a time period.
 *
 * $view: The view.
 * $min_date_formatted: The minimum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * $max_date_formatted: The maximum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 *
 */

$index = 0;
$header_ids = array();
foreach ($day_names as $key => $value) {
  $header_ids[$key] = $value['header_id'];
}
$today = new DateTime(date('Y-m-d'));
$today_day_col = $today->format('w');
?>
<div class="calendar-calendar"><div class="week-view">
<table class="full">
  <thead>
    <tr>
      <?php foreach ($day_names as $cell): ?>
        <?php
        if ($cell['header_id'] == 'Saturday' || $cell['header_id'] == 'Sunday') {
          $cell['class'] .= ' weekend';
        }
        ?>
        <th class="<?php print $cell['class']; ?>" id="<?php print $cell['header_id']; ?>">
          <span class="mobile"><?php print $cell['data']; ?></span>
          <span class="desktop"><?php print $cell['header_id']; ?></span>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <tr class="date-day">
      <?php
        $cell_titles = array();
        $week_day = new DateTime($view->date_info->min_date);
        $week_last_day = new DateTime($view->date_info->max_date);
        $one_day = new DateInterval('P1D');
        $is_current_week = ($week_day <= $today && $today <= $week_last_day);
      ?>
      <?php for ($i = 0; $i < 7; $i++): ?>
      <?php
        $date_day = $week_day->format('j');
        $cell_titles[$i] = strtoupper($week_day->format('D')) . $week_day->format(' M j');

        $cell_class = '';
        if ($is_current_week && $i == $today_day_col) {
          $cell_class = 'today';
        }

        $week_day->add($one_day);
      ?>
      <td class="<?php print $cell_class ?>"><?php print $date_day; ?></td>
      <?php endfor; ?>
    </tr>

    <tr class="first last">
    <?php
    // Custom rewrite for the Calendar module Week view.
    // Combines multi-day & single-day events into one row so they stack the way
    // our use case calls for.
    $day_containers = array();
    foreach ($rows['multiday_buckets'] as $k => $multiday_row) {
      $day_containers[$k] = $multiday_row + $rows['singleday_buckets'][$k];
    }
    ?>
    <?php foreach ($day_containers as $index => $day_container): ?>
      <?php
      $cell_class = ($index == 0 || $index == 6) ? ' weekend' : '';
      if ($is_current_week) {
        $cell_class .= ($today_day_col == $index) ? ' today' : '';
      }
      ?>
      <td class="calendar-agenda-items single-day<?php print $cell_class; ?> " data-title="<?php print $cell_titles[$index]; ?>" headers="<?php print $header_ids[$index] ?>">
        <div class="calendar">

          <?php if (!empty($day_container)): ?>
            <div class="inner">
            <?php foreach ($day_container as $time_str => $items): ?>
              <?php foreach($items as $item): ?>
                <?php print $item['entry'] ?>
              <?php endforeach; ?>
            <?php endforeach; ?>
            </div>
          <?php else: ?>
            <div class="inner no-events">
              <p class="mobile">No Events Scheduled for Today</p>
            </div>
          <?php endif; ?>
        </div>

      </td>
    <?php endforeach; ?>
    </tr>

  </tbody>
</table>
</div></div>
