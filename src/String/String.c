#include <string.h>

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

char *String_pop_char(String *target) {
  UNIMPLIMENTED;
}

static int String_extend_string_size(String *target, size_t new_size) {
  UNIMPLIMENTED;
}
