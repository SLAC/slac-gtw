<?php
/**
 * available variables
 * $features_news		featured news items
 * $news		news items
 */
?>
<?php if (empty($featured_news) && empty($news)): ?>
<span>No announcements were added to SLAC Today yesterday. Please visit the SLAC Today home page to see the lab's most recent news and updates.</span>
<?php endif; ?>
<div id="featured_news">
<?php foreach($featured_news as $featured): ?>
  <div class="item">
    <?php print $featured; ?>
  </div>
  <br clear="all" />
<?php endforeach; ?>
</div>

<div id="sub_news">
<?php foreach($news as $_news): ?>
    <?php print $_news; ?>
<?php endforeach; ?>
</div>