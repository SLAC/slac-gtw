<?php
/**
 * available variables
 * $features_news		featured news items
 * $news		news items
 */
?>
<?php if (empty($featured_news) && empty($news)): ?>
<h3>No new lab or science news today</h3>
<?php endif; ?>
<div id="featured_news">
<?php foreach($featured_news as $featured): ?>
  <div class="item">
    <?php print $featured; ?>
  </div>
<?php endforeach; ?>
</div>

<div id="sub_news">
<?php foreach($news as $_news): ?>
    <?php print $_news; ?>
<?php endforeach; ?>
</div>