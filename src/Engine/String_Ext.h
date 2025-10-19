#if !defined(String_Ext)
#define String_Ext

#include <stdio.h>
#include <stdlib.h>

//@file String_Ext.h
//@brief Custom string utilities for C (no std::string needed).
//@details
//  Provides helper functions for working with null-terminated strings
//  (`char*`) and arrays of strings.  
//  Includes functions for measuring length, finding characters,
//  splitting strings, changing case, and extracting substrings.
//
//  NOTE: All dynamically allocated memory returned by these functions
//  must be freed by the caller using `free()` or `Strings_DFree()`.

/**
 * @brief Get the length of a string (number of characters before '\0').
 * @param buffer The input C string.
 * @return The number of characters (not counting the null terminator).
 */
int String_GetLen(const char* buffer);

/**
 * @brief Find the first occurrence of a character in a string.
 * @param buffer The input C string to search.
 * @param chc The character to find.
 * @return The index (0-based) of the character, or -1 if not found.
 */
int String_FindChar(const char* buffer, char chc);

/**
 * @brief Extract a substring between two characters.
 * @param buffer The input C string.
 * @param starting The starting character (inclusive).
 * @param ending The ending character (inclusive).
 * @return A newly allocated substring, or NULL if invalid.
 * @note The caller must free the returned string using `free()`.
 */
char* String_SubStr(const char* buffer, char starting, char ending);

/**
 * @brief Create a new string converted to uppercase.
 * @param buffer The input C string.
 * @return A newly allocated uppercase copy of the string.
 * @note The caller must free the returned string using `free()`.
 */
char* String_ToUpperCased(const char* buffer);

/**
 * @brief Create a new string converted to lowercase.
 * @param buffer The input C string.
 * @return A newly allocated lowercase copy of the string.
 * @note The caller must free the returned string using `free()`.
 */
char* String_ToLowerCased(const char* buffer);

//@struct Strings
//@brief A dynamic array of strings (char**).
//@details Used by functions like `String_split()` to hold multiple substrings.
struct Strings {
    char** data;
    int num;
};

/**
 * @brief Split a string into parts separated by a given delimiter.
 * @param buffer The input C string to split.
 * @param delim The delimiter character.
 * @return A `struct Strings` containing dynamically allocated substrings.
 * @note Use `Strings_DFree()` to free the result properly.
 */
struct Strings String_split(const char* buffer, char delim);

/**
 * @brief Free all memory allocated by a `struct Strings` instance.
 * @param strs Pointer to the `struct Strings` to free.
 * @note Frees each string and the array itself.  
 *       After freeing, `strs->data` is set to NULL and `strs->num` to 0.
 */
void Strings_DFree(struct Strings* strs);

#endif // String_Ext
