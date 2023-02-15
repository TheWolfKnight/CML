#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

#include "../fs/fs.h"
#include "../String/String.h"
#include "../common.h"

#define CML_IMPLIMENTATION
#include "./cml.h"

Cml_Tree Cml_generate_tree() {
  Cml_Tree result = {0};
  return result;
}

Cml_Node Cml_generate_node() {
  Cml_Node result = {0};
  return result;
}

int Cml_parse_file(Cml_Tree *dest, const char *file_path) {
  size_t len = strlen(file_path);
  char *file_extension;
  substring(len-4, 4, file_path, &file_extension);
  assert(strcmp(file_extension, ".xml") && "[ASSERT] The file does not end with .xml");

  String file_content;
  if (!read_entire_file(&file_content, file_path)) {
    exit(1);
  }


  return 1;
}
