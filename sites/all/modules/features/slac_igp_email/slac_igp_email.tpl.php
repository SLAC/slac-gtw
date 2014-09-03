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
  <br clear="all" />
<?php endforeach; ?>
<?php foreach($news_with_images as $item): ?>
  <div class="item">
    <?php print $item; ?>
  </div>
  <br clear="all" />
<?php endforeach; ?>
</div>

<div id="sub_news">
<?php foreach($news as $item): ?>
    <?php print $item; ?>
<?php endforeach; ?>
</div>