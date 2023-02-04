#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../common.h"
#include "../String/String.h"

#include "fs.h"
#define FS_IMPLEMENTATION


Errno file_size(FILE *fptr, size_t *dest) {
  long saved = ftell(fptr);
  if (saved < 0 || fseek(fptr, 0, SEEK_END) < 0) return errno;
  long result = ftell(fptr);
  if (result < 0 || fseek(fptr, saved, SEEK_SET) < 0) return errno;

  *dest = (size_t)result;

  return 1;
}

Errno read_entire_file(String *dest, const char *file_path) {
  FILE *fptr;
  fptr = fopen(file_path, "r");

  if (fptr == NULL) {
    ERR_PRINT("[ERROR] Could not load the given file %s, %s\n", file_path, strerror(errno));
    fclose(fptr);
    return 0;
  }
  size_t fsize;
  Errno err = file_size(fptr, &fsize);
  if (err != 0) {
    ERR_PRINT("[ERROR] Could not read the file size, for the given file %s, %s\n", file_path, strerror(errno));
    fclose(fptr);
    return 0;
  }

  if (dest->capacity < fsize) {
    dest->capacity = fsize;
    dest->string = realloc(dest->string, dest->capacity*sizeof(*dest->string));
    assert(dest->string != NULL && "The program has run out of memory, please allocate more RAM");
  }

  fread(dest->string, fsize, 1, fptr);
  if (ferror(fptr)) {
    ERR_PRINT("[ERROR] Could not read the given file %s, %s\n", file_path, strerror(errno));
  }
  dest->length = fsize;

  fclose(fptr);
  return 1;
}

Errno write_file(const char *file_path, const char *content) {
  FILE *fptr;
  fptr = fopen(file_path, "w");

  if (fptr != 0) {
    return 1;
  }
  return 0;
}

Errno append_file(const char *file_path, const char *content) {
  UNUSED(file_path);
  UNUSED(content);
  UNIMPLIMENTED;
}

Errno delete_file(const char *file_path) {
  UNUSED(file_path);
  UNIMPLIMENTED;
}
