(function ($) {

Drupal.behaviors.initColorboxDefaultStyle = {
  attach: function (context, settings) {
    $(context).bind('cbox_complete', function () {
      var colorbox_original_image = Drupal.settings.colorbox.colorbox_original_image;
      if(colorbox_original_image == '1') {
        function addLink() {
          if ($('#cboxDownload').length) {
            $('#cboxDownload').remove();
          }
          var fullHref = $('#cboxLoadedContent > img').attr('src').replace(/styles\/large\/public\//,'');
          var fullLink = $('<a/>');
          fullLink.attr('href', fullHref);
          fullLink.attr('target', 'new');
          fullLink.attr('title', 'Right click to download');
          fullLink.addClass("download_link");
          fullLink.text('Download Image');
          $('#cboxClose').before(fullLink);
          $('.download_link').wrap('<div id="cboxDownload"></div>');
        }

        if ($('#cboxLoadedContent > img').attr('src')) {
          addLink();
        } else {
          if ($('#cboxDownload').length) {
            $('#cboxDownload').remove();
          }
        }
      }
    });
  }
};

})(jQuery);
