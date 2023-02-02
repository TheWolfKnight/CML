#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include "./common.h"
#include "./fs/fs.h"

Errno main(int argc, char **argv) {
  char src_file_content[READ_LIMIT];
  
  if (!read_entire_file(&src_file_content, "./src/main.c")) {
    exit(1);
  }
  
  printf("%s", src_file_content);
  return 0;
}
