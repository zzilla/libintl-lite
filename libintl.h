/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef LIBINTL_HPP_
#define LIBINTL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Loads a message catalog from a given (GNU-compatible) .mo file.
 * Returns true, if the message catalog was loaded successfully and
 * false otherwise.
 * This function is specific to libintl-lite and serves as a simple
 * replacement for bindtextdomain() function of GNU gettext.
 * This function is NOT thread safe!
 * Pay attention to the thread safety remarks of the gettext() function!
 */
int loadMessageCatalog(const char* domain, const char* moFilePath);

/**
 * Closes a message catalog for the specified domain and releases its obtained resources.
 * This function is NOT thread safe!
 * Pay attention to the thread safety remarks of the gettext() function!
 */
void closeLoadedMessageCatalog(const char* domain);

/**
 * Closes all loaded message catalogs releases their obtained resources.
 * This function is NOT thread safe!
 * Pay attention to the thread safety remarks of the gettext() function!
 */
void closeAllLoadedMessageCatalogs();

/**
 * Sets the default text domain for gettext() / ngettext() calls.
 * This function is NOT thread safe!
 */
const char* textdomain(const char* domain);

/**
 * Returns a pointer to the NULL-terminated string in the loaded for the default
 * message catalog, or origString if origStr is NULL, textdomain() was not called,
 * no message catalog for the specified domain is loaded or no translated message
 * could be found.
 * This function is thread-safe, but loadMessageCatalog(), textdomain(),
 * closeLoadedMessageCatalog() or closeAllLoadedMessageCatalogs()
 * must not be called at the same time! A returned string in the current
 * loaded message catalog will be deleted, if loadMessageCatalog() or
 * closeLoadedMessageCatalog() is called for the used domain afterwards!
 * Does not perform any character set conversion!
 */
const char* gettext(const char* origStr);

/**
 * Works like the gettext() function, but uses the message catalog for a specified domain.
 */
const char* dgettext(const char* domain, const char* origStr);

/**
 * Works like the gettext() function, but distinguishes between singular
 * and plural form of a message.
 * Always returns the suitable singular string, if n == 1, and the plural string
 * otherwise, regardless of the language.
 */
const char* ngettext(const char* origStr, const char* origStrPlural, unsigned long n);

/**
 * Works like the ngettext() function, but uses the message catalog for a specified domain.
 */
const char* dngettext(const char* domain, const char* origStr, const char* origStrPlural, unsigned long n);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LIBINTL_HPP_