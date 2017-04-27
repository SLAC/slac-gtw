<?php
/**
 * available variables
 * $features_news		featured news items
 * $news		news items
 */
?>
<?php if (empty($featured_news) && empty($news)): ?>
    <p>This daily email newsletter consists of news and announcements that were published to the SLAC Today home page since the previous day’s newsletter. No news items were published yesterday.</p>
    <p>Please visit the <a href="https://intranet.slac.stanford.edu/">SLAC Today home page</a> to see the lab’s most recent news and information.</p>
    <p>If you would like to submit an announcement to publish in SLAC Today, please visit the <a href="https://intranet.slac.stanford.edu/about-slac-today">About SLAC Today page</a> for guidance. If you would like to suggest a story idea, please fill out our <a href="https://intranet.slac.stanford.edu/suggest-a-story">web form</a> or email <a href="mailto:communications@slac.stanford.edu">Communications</a>.</p>
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