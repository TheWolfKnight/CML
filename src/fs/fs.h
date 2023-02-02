
#include "../common.h"

#ifndef FS_H_
#define FS_H_

#define READ_LIMIT 1024

int read_entire_file(char *buffer[1024], const char *file_path);
int write_file(const char *file_path, const char *content);
int append_file(const char *file_path, const char *content);
int delete_fiel(const char *file_path);

#endif // FS_H_
