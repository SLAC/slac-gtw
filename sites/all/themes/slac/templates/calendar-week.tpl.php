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
$today_day_col = NULL;

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
        $week_day = new DateTime($view->date_info->min_date);
        $one_day = new DateInterval('P1D');
      ?>
      <?php for ($i = 0; $i < 7; $i++): ?>
      <?php
        $date_day = $week_day->format('j');
        $date_diff = $week_day->diff($today);

        if ((int) $date_diff->format('%a') == 0) {
          $cell_class = 'today';
          $today_day_col = $i;
        }
        else {
          $cell_class = '';
        }
        $week_day->add($one_day);
      ?>
      <td class="<?php print $cell_class ?>"><?php print $date_day; ?></td>
      <?php endfor; ?>
    </tr>
    <?php for ($i = 0; $i < $multiday_rows; $i++): ?>
    <?php 
      $colpos = 0; 
      $rowclass = "all-day";
      if( $i == 0) {
        $rowclass .= " first";
      }
      if( $i == $multiday_rows - 1) {
        $rowclass .= " last";
      }
    ?>
    <tr class="<?php print $rowclass?>">
      <?php for($j = 0; $j < 6; $j++): ?>
        <?php $cell = (empty($all_day[$j][$i])) ? NULL : $all_day[$j][$i]; ?>
        <?php if($cell != NULL && $cell['filled'] && $cell['wday'] == $j): ?>
          <?php for($k = $colpos; $k < $cell['wday']; $k++) : ?>
            <?php
              $cell_class = ($k == 0 || $k == 6) ? ' weekend' : '';
              $cell_class .= ($today_day_col == $k) ? ' today' : '';
            ?>
          <td class="multi-day no-entry<?php print $cell_class?>"><div class="inner">&nbsp;</div></td>
          <?php endfor;?>
          <?php
            $cell_class = ($cell['wday'] == 0 || $cell['wday'] == 6) ? ' weekend' : '';

            // Add the Date formatted like 'Thu Apr 16' as a data attribute on
            // each TD.
            $cell_date = $cell['item']->calendar_start_date;
            $cell_title = strtoupper($cell_date->format('D')) . $cell_date->format(' M j');
            $cell_class .= ($today_day_col == $cell['wday']) ? ' today' : '';
          ?>
          <td colspan="<?php print $cell['colspan']?>" data-title="<?php print $cell_title ?>" class="multi-day<?php print $cell_class?>">
            <div class="inner"><?php print $cell['entry']?></div>
          </td>
          <?php $colpos = $cell['wday'] + $cell['colspan']; ?>
        <?php endif; ?>
      <?php endfor; ?>  
      <?php for($j = $colpos; $j < 7; $j++) : ?>
      <?php
        $cell_class = ($j == 0 || $j == 6) ? ' weekend' : '';
        $cell_class .= ($today_day_col == $j) ? ' today' : '';
      ?>
      <td class="multi-day no-entry<?php print $cell_class?>"><div class="inner">&nbsp;</div></td>
      <?php endfor;?>
    </tr>
    <?php endfor; ?>  
    <?php foreach ($items as $time): ?>
    <tr class="not-all-day">
      <?php $curpos = 0; ?>
      <?php foreach ($columns as $index => $column): ?>
        <?php $colpos = (isset($time['values'][$column][0])) ? $time['values'][$column][0]['wday'] : $index; ?>
        <?php for ($i = $curpos; $i < $colpos; $i++): ?>
        <?php
          $cell_class = ($k == 0 || $k == 6) ? ' weekend' : '';
          $cell_class .= ($today_day_col == $j) ? ' today' : '';
        ?>
        <td class="calendar-agenda-items single-day<?php print $cell_class; ?>">
          <div class="calendar">
            <div class="inner">&nbsp</div>
          </div>
        </td>
        <?php endfor; ?>   
        <?php $curpos = $colpos + 1; ?>
        <?php
          $cell_class = ($colpos == 0 || $colpos == 6) ? ' weekend' : '';
        $cell_class .= ($today_day_col == $colpos) ? ' today' : '';
        ?>
        <td class="calendar-agenda-items single-day<?php print $cell_class; ?>" headers="<?php print $header_ids[$index] ?>">
          <div class="calendar">
          <div class="inner">
            <?php if(!empty($time['values'][$column])) :?>
              <?php foreach($time['values'][$column] as $item) :?>
                <?php print $item['entry'] ?>
              <?php endforeach; ?>
            <?php endif; ?>
          </div>
          </div>
        </td>
      <?php endforeach; ?>   
      <?php for ($i = $curpos; $i < 7; $i++): ?>
        <?php
          $cell_class = ($k == 0 || $k == 6) ? ' weekend' : '';
          $cell_class .= ($today_day_col == $j) ? ' today' : '';
        ?>
        <td class="calendar-agenda-items single-day<?php print $cell_class; ?>">
          <div class="calendar">
            <div class="inner">&nbsp</div>
          </div>
        </td>
      <?php endfor; ?>   
    </tr>
   <?php endforeach; ?>   
  </tbody>
</table>
</div></div>
