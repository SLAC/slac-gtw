<?php

/**
 * @file
 * SLAC alert template file.
 */
?>

<?php if ($active): ?>
  <div class="slac-alert">
    <?php if ($link): ?>
      <a href="<?php print $link; ?>">
    <?php endif; ?>

    <?php print $body; ?>

    <?php if ($link): ?>
      </a>
    <?php endif; ?>
  </div>
<?php endif; ?>
