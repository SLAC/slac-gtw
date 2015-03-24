<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<?php if (!$page && $title): ?>
    <?php print render($title_prefix); ?>
      <h3<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
    <?php print render($title_suffix); ?>
    <?php if ($unpublished): ?>
      <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
    <?php endif; ?>
<?php endif; ?>
