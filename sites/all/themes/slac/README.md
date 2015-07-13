# Front-End Documentation for SlacToday

* Information on theme and front-end configuration *

## Table of Contents

  1. [Theme’s front-end tools setup](#markdown-header-themes-front-end-tools-setup)
  1. [Watching for Sass changes](#markdown-header-watching-for-sass-changes)

## Theme’s front-end tools setup

SlacToday's Drupal theme can be found under `/docroot/sites/all/themes/slac`.  In here you will find theme's and fron-end confirguations which we will cover in this documentation.


The following ruby gems are part of this theme:

  [Bundler](http://bundler.io), [Sass 3.4.9](http://sass-lang.com/), [Compass 1.0.1](http://compass-style.org/), [Breakpoint 2.5.0](http://breakpoint-sass.com/), [Zen-grids 1.4](http://zengrids.com/), [Toolkit](https://github.com/at-import/toolkit)

Each gems above can be installed by running `gem install gem-name` (i.e. `gem install sass`, `gem install bundler`, etc.)



  - **Bundler**
Bundler provides a consistent environment for Ruby projects by tracking and installing the exact gems and versions that are needed. Using different versions of ruby gems could create Sass compilation errors that could result in your project not properly rendering in the browser.



  - **Sass**
Sass is a preprocessor for writing more efficient and advanced CSS.  Sass provides many advantages over generic CSS that improves the process of writing CSS as well as how your project's stylesheets are organized for a more modular approach to theming.



  - **Compass**
Compass goes hand-in-hand with Sass.  Compass is a css authoring system that allows for compilation of CSS in addition to other advanced tools and mixing we can take advantage of in our Sass files.



  - **Toolkit**
Toolkit a collection of tools we can use on our project.  Some of the tools include clearfix, color mixings, font mixings, etc.



  - **Zen Grids**
Zen Grids is the grid system of choice for this project.  This is a dynamic grid that can be used with Sass for layout the structure of our website.



  - Building your own grid with zen grids is easy, create a new Sass partial (i.e. _grid.scss), and specify your grid's properties:
```
// Set the total number of columns in the grid.
$zen-column-count: 7;

// Set the gutter size. A half-gutter is used on each side of each column.
$zen-gutter-width: 10px;

// Apply this mixin to the container.
.container {
 @include zen-grid-container;
}

// Apply this mixin for each grid item in the container.
.aside1 {
 @include zen-grid-item(2, 1);
```

**[⬆ back to top](#markdown-header-table-of-contents)**


A more efficient way for ensuring all ruby gems are up to date is to include them in a Gemfile which bundler would look at to ensure consistency.  This is an example of the Gemfile used on this project:
```
source 'https://rubygems.org'

group :development do

  # Sass, Compass and extensions.
  gem 'sass', '3.4.9'           # Sass.
  gem 'compass', '1.0.1'        # Framework built on Sass.
  gem 'toolkit'                 # Compass utility from the fabulous Snugug.
  gem 'breakpoint', '2.5.0'     # Manages CSS media queries.
  gem 'zen-grids', '1.4'        # Zen-Grids gem.

end
```

The Gemfile is saved in the root location of your theme `(i.e. /docroot/sites/all/themes/slac/Gemfile)

Once your gemfile is in place, you need to navigate to your theme's location (i.e. /docroot/sites/all/themes/slac/), and run `bundle install`.  Bundler will read your Gemfile and ensure the ruby versions specified in it are installed for this project.  Ruby versions can vary from project to project and that's another advantage of using Bundler as it will always ensure the right versions are installed on yoru project based on what is found in your Gemfile.

**[⬆ back to top](#markdown-header-table-of-contents)**

## Watching for Sass changes

Once your gems are in place by either of the methods above, you can start watching for Sass changes.

  - Navigate to your theme's location (i.e. /docroot/sites/all/themes/slac/)

  - run `bundle exec compass watch`

Using Bundler for compiling CSS ensures that our ruby gems are in sync with our Gemfile specifications.



