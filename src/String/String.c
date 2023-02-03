#include <stdint.h>
#include <string.h>

#define STRING_IMPLIMENTATION
#include "../common.h"
#include "./String.h"

String String_create_string() {
  uint8_t *buffer = malloc(sizeof(char) * DEFAULT_STRING_SIZE);
  String result = {
    .chars = *buffer,
    .length = 0,
    .capacity = DEFAULT_STRING_SIZE,
  };
  return result;
}

int String_add_char(String *dest, char c) {
  if (dest->length+1 >= dest->capacity) {
    puts("Here");
    String_extend_string_size(dest, dest->capacity+1);
  }
  dest->chars[dest->length] = c;
  dest->length++;
  return 1;
}

int String_add_cstr(String *dest, char *s) {
  size_t source_len = strlen(s);
  if (dest->length+source_len > dest->capacity)
    String_extend_string_size(dest, dest->capacity+source_len+1);
  for (int i = 0; dest->length < source_len; ++i, ++dest->length)
    dest->chars[dest->length] = s[i];
  return 1;
}

int String_pop_char(String *target, char *dest) {
  UNIMPLIMENTED;
}

int String_extend_string_size(String *dest, size_t new_size) {
  uint8_t *new_string = malloc(sizeof(char) * new_size + 1);

  for (int i = 0; i < new_size; ++i) {
    new_string[i] = dest->chars[i];
  }
  free(dest->chars);
  dest->chars = new_string;
  return 1;
}
