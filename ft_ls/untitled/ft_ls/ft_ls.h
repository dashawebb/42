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

typedef struct s_info
{
	char *name;
	size_t size;
	long access_time;
	long mod_time;
	long change_time;
	int filetype; // как лучше хранить тип файла?
	size_t serial_number;
// как хранить uid and gid?
	char *uid;
	char *gid;
	int chmod_int;
	char chmod_char;
	char symb_link;

} t_info;

#endif
