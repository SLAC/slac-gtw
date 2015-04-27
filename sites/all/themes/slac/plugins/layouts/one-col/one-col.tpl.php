<?php
/**
 * @file
 * Template for the 2 column panel layout.
 *
 * This template provides a two column ~75%-25% panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 */
?>
<div class="panel-display l-general-one-col clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel main-content">
     <?php if ($content['main_content_column']): ?>
        <div class="inside"><?php print $content['main_content_column']; ?></div>
      <?php endif ?>
  </div>
</div>
