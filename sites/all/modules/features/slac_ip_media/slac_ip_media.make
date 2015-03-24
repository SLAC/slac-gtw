; SLAC - Media related modules

core = 7.x
api  = 2

projects[file_entity][version] = 2.x-dev
projects[file_entity][subdir] = contrib
projects[file_entity][download][type] = git
projects[file_entity][download][revision] = 20f3070
projects[file_entity][download][branch] = 7.x-2.x

projects[media][version] = 2.x-dev
projects[media][subdir] = contrib
projects[media][download][type] = git
projects[media][download][revision] = 6382429
projects[media][download][branch] = 7.x-2.x
projects[media][patch][2192981] = http://drupal.org/files/issues/media-restore-edit-button-2192981-13.patch
projects[media][patch][2126697] = http://drupal.org/files/issues/media-wysiwyg-alt-title-handling-2126697-27.patch
projects[media][patch][2308487] = http://drupal.org/files/issues/media-alt-title-double-encoded-2308487-1.patch

projects[media_youtube][version] = 2.x-dev
projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][revision] = d0377b3
projects[media_youtube][download][branch] = 7.x-2.x

projects[media_vimeo][version] = 2.0
projects[media_vimeo][subdir] = contrib
projects[media_vimeo][patch][2446199] = https://www.drupal.org/files/issues/no_exception_handling-2446199-1.patch

