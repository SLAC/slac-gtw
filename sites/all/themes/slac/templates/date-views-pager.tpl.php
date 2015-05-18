<?php
/**
 * @file
 * Template file for the example display.
 *
 * Variables available:
 * 
 * $plugin: The pager plugin object. This contains the view.
 *
 * $plugin->view
 *   The view object for this navigation.
 *
 * $nav_title
 *   The formatted title for this view. In the case of block
 *   views, it will be a link to the full view, otherwise it will
 *   be the formatted name of the year, month, day, or week.
 *
 * $prev_url
 * $next_url
 *   Urls for the previous and next calendar pages. The links are
 *   composed in the template to make it easier to change the text,
 *   add images, etc.
 *
 * $prev_options
 * $next_options
 *   Query strings and other options for the links that need to
 *   be used in the l() function, including rel=nofollow.
 */
?>
<?php if (!empty($pager_prefix)) print $pager_prefix; ?>
<div class="date-nav-wrapper clearfix<?php if (!empty($extra_classes)) print $extra_classes; ?>">
  <div class="date-nav item-list">
    <div class="date-heading">
      <h3><?php print $nav_title ?></h3>
    </div>
    <ul class="pager">
    <?php if (!empty($prev_url)) : ?>
      <li class="date-prev">
        <?php print l('&laquo;' . ($mini ? '' : ' ' . t('Prev', array(), array('context' => 'date_nav'))), $prev_url, $prev_options); ?>
      </li>
    <?php endif; ?>
    <?php
    // Set up for 'Today' link.
    $now = new DateTime('now');
    $display_date_arg = $plugin->view->args[0];

    if ($plugin->options['date_id'] == 'month') {
      $is_current = ($now->format('Y-m') == $display_date_arg);
      $today_link = 'calendar/' . $now->format('Y-m');
    }
    elseif ($plugin->options['date_id'] == 'week') {
      $is_current = ($now->format('Y-\WW') == $display_date_arg);
      $today_link = 'calendar/week/' . $now->format('Y-\WW');
    }
    elseif ($plugin->options['date_id'] == 'day') {
      $is_current = ($now->format('Y-m-d') == $display_date_arg);
      $today_link = 'calendar/day/' . $now->format('Y-m-d');
    }
    ?>
    <li class="date-today">
    <?php if ($is_current): ?>
      <span>Today</span>
    <?php else: ?>
      <?php print l(t('Today'), $today_link) ?>
    <?php endif; ?>
    </li>
    <?php if (!empty($next_url)) : ?>
      <li class="date-next">
        <?php print l(($mini ? '' : t('Next', array(), array('context' => 'date_nav')) . ' ') . '&raquo;', $next_url, $next_options); ?>
      </li>
    <?php endif; ?>
    </ul>
  </div>
</div>
