# Front-End Documentation for Slac Today

* Information on theme and front-end configuration *

## Table of Contents

  1. [Theme’s front-end tools setup](#markdown-header-themes-front-end-tools-setup)
  2. [Watching for Sass changes](#markdown-header-watching-for-sass-changes)
  3. [Theme's structure and organization](#markdown-header-themes-structure-and-organization)
  4. [Grid and Layout](#markdown-header-grid-and-layout)
  5. [Responsive Design](#markdown-header-responsive-design)
  6. [Events Calendar](#markdown-header-events-calendar)
  7. [Event nodes color coding](#markdown-header-event-nodes-color-coding)
  8. [Color box theming](#markdown-header-color-box)

## Theme’s front-end tools setup

Slac Today's Drupal theme can be found under `/docroot/sites/all/themes/slac`.  In here you will find theme's and front-end configurations which we will cover in this documentation.


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
.aside {
  @include zen-grid-item(2, 1);
 }
```

**[⬆ back to top](#markdown-header-table-of-contents)**


A more efficient way for ensuring all ruby gems are up to date is to include them in a Gemfile which bundler would look at to ensure consistency.  This is an example of the Gemfile used on this project:
```
source 'https://rubygems.org'

group :development do

  # Sass, Compass and extensions.
  gem 'sass', '3.4.9'           # Sass.
  gem 'compass', '1.0.1'        # Framework built on Sass.
  gem 'toolkit'                 # Toolkit utility from Snugug.
  gem 'breakpoint', '2.5.0'     # Manages CSS media queries.
  gem 'zen-grids', '1.4'        # Zen-Grids gem.

end
```

The Gemfile is saved in the root location of your theme `(i.e. /docroot/sites/all/themes/slac/Gemfile)

Once your Gemfile is in place, you need to navigate to your theme's location (i.e. /docroot/sites/all/themes/slac/), and run `bundle install`.  Bundler will read your Gemfile and ensure the ruby versions specified in it are installed for this project.  Ruby versions can vary from project to project and that's another advantage of using Bundler as it will always ensure the right versions are installed on your project based on what is found in your Gemfile.

**[⬆ back to top](#markdown-header-table-of-contents)**

## Watching for Sass changes

Once your gems are in place by either of the methods above, you can start watching for Sass changes.

  - Navigate to your theme's location (i.e. /docroot/sites/all/themes/slac/)

  - run `bundle exec compass watch`

Using Bundler for compiling CSS ensures that our ruby gems are in sync with our Gemfile specifications.


## Theme's structure and organization

Thanks to Sass we can provide better structure and organization of our theme's stylesheets.  By modulizing as many of the site's elements as possible, we are able to create individual Sass partials that are easy to maintain in the long run.

The slac theme is currently structured as follows:

```
css/
images/
js/
sass/
|
|– base/
|   |– _base.scss
|   |– _colors.scss
|   |- _quotes.scss
|   |- _tables.scss
|   |- _typography.scss
|
|– components/
|   |- _access-notice-listings.scss
|   |- _author.scss
|   |– _buttons.scss
|   |- _calendar-events-by-color.scss
|   |- _calendar-filters-dropdown.scss
|   |- _calendar-mobile.scss
|   |- _calendar-overlap.scss
|   |- _calendar.scss
|   |- _captions.scss
|   |- _collapsible-content.scss
|   |- _date.scss
|   |- _event-news-access-notice-mobile.scss
|   |- _event-news-access-notice.scss
|   |- _events-legend.scss
|   |- _featured-news.scss
|   |- _feed-icon.scss
|   |- _feedback.scss
|   |- _flag.scss
|   |- _flea-market.scss
|   |- _footer.scss
|   |- _form-components.scss
|   |- _frontpage-access-information.scss
|   |- _frontpage-content-blocks.scss
|   |- _frontpage-gold-headings.scss
|   |- _frontpage-help-market-security-contacts.scss
|   |- _frontpage-lab-news.scss
|   |- _frontpage-lists.scss
|   |- _frontpage-people-finder.scss
|   |- _frontpage-slac-projects.scss
|   |- _frontpage-slac-science.scss
|   |- _frontpage-slider.scss
|   |- _frontpage-social-icons.scss
|   |- _frontpage-upcoming-events.scss
|   |- _frontpage-views-footer.scss
|   |- _frontpage.scss
|   |- _header.scss
|   |- _icons.scss
|   |- _listing-blocks.scss
|   |- _lists.scss
|   |- _my-content.scss
|   |- _navigation.scss
|   |- _news-archives.scss
|   |- _page-icons.scss
|   |- _pager.scss
|   |- _scroll-to-top.scss
|   |– _search.scss
|   |- _sidebar.scss
|   |- _taxonomy-listing.scss
|
|– layout/
|   |– _layout.scss
|
|– utilities/
|   |– _breakpoints.scss
|   |– _events-color-codes.scss
|   |– _mixins.scss
|
|- main.scss
|
```
**base/**: The base directory is intended to hold partials that address styles at a very high level.  Elements addressed in the base directory normally don't have IDs or classes associated with them.

**components/**: Also known as modules, this directory contains partials reserved for reusable UI patterns. A general rule of thumb, anytime you find yourself needing the same CSS more than once, you should modularize it. As your project matures, you should be able to compartmentalize more CSS into modules.

**layout/**:  Partials in this directory target the layout or structure of your theme’s regions.  Definitions for regions' widths or how many grid columns a particular region spans.

**utilities/**: Mixins, variables, breakpoints and functions are usually found in this directory in addition to other custom or third party utilities.

**main.scss**: This partial's only function is to compile a list of all other partials to be imported into the project.  Instead of writing `@import` statements in different partials, combining all partials in the order they are required for the project to run properly makes more sense.


**[⬆ back to top](#markdown-header-table-of-contents)**

## Grid and layout

The site's grid is configured to use 12 columns.  The site's layout structure is defined in `/sass/layouts/_layout.scss` as follows:
```css
.l-main {
  @include zen-grid-item(12, 1);
  max-width: 1432px;
  padding-top: 37px;

  @include breakpoint($tablet-large) {
    padding-top: 47px;

    .page-calendar & {
      padding-top: 0;
    }
  }
}
```

  - `@include zen-grid-item(12, 1)`: Grid spans 12 columns starting on column 1.
  - `max-width: 1432px`: The site's width should not exceed 1432px.
  - `padding-top: 37px`: provides default padding for all pages on mobile.  This increases to 47px on large screens.
  - The dimensions above apply to all device sizes from smartphones to desktops.

The homepage is broken down in three columns:
```
.front-main-column
.front-first-column
.front-last-column
```
`.front-main-column` is about 42% the width of the site’s container (.l-main)
`.front-first-column` is 25%
`.front-last-column` is 33%


Pages that are broken down in two columns look like this:
```
.general-left
.general-right
```
`.general-left` is about 58% the width of the site’s container (.l-main)
`.general-right` is 25%




The two column layout spans 10 columns out of the grid’s 12 starting on column 2.



One column pages:
`.l-general-one-col` at 83% the width of .l-main.  As with the two column layout, the one column layout also spans for 10 columns out the grid's 12 starting at column 2.

All pages default to 1 column at 100% width on mobile devices with 20px of padding on left and right.


**[⬆ back to top](#markdown-header-table-of-contents)**


## Responsive Design

Responsive design was accomplished by taking advantage of Zen grids, Breakpoint and Sass.
All pages default to a single column or 100% in width on mobile devices.  As the device's increase in size (tablets), the site's structure changes to multiple columns allowing for better content placements.  This process continues all the way to large desktop.  At its widest, the site is rearranged into three columns (i.e. homepage).  Most other pages retain a two column layout (.general-left and .general-right).
Other unique pages such as listing pages, calendar and search results stay at
a single column expanding to about 83% of the site's width.

In addition to traditional pages, several tables throughout the site were transformed into [responsive tables](http://blog.apps.npr.org/2014/05/09/responsive-data-tables.html).  Tables such as My Content and Calendar provide a better user experience in mobile.

The following breakpoints were created to handle the different layouts on different devices:
```
$mobile: 20em; // 320px
$tablet-small: 40em; // 640px
$tablet-large: 60em; // 960px
$desktop: 70em; // 1120px
$huge: 80em; // 1280px
$calendar-full: 85em; //1337px
$extra-large: 92.50em; // 1480px
```

Internet Explorer (IE), 10 and 11 no longer support conditional html comments (i.e. `<!--[if IE 9]><html class="lte-ie9"><![endif]-->`).  We used a special media query to conditional target IE 10+.:
```
@media all and (-ms-high-contrast: none), (-ms-high-contrast: active) {
  // IE10+ CSS here
}
```

All font sizes are declared using REMs with Pixels fallback and we used percentages for widths as much as we could to provide a great and fluid user experience.

Image and media resizing is currently being handled by using the famous css rule:
```css
img,
embed,
iframe,
object,
video {
  max-width: 100%;
  height: auto;
}
```

**[⬆ back to top](#markdown-header-table-of-contents)**


## Events Calendar

The events calendar located under _/calendar_ presented many development and theming challenges because of complexity of calendars in general.

Events are color-coded based on their type.  For this we created a simply color map to be used on each event.  Event types are applied through a taxonomy terms.  By appending the taxonomy machine name to each event as a css class we are able to target the color-coding with Sass.

The color map can be found under `/sass/utilities/_events-color-codes.scss` and it looks like this:
```sass
$color: (
  red: #de0105,
  red-light: #fce9e9,

  blue: #4780d1,
  blue-light: #e6eef9,

  green: #35b635,
  green-light: #d0eed0,

  purple: #7e00aa,
  purple-light: #eddaf3,

  pink: #ff2eba,
  pink-light: #f9e1f2,

  yellow: #e9ce43,
  yellow-light: #fff8df,

  orange: #e76d00,
  orange-light: #fae2cc,

  grey: #838383,
  grey-light: #c8cac8,

  grey-blue: #d5dde1,
  grey-blue-light: #eaeef0,
  grey-blue-dark: #849ba6,
  light-green: #eff9f5,
  light-blue: #dfe9f5,
  weekend-grey: #eeeeee,
  event-item-grey: #e4e4e4,
  event-time-grey: #252525,
  event-description-grey: #3d3d3d
);
```

Through the use of a Sass function, we've built some logic and
validation for when colors are used:
```sass
// color function
@function color($key) {
  @if map-has-key($color, $key) {
    @return map-get($color, $key);
  }

  @warn "This `#{$key}` is not in the $color map.";
  @return null;
}
```

Finally, to apply a color to an element or selector we do as follows:
```css
.selector__name {
  color: color(pink);
  background-color: color(purple);
}
```

### Applying color to events by type ###

Since calendar events color-code would be consistent across the site and in all device sizes, we gathered all rules for applying color to events into a single Sass partial, which can be found under `/sass/components/_calendar-events-by-color.scss`.

First we created a general rule that would apply to all events:
```
.type-access_information,
.type-event {
  background: color(event-item-grey);
  margin: 0.2rem 0 0.5rem 0;
  padding: 0.2rem 0.4rem;
  border-left: 4px solid color(grey);
```
Events container fall in one of two types: _access_information_ and _type-event_.

In the rule above we are applying a general grey background as well as a 4px border to all events.

Next, we get more specific about each event type:
```
  &.event-summer-school-programs {
    border-color: color(pink);
  }

  &.event-talks-seminars--colloquia {
    border-color: color(yellow);
  }

  &.event-public-events--tours {
    border-color: color(green);
  }

  &.event-conferences--workshops {
    border-color: color(blue);
  }

  &.event-staff-celebrations {
    border-color: color(purple);
  }

  &.event-training--development {
    border-color: color(orange);
  }

  &.type-access_information {
    border-color: color(red);
    background: color(event-item-grey) url(../images/access-notice-icon-smaller.png) 5px 3px no-repeat;
  }
}
```
The code above targets the event's border color and assigns a background image to the access_information events as they do not use the same theming as all other events.

We are not changing the event background color found behind the event time filed because the background position changes based on the calendar view and the device breakpoints.  We do that individually as we theme each specific view at different breakpoints.

Important to note, if a new event type is added to the list of existing event types, the easiest way to ensure the color-coding approached shown above is followed would be to:

1. Add your color variable to the color map
2. Obtain the event's taxonomy term machine name
3. Add the taxonomy term machine name as a css class as shown above to the list of other event's css classes. This should allow for that new event to be properly color-coded across the calendar.


**Note**
  >  The above color map can be used on any selector and it's not exclusive to the calendar.  However as of now the calendar is where it's being more widely used.

***

As far as responsive theming for calendar, we used the same technique as we've done on tables.  After all, most of the calendar is built using tables.

**[⬆ back to top](#markdown-header-table-of-contents)**


## Event nodes color coding ##

Similarly to color coding calendar events, applying the right color code to event nodes can be accomplished by first adding a new event type taxonomy term to the Event Type vocabulary.

When an event is created using the newly added event type term, its machine name will be added as a CSS class to the node's event type field.  You can then use this CSS class to apply the right color code to that event type.

  1. Edit `/utilities/_events-color-codes.scss` and add your new color code
  2. Edit `/components/_page-icons.scss` and add the new CSS class generated from the taxonomy term.  Be sure to use the same format as the other events in the list (i.e. `&.new-css-class:before`)
  3. Add a background property with the corresponding color added in step one above.

  **[⬆ back to top](#markdown-header-table-of-contents)**

## Color box theming ##

The default styling and functionality of the colorbox js plugin and module is being overridded with a custom style in the slac_colorbox directory in this theme. Changes should be made there if required.

  **[⬆ back to top](#markdown-header-table-of-contents)**
