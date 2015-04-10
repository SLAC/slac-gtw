(function ($) {

Drupal.behaviors.initColorboxDefaultStyle = {
  attach: function (context, settings) {
    $(context).bind('cbox_complete', function () {
      $('#cboxLoadedContent', context).once('cbox_complete', function () {
        if (settings.colorbox.colorbox_original_image === 1) {
          // Remove a previously added download link if it exists.
          if ($('#cboxDownload').length !== 0) {
            $('#cboxDownload').remove();
          }

          // Add the download link if this box has an image.
          if ($('#cboxLoadedContent > img').attr('src')) {
            var fullHref = $('#cboxLoadedContent > img').attr('src').replace(/styles\/large\/public\//,'');
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
          }
          else {
            $('#cboxDownload').remove();
          }
        }
      });
    });
  }
};

})(jQuery);
