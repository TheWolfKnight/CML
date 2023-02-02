
#ifndef STRING_H_
#define STRING_H_

typedef struct {
  char *chars;
  size_t size;
  size_t capacity;
} String;

String String_create_string();
int String_add_char(String *dest, char c);
int String_add_cstr(String *dest, char *s);
char *String_pop_char(String *target);
static int String_extend_string_size(String *target, size_t new_size);

#endif // STRING_H
