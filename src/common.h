
#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifndef COMMON_H_
#define COMMON_H_

typedef int Errno;
typedef int Bool;

#define UNIMPLIMENTED                    \
  do {                                   \
    printf("\n%s:%d: UNIMPLIMENTED %s\n",\
            __FILE__,                    \
            __LINE__,                    \
            __func__);                   \
    exit(1);                             \
  } while (0);

#define UNRECHABLE                     \
  do {                                 \
    printf("\n%s:%d: UNRECHABLE: %s\n",\
            __FILE__,                  \
            __LINE__,                  \
            __func__);                 \
    exit(1);                           \
  } while (0);

#define TODO                           \
  do {                                 \
    printf("\n%s:%d: TODO: %s\n",      \
            __FILE__,                  \
            __LINE__,                  \
            __func__);                 \
    exit(1);                           \
  } while (0);

#define UNUSED(...) (void) __VA_ARGS__;

#define ERR_PRINT(str, ...)               \
  do {                                    \
      char buf[512];                      \
      strcat(buf, "\n");                  \
      strcat(buf, str);                   \
      fprintf(stderr, buf, __VA_ARGS__);  \
  } while (0);

#define SUBSTRING_MAX_LEN 1024
void substring(int pos, int len, const char *string, char **dest);

#endif // COMMON_H_
