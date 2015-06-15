<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title && !$content['title']): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>

      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);

    // Hide the date and location fields so they can be rendered wrapped along
    // with our custom calendar link icon.
    hide($content['field_event_date']);
    hide($content['field_shared_location']);
    print render($content);
  ?>

  <div class="access-notice-date">
    <?php print render($content['field_event_date']); ?>
      <a href="/node/<?php print $node->nid; ?>/ical" title="Add to your Calendar"><img src="/sites/all/themes/slac/images/calendar-icon-gray.png">Add to your Calendar</a>
  </div>

  <?php print render($content['field_shared_location']); ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>
</article>
