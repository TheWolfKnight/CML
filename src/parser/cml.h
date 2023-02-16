
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "../common.h"
#include "../fs/fs.h"
#include "../String/String.h"

#ifndef CML_H_
#define CML_H_

typedef enum CML_NODE_TYPE_ {
  CML_TUPLE = 0,
  CML_INT,
  CML_FLOAT,
  CML_STRING,
  CML_TREE,
  
  CML_END,
} Cml_Node_Type;

typedef struct {
  Cml_Node *items;
  size_t capacity;
  size_t length;
} Cml_Tree;

typedef struct {
  void *value;
  char *tag;
  Cml_Node_Type type;
  size_t length;
} Cml_Node;

Cml_Tree Cml_generate_tree();
Cml_Node Cml_generate_node();
Bool Cml_parse_file(Cml_Tree *dest, const char *file_path);
Bool Cml_get_node(Cml_Tree *source, const char *target, Cml_Node *dest);
Bool Cml_get_nodes(Cml_Tree *source, const char *target, Cml_Node **dest);

#endif // CML_H_