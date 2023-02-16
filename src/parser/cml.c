#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "../fs/fs.h"
#include "../String/String.h"
#include "../common.h"

#define CML_IMPLIMENTATION
#include "./cml.h"

static struct Cml_Parse_State {
  bool tag;
  bool content;
  bool skip;
  bool normal;
};

Cml_Tree Cml_generate_tree() {
  Cml_Tree result = {0};
  return result;
}

Cml_Node Cml_generate_node() {
  Cml_Node result = {0};
  return result;
}

static Bool Cml_get_content_type(const char *content, size_t len, Cml_Node_Type *t) {
  UNUSED(content, len, t);
  UNIMPLIMENTED;
}

static Bool Cml_add_to_tree(Cml_Tree *dest, Cml_Node *node) {
  UNUSED(dest, node);
  UNIMPLIMENTED;
}

Bool Cml_parse_file(Cml_Tree *dest, const char *file_path) {
  size_t len = strlen(file_path);
  char *file_extension;
  substring(len-4, 4, file_path, &file_extension);
  assert(strcmp(file_extension, ".xml") && "[ASSERT] The file does not end with .xml");

  String file_content;
  if (!read_entire_file(&file_content, file_path)) {
    return 0;
  }

  struct Cml_Parse_State state = {
    .tag = false,
    .content = false,
    .skip = false,
    .normal = true,
  };

  for (size_t i = 0; i < file_content.length; ++i) {

    // Starts the compile tag state
    if (state.normal && file_content.string[i] == '<') {
      state.normal = false;
      state.tag = true;
      continue;
    }
    // End the compile tag state

    // Start the compilation of the tag
    if (state.tag) {
      String s = String_create_string();
      while (true) {
        if (file_content.string[i] == '>')
          break;
        if (!String_add_char(&s, file_content.string[i])) {
          ERR_PRINT("[ERROR] Could not add %s to string. %s", file_content.string[i], strerror(errno));
          return 0;
        }
        ++i;
      }

      // memcpy the string from the String struct, into the Cml_Node struct
      Cml_Node node = Cml_generate_node();
      node.length = 0;
      memcpy(node.tag, s.string, s.length);
      Cml_add_to_tree(dest, &node);
      state.tag = false;
      state.content = true;
    }
    // End the compilation of the tag

    // Start compilation of content
    if (state.content) {
      String s = String_create_string();
      while (true) {
        if (file_content.string[i] == '<')
          break;
        if (!String_add_char(&s, file_content.string[i])) {
          ERR_PRINT("[ERROR] Could not add %s to string. %s", file_content.string[i], strerror(errno));
          return 0;
        }
      }

      Cml_Node_Type type;
      if (!Cml_get_content_type(s.string, s.length, &type)) {
        ERR_PRINT("[ERROR] Could not parse \"%s\" as a content type. %s", s.string, strerror(errno));
        return 0;
      }

      Cml_Node *dst = dest->items[dest->length - 1];
      dst->type = type;
      dst->value = (void *)s.string;
      dst->length++;
      state.content = false;
      state.normal = true;
    }
    // End compilation of content
  }

  return 1;
}

Bool Cml_get_node(Cml_Tree *src, const char *target, Cml_Node *dest) {
  UNUSED(src, target, dest);
  UNIMPLIMENTED;
}

Bool Cml_get_nodes(Cml_Tree *src, const char *target, Cml_Node **dest) {
  UNUSED(src, target, dest);
  UNIMPLIMENTED;
}
