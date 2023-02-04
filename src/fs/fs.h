
#include "../common.h"
#include "../String/String.h"

#ifndef FS_H_
#define FS_H_

int read_entire_file(String *dest, const char *file_path);
int write_file(const char *file_path, const char *content);
int append_file(const char *file_path, const char *content);
int delete_file(const char *file_path);

#endif // FS_H_
