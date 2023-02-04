/*
  Added the string method found in the tsoding repository:
    https://github.com/tsoding/ded
  Please go here to look at his amazing work
*/

#include <stdint.h>
#include <string.h>

#include "../common.h"

#define STRING_IMPLIMENTATION
#include "../common.h"
#include "./String.h"

static void String_extend_string_size(String *dest, size_t new_size) {
  dest->capacity = new_size;
  dest->string = realloc(dest->string, dest->capacity*sizeof(*dest->string));
}

String String_create_string() {
  String result = {0};
  return result;
}

int String_add_char(String *dest, const char c) {
  if (dest->length + 1 > dest->capacity)
    String_extend_string_size(dest, dest->capacity+1);
  dest->string[dest->length++] = c;
  return 1;
}

int String_add_cstr(String *dest, const char *s) {
  size_t len = strlen(s);
  if (dest->length + len > dest->capacity)
    String_extend_string_size(dest, dest->capacity + len);
  memcpy(dest->string + dest->length, s, len*sizeof(*dest->string));
  return 1;
}

int String_pop_char(String *source, char *dest) {
  UNUSED(source);
  UNUSED(dest);
  UNIMPLIMENTED;
}
