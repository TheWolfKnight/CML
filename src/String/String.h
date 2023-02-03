#include <stdlib.h>

#ifndef STRING_H_
#define STRING_H_

#define DEFAULT_STRING_SIZE 32

typedef struct {
  char *chars;
  size_t length;
  size_t capacity;
} String;

String String_create_string();
int String_add_char(String *dest, char c);
int String_add_cstr(String *dest, char *s);
int String_pop_char(String *target, char *dest);
static int String_extend_string_size(String *target, size_t new_size);

#endif // STRING_H
