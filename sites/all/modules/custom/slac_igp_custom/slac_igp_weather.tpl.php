<?php
/**
* This file is not used, it once modified the markup of weather_block.
 * That service was found unreliable.
 * Uncomment it, should it need to be put back
*/
?>
<?php
/**
 * available variables
 * (array) $current       current conditions
 *    condition           current condition
 *    code                weather code
 *    temp                Current temperature
 *    date                date string
 *
 * (array) $forecast      next 3 days forecast
 *    day                 Mon,Tue, etc
 *    date                date string
 *    low                 temperature: low
 *    high                temperature: high
 *    condition           weather condition
 *    code                
 *       
 * (string) $location
 * (string) $icon_path    either default provider path (url) or configured to a files/[path]
 */
?>
<!--
<div class="current">
  <h2><?php //print $location; ?></h2>
  <div class="temp">
    <span class="temp-nr"><?php //print $current['temp']; ?></span>
    <span class="condition"><?php //print $current['condition']; ?></span>
  </div>
  <div class="icon">
    <img title ="<?php //print $current['condition']; ?>" src="<?php //print $icon_path . $current['code']; ?>.<?php //print ($default_icon) ? 'gif' : 'png' ?>" />
  </div>
</div>
<div class="forecast">
  <ul>
  <?php //foreach ($forecast as $day): ?>
    <li>
      <img title ="<?php //print $day['condition']; ?>" src="<?php //print $icon_path . $day['code']; ?>.<?php //print ($default_icon) ? 'gif' : 'png' ?>" />
      <label><span class="day"><?php //print $day['day']; ?></span><span class="hight"><?php //print $day['high'] ?></span> <span class="low"><?php //print $day['low'] ?></span></label>
    </li>
  <?php //endforeach; ?>
  </ul>
  <span class="switch-link"><a href="http://weather.yahoo.com/united-states/california/stanford-2498941" target="_blank">View Detailed Weather Information</a></span>
</div>
-->