#include <stdlib.h>
#include <stdint.h>

#include "../common.h"

#ifndef STRING_H_
#define STRING_H_

#define DEFAULT_STRING_SIZE 32

typedef struct {
  char *string;
  size_t length;
  size_t capacity;
} String;

String String_create_string();
Errno String_add_char(String *dest, char c);
Errno String_add_cstr(String *dest, char *s);
Errno String_pop_char(String *source, char *dest);
Errno String_extend_string_size(String *source, size_t new_size);

#endif // STRING_H
