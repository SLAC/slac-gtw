<?php
/**
 * available variables
 * $features_news		featured news items
 * $news		news items
 */
?>
<?php if (empty($featured_news) && empty($news)): ?>
    <p>No news items were published yesterday.</p>

    <hr />
    <p><span style="font-size:12px"><em>This daily email newsletter consists of news and announcements that were published to the SLAC Today home page since the previous day&rsquo;s newsletter.</em></span></p>

    <p><span style="font-size:12px"><em>Please visit the <a href="https://intranet.slac.stanford.edu/">SLAC Today home page</a> to see the lab&rsquo;s most recent news and information.</em></span></p>

    <p><span style="font-size:12px"><em>If you would like to submit an announcement to publish in SLAC Today, please visit the <a href="https://intranet.slac.stanford.edu/about-slac-today">About SLAC Today page</a> for guidance. If you would like to suggest a story idea, please fill out our <a href="https://intranet.slac.stanford.edu/suggest-a-story">web form</a> or email <a href="mailto:communications@slac.stanford.edu">Communications</a>.</em></span></p>
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