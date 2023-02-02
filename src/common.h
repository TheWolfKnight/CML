
#include <stdio.h>
#include <errno.h>

#ifndef COMMON_H_
#define COMMON_H_

typedef int Errno;

#define UNIMPLEMENTED                  \
  do {                                 \
    printf("%s:%d: UNIMPLEMENTED %s\n",\
            __FILE__,                  \
            __LINE__,                  \
            __func__);                 \
    exit(1);                           \
  } while (0)

#define UNRECHABLE                     \
  do {                                 \
    printf("%s:%d: UNRECHABLE: %s\n",  \
            __FILE__,                  \
            __LINE__,                  \
            __func__);                 \
    exit(1);                           \
  } while (0);

#define TODO                           \
  do {                                 \
    printf("%s:%d: TODO: %s\n",        \
            __FILE__,                  \
            __LINE__,                  \
            __func__);                 \
    exit(1);                           \
  } while (0)

#define UNUSED(var) (void) var

#endif // COMMON_H_
