#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common.h"
#include "../String/fs.h"

#include "fs.h"
#define FS_IMPLEMENTATION


String read_entire_file(const char *file_path) {
  FILE *fptr;
  fptr = fopen(file_path, "r");
  
  if (fptr == NULL) {
    fprintf(stderr, "[ERROR] Failed to open file %s: %s\n", file_path, strerror(errno));
    exit(1);
  }

  String result = String_create_string();

  int i = 0;
  for (char c = getc(fptr); c != EOF && i < READ_LIMIT-1; c = getc(fptr), ++i) {
    String_add_char(*result, c);
  }
  String_add_char(*result, '\0');

  return result;
}

int write_file(const char *file_path, const char *content) {
  FILE *fptr;
  fptr = fopen(file_path, "w");

  if (fptr != 0) {
    return 1;
  }
  return 0;
}

int append_file(const char *file_path, const char *content) {
  UNUSED(file_path);
  UNUSED(content);
  UNIMPLIMENTED;
}

int delete_fiel(const char *file_path) {
  UNUSED(file_path);
  UNIMPLIMENTED;
}
