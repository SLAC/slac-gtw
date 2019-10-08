<?php

/**
 * @file
 * Default template for wrapping bar results - includes count of votes.
 *
 * Variables available:
 * - $nid: The nid of the poll
 * - $cancel_form: Provides a form for deleting user's votes when they have
 *   permission to do so.
 * - $bars: The output of all styled bars displaying votes.
 * - $total: Total number of votes.
 * - $voted: An array indicating which unique choice ids were selected by the
 *   user.
 */
?>
<div class="poll" id="advpoll-<?php print $nid; ?>">

    <?php print $bars; ?>
    <div class="poll-bar">
  		<div class="text"><?php print 'Other'; ?></div>
  		<div class="bar">
    		<div style="width: <?php print $writein_percentage; ?>%;" class="foreground"></div>
  		</div>
  		<div class="percent">
    		<?php print $writein_percentage; ?>% (<?php print format_plural($writein_total, '1 vote', '@count votes'); ?>)
  		</div>
	</div>
    <div class="total"><?php print t('Total votes: @total', array('@total' => $total)); ?></div>

    <?php print $cancel_form; ?>
</div>
