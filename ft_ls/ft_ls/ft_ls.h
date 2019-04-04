//
// Created by Christop Reek on 2019-03-10.
//

#ifndef FT_LS_H
#define FT_LS_H
#define st_mtime st_mtimespec.tv_sec

#define TYPE_REG_FILE 0
#define TYPE_DIR 1
#define TYPE_CHR 2
#define TYPE_BLK 3
#define TYPE_FIFO 4
#define TYPE_LNK 5
#define TYPE_SOCK 6

#define OPTIONS "ACLOPRST@adefhiklmnoprst1"
#define OPTIONS_SHIFT 7

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

typedef struct s_info
{
	char *name;
	char *path;
	size_t size;
	unsigned long long access_time;
	unsigned long long mod_time;
	unsigned long long change_time;
	int filetype; // как лучше хранить тип файла?
	size_t serial_number;
// как хранить uid and gid?
	char *uid;
	char *gid;
	int chmod_int;
	char chmod_char[11];
	int links;
	char *symb_link; //path/file symbolic link points to

} t_info;

#endif
