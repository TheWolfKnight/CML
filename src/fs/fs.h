
#include "../common.h"
#include "../String/String.h"

#ifndef FS_H_
#define FS_H_

Errno read_entire_file(String *dest, const char *file_path);
Errno write_file(const char *file_path, const char *content);
Errno append_file(const char *file_path, const char *content);
Errno delete_file(const char *file_path);

#endif // FS_H_
