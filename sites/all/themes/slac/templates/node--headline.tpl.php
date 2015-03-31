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
      <a href="<?php print $node_url; ?>" class="<?php print $title_attributes; ?>"><?php print $title; ?></a>
<?php endif; ?>
