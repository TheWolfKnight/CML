#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include "./common.h"
#include "./fs/fs.h"
#include "./String/String.h"

Errno main(int argc, char **argv) {
  String file_results = String_create_string();

  if (!read_entire_file(&file_results, "./src/common.h")) {
    exit(1);
  }
}
