<?php
/**
 * available variables
 *
 */
?>
<div id="featured_news">
<?php if (empty($featured_news)): ?>
<h3>There is no new lab or science news today.</h3>
<?php endif; ?>
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