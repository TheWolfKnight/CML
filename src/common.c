
#include <stdlib.h>

#define COMMON_IMPLIMENTATION
#include "./common.h"

void substring(int pos, int len, const char *string, char **dest) {
  char substring[SUBSTRING_MAX_LEN];
  for (int i = 0; i < len; ++i) {
    substring[i] = string[pos + i - 1];
  }
  *dest = substring;
}
