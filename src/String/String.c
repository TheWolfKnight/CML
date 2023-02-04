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

String String_create_string() {
  String result = {0};
  return result;
}

int String_add_char(String *dest, char c) {
  UNIMPLIMENTED;
}

int String_add_cstr(String *dest, char *s) {
  UNIMPLIMENTED;
}

int String_pop_char(String *target, char *dest) {
  UNIMPLIMENTED;
}

int String_extend_string_size(String *dest, size_t new_size) {
  UNIMPLIMENTED;
}
