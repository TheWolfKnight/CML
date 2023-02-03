#include <string.h>

#define STRING_IMPLIMENTATION
#include "../common.h"
#include "./String.h"

String String_create_string() {
  char buffer[DEFAULT_STRING_SIZE];
  String result = {
    .chars = buffer,
    .length = 0,
    .capacity = DEFAULT_STRING_SIZE
  };
  return result;
}

int String_add_char(String *dest, char c) {
  if (dest->length+1 > dest->capacity)
    String_extend_string_size(dest, dest->capacity+1);
  strcat(dest->chars, &c);
  dest->length++;
  return 1;
}

int String_add_cstr(String *dest, char *s) {
  size_t source_len = strlen(s);
  if (dest->length+source_len > dest->capacity)
    String_extend_string_size(dest, dest->capacity+source_len+1);
  strcat(dest->chars, s);
  dest->length += source_len;
  return 1;
}

int String_pop_char(String *target, char *dest) {
  UNIMPLIMENTED;
}

static int String_extend_string_size(String *target, size_t new_size) {
  char string[new_size];
  size_t final_size;
  for (size_t i = 0; i < new_size; ++i) {
    if (new_size > target->length) {
      final_size = i;
      break;
    }
    string[i] = target->chars[i];
  }
  target->length = final_size;
  return 1;
}
