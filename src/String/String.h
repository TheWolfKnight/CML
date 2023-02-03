#include <stdlib.h>
#include <stdint.h>

#ifndef STRING_H_
#define STRING_H_

#define DEFAULT_STRING_SIZE 32

typedef struct {
  uint8_t chars;
  size_t length;
  size_t capacity;
} String;

String String_create_string();
int String_add_char(String *dest, char c);
int String_add_cstr(String *dest, char *s);
int String_pop_char(String *target, char *dest);
int String_extend_string_size(String *target, size_t new_size);

#endif // STRING_H
