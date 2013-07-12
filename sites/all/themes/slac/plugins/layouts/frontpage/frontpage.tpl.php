<?php
/**
 * @file
 * Template for the 1 column panel layout.
 *
 * This template provides a three column 25%-50%-25% panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['middle']: Content in the middle column.
 *   - $content['right']: Content in the right column.
 */
?>
<div class="panel-display panel-frontpage clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  
 

    <div class="frontpage-left-col">

      <?php if ($content['coltworowone']): ?>
        <div class="inside frontpage-links"><?php print $content['coltworowone']; ?></div>
      <?php endif ?>
      <?php if ($content['coltworowtwo']): ?>
        <div class="inside frontpage-calendar"><?php print $content['coltworowtwo']; ?></div>
      <?php endif ?>
      <?php if ($content['coltworowthree']): ?>
        <div class="inside frontpage-access-info"><?php print $content['coltworowthree']; ?></div>
      <?php endif ?>
      <?php if ($content['coltworowfour']): ?>
        <div class="inside frontpage-weather"><?php print $content['coltworowfour']; ?></div>
      <?php endif ?>

    </div>

  <div class="frontpage-right">
   
    <div class="frontpage-middle-col">

      <?php if ($content['colonerowone']): ?>
        <div class="inside frontpage-news-slider"><?php print $content['colonerowone']; ?></div>
      <?php endif ?>
      <?php if ($content['colonerowtwo']): ?>
        <div class="inside frontpage-news-list"><?php print $content['colonerowtwo']; ?></div>
      <?php endif ?>
      <?php if ($content['colonerowthree']): ?>
        <div class="inside frontpage-slac-science"><?php print $content['colonerowthree']; ?></div>
      <?php endif ?>
      
    </div>

    <div class="frontpage-right-col">

      <?php if ($content['colthreerowone']): ?>
        <div class="inside frontpage-people-finder"><?php print $content['colthreerowone']; ?></div>
      <?php endif ?>
      <?php if ($content['colthreerowtwo']): ?>
        <div class="inside frontpage-top-links"><?php print $content['colthreerowtwo']; ?></div>
      <?php endif ?>
      <?php if ($content['colthreerowthree']): ?>
        <div class="inside frontpage-projects"><?php print $content['colthreerowthree']; ?></div>
      <?php endif ?>
      <?php if ($content['colthreerowfour']): ?>
        <div class="inside frontpage-directorate-links"><?php print $content['colthreerowfour']; ?></div>
      <?php endif ?>
      <?php if ($content['colthreerowfive']): ?>
        <div class="inside frontpage-help-market"><?php print $content['colthreerowfive']; ?></div>
      <?php endif ?>
      <?php if ($content['colthreerowsix']): ?>
        <div class="inside frontpage-security-contacts"><?php print $content['colthreerowsix']; ?></div>
      <?php endif ?>
    </div>
  </div>
  
</div>


