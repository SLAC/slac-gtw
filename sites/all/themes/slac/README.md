# Front-End Documentation for SlacToday {

* Information on theme and front-end configuration *

## Table of Contents

  1. [Theme’s front-end tools setup](#markdown-header-themes-front-end-tools-setup)

## Theme’s front-end tools setup

SlacToday's Drupal theme can be found under `/docroot/sites/all/themes/slac`.  In here you will find theme's and fron-end confirguations which we will cover in this documentation.

The following configurations and tools are part of the slac theme:

  - [Bundler](http://bundler.io)
  - Ruby Gems: [Sass 3.4.9](http://sass-lang.com/), [Compass 1.0.1](http://compass-style.org/), [Breakpoint 2.5.0](http://breakpoint-sass.com/), [Zen-grids 1.4](http://zengrids.com/), [Toolkit](https://github.com/at-import/toolkit)
  - Javascript

**Bundler**
Bundler provides a consistent environment for Ruby projects by tracking and installing the exact gems and versions that are needed. Using different versions of ruby gems could create Sass compilation errors that could result in your project not properly rendering in the browser.

To install Bundler run `gem install bundler`.  This will make Bundler availabe on any project on your system.

**Sass**
Sass is a preprocessor for writing more efficient and advanced CSS.  Sass provides many advantages over generic CSS that improve the process of writing CSS as well as how your project's stylesheets are organized for a more modular approach to theming.

To install Sass run `gem install sass`.  Sass will then be available to use on any project.

In this project we are using the `.scss` Sass syntax. This means every time you create a new Sass partial it should have the `.scss` extension as oppose to *.sass* or *.css*.

**Compass**
Compass goes hand-and-hand with Sass.  Compass is a css authoring system that allows for compilation of CSS in addition to other advanced tools and mixing we can take advantage of in our Sass files.

**Note**: In this project we do NOT compile CSS using `compass watch`, instead, we use Bundler's `bundle exec compass watch`.  Using Bundler for compiling CSS ensures that our ruby gems are in sync with our Gemfile specifications.

To install Compass run `gem install compass`.  Compass is now available to use on any project.

**Toolkit**
Toolkit a collection of tools we can use on our project.  Some of the tools include clearfix, color mixings, font mixings, etc.

To install Toolkit run `gem install toolkit`.

**Zen Grids**
Zen Grids is the grid system of choice for this project.  This is a dynamic grid that can be used with Sass for layout the structure of our website.

To install zen grids run `gem install zen-grids`.  Once the gem has been installed, you can begin using the grid by importing into your Sass files with `@import "zen";`.

Building your own grid with zen grids is easy, create a new Sass partial (i.e. _grid.scss), and specify your grid's properties:
```
// Set the total number of columns in the grid.
$zen-column-count: 7;

/ Set the gutter size. A half-gutter is used on each side of each column.
$zen-gutter-width: 10px; /

// Apply this mixin to the container.
.container {
 @include zen-grid-container;
}

// Apply this mixin for each grid item in the container.
.aside1 {
 @include zen-grid-item(2, 1);
```

**[⬆ back to top](#markdown-header-table-of-contents)**
