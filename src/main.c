#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include "./common.h"
#include "./fs/fs.h"
#include "./String/String.h"
#include "./parser/cml.h"

Errno main(int argc, char **argv) {

  Cml_Tree tree = Cml_generate_tree();

  Cml_parse_file(&tree, "./test.txt");
}
