(function ($) {

Drupal.behaviors.initColorboxDefaultStyle = {
  attach: function (context, settings) {
    $(context).bind('cbox_complete', function () {
      if (settings.colorbox.colorbox_original_image === 1) {
        // Remove a previously added download link if it exists.
        var $cboxDownload = $('#cboxDownload');
        if ($cboxDownload.length !== 0) {
          $cboxDownload.remove();
        }

        // Add the download link if this box has an image.
        var $cboxLoadedContentImg = $('#cboxLoadedContent > img');
        if ($cboxLoadedContentImg.length !== 0 && $cboxLoadedContentImg.attr('src')) {
          var fullHref = $cboxLoadedContentImg.attr('src').replace(/styles\/large\/public\//,'');
          var fullLink = $('<a/>');
          fullLink.attr('href', fullHref);
          fullLink.attr('target', 'new');
          fullLink.attr('title', 'Click to download');
          fullLink.addClass('download_link');
          fullLink.text('Download Image');

          if (typeof fullLink[0].download !== 'undefined') {
            // If the browser supports the A download attr, use that.
            fullLink.attr('download', '');
          }
          else {
            // Fallback/workaround for IE and some other browsers not supporting
            // the download attribute.
            // Change the link to use a custom download handler.
            // See: slac_ip_media.module
            var downloadHref = '/slac/media-download?url=' + fullHref;
            fullLink.attr('href', downloadHref);
          }

          $('#cboxClose').before(fullLink);
          $('.download_link').wrap('<div id="cboxDownload"></div>');

          // Show the #cboxTitle which contins the image caption in case it was
          // previously hidden while showing a video.
          $('#cboxContent #cboxTitle', context).show();
        }
        else {
          // There is no image, remove the download link, if there is one, and
          // remove the #cboxTitle element to it doesn't overly the video
          // caption.

          $cboxDownload.remove();

          $('#cboxContent #cboxTitle', context).hide();
        }
      }
    });
  }
};

}(jQuery));
