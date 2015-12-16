libintl lite
============

libintl-lite is a simple (but less powerful) GNU gettext libintl replacement originally written by felixhaedicke and released on SourceForge.net: http://sourceforge.net/projects/libintl-lite/

The library does not depends upon any library except the standard C++ library and the STL, thus making it well suited for platforms like Android.

Where to get help?
===============

Issues should be reported on the project's page on GitHub: https://github.com/j-jorge/libintl-lite

For general questions, send an email to julien.jorge@stuff-o-matic.com.

Legal information
==============

The software is licensed under the version 1 of the Boost Software License.

See the accompanying LICENSE file for details.

Usage
=======

While using this function, remember to call bindtextdomain for as many domains as you want to use in your application.  For example, if I have module1 and module2 as 2 separate domains in the same application, you can do the following:

bindtextdomain("module1", "//path/to/my/locale/folder");

bindtextdomain("module2", "//path/to/my/locale/folder");

textdomain("module1");

echo _("Label1"); // this call will get the message from module1

echo dgettext("module2", "Label1"); // this call will get the message from module2

