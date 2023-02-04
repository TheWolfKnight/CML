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
int String_add_char(String *dest, const char c);
int String_add_cstr(String *dest, const char *s);
int String_pop_char(String *source, char *dest);

#endif // STRING_H
