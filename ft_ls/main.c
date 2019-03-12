#ifndef st_mtime
#define st_mtime st_mtimespec.tv_sec
#endif

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

int print_attributes(char *path)
{
	ssize_t buflen, keylen, vallen;
	char *buf, *key, *val;

	/*
	 * Determine the length of the buffer needed.
	 */
	buflen = listxattr(path, NULL, 0, 0);
	//printf("buflen: %zd\n", buflen); // тут все нормально считывается
	if (buflen == -1)
	{
		perror("listxattr");
		exit(EXIT_FAILURE);
	}
	if (buflen == 0)
	{
		printf("%s has no attributes.\n", path);
//		exit(EXIT_SUCCESS);
		return (0);
	}

	/*
	* Allocate the buffer.
	*/
	buf = (char *)malloc(buflen);
	if (buf == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/*
	 * Copy the list of attribute keys to the buffer.
	 */
	buflen = listxattr(path, buf, buflen, 0);
	//printf("buflen: %zd\n", buflen); // почему-то тут -1
	if (buflen == -1)
	{
		perror("listxattr");
		exit(EXIT_FAILURE);
	}

	/*
	 * Loop over the list of zero terminated strings with the
	 * attribute keys. Use the remaining buffer length to determine
	 * the end of the list.
	 */
	key = buf;
	while (buflen > 0)
	{

		/*
		 * Output attribute key.
		 */
		printf("eta attribute %s: ", key);

		/*
		 * Determine length of the value.
		 */
		vallen = getxattr(path, key, NULL, 0, 0, 0);
		if (vallen == -1)
			perror("getxattr");
		if (vallen > 0)
		{

			/*
			 * Allocate value buffer.
			 * One extra byte is needed to append 0x00.
			 */
			val = malloc(vallen + 1);
			if (val == NULL) {
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			/*
			 * Copy value to buffer.
			 */
			vallen = getxattr(path, key, val, vallen, 0 , 0);
			if (vallen == -1)
				perror("getxattr");
			else
			{
				/*
				 * Output attribute value.
				 */
				val[vallen] = 0;
				printf("%s", val);
			}
			free(val);
		}
		else if (vallen == 0)
			printf("<no value>");

		printf("\n");

		/*
		 * Forward to next attribute key.
		 */
		keylen = strlen(key) + 1;
		buflen -= keylen;
		key += keylen;
	}

	free(buf);
//	exit(EXIT_SUCCESS);
}


int	main()
{
	int a;

 	DIR *directory;
	struct dirent *dirent1;

    directory = opendir("./");
	dirent1 = readdir(directory);
	closedir(directory);

	char *path;
	struct stat buf;

//	path = "./Makefile";
	path = "/Users/creek/test_ls/6";
	a = lstat(path, &buf); //

	// print name
	char *name;
	name = strrchr(path, '/');
	printf("name: %s\n", ++name);
	// print attr
	print_attributes(path);


//	}
//	char *attributes;
//	size_t attr_size = 20; // RANDOM_NUM
//	getxattr(path, name, attributes, attr_size);
//	printf("attributes: %s\n", attributes);

	// print size
	printf("size in bytes: %lld\n", buf.st_size);
	// print date mod
	// print date created
	printf("Access time: %s\n", ctime(&buf.st_atimespec));
	printf("Modification time: %s\n", ctime(&buf.st_mtimespec));
	printf("Change time: %s\n", ctime(&buf.st_ctimespec));

	printf("Access time: %llu\n", buf.st_atimespec);
	printf("Modification time: %llu\n", buf.st_mtimespec);
	printf("Change time: %llu\n", buf.st_ctimespec);
	// print type of file/dir
	if (S_ISREG(buf.st_mode))
		printf("type of file/dir: regular file\n");
	if (S_ISDIR(buf.st_mode))
		printf("type of file/dir: directory\n");
	if (S_ISCHR(buf.st_mode))
		printf("type of file/dir: character device\n");
	if (S_ISBLK(buf.st_mode))
		printf("type of file/dir: block device\n");
	if (S_ISFIFO(buf.st_mode))
		printf("type of file/dir: FIFO (pipe)\n");
	if (S_ISLNK(buf.st_mode))
		printf("type of file/dir: symbolic link\n");
	if (S_ISSOCK(buf.st_mode))
		printf("type of file/dir: socket\n");
	// print serial number
	printf("serial number: %llu\n", buf.st_ino);
	// print gid uid
	struct passwd *pwd;
	pwd = getpwuid(buf.st_uid);
	if(pwd == NULL)
		perror("getpwuid");
	else
		printf("uid: %s\n", pwd->pw_name);

	struct group *group_name;
	group_name = getgrgid(buf.st_gid);
	if(group_name == NULL)
		perror("getgrgid");
	else
		printf("gid: %s\n", group_name->gr_name);

	// print chmod
	int statchmod = buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
	printf("chmod: %o\n", statchmod);

	//	printf("user defined flags:\n", buf.st_mode);

	// THE HELL THIS MEANS?


	// column 2? in ls -la - amount of links
	printf("links: %hu\n", buf.st_nlink);
	// contents of a link
	char *linkname;

	linkname = malloc(buf.st_size + 1);
	if (linkname == NULL)
	{
		fprintf(stderr, "insufficient memory\n");
		exit(EXIT_FAILURE);
	}
	ssize_t r;
	r = readlink(path, linkname, buf.st_size + 1);

	if (r < 0)
	{
		perror("lstat");
		exit(EXIT_FAILURE);
	}

	if (r > buf.st_size)
	{
		fprintf(stderr, "symlink increased in size "
						"between lstat() and readlink()\n");
		exit(EXIT_FAILURE);
	}

	linkname[buf.st_size] = '\0';

	printf("'%s' points to '%s'\n", path, linkname);


	// amount of blocks allocated for this file
	printf("Amount of blocks allocated: %d\n", buf.st_blocks);



	// get list of files in dir
	// get list of dirs in dir
//	dirp = opendir(".");
//	if (dirp == NULL)
//		return (ERROR);
//	len = strlen(name);
//	while ((dp = readdir(dirp)) != NULL) {
//		if (dp->d_namlen == len && strcmp(dp->d_name, name) == 0) {
//			(void)closedir(dirp);
//			return (FOUND);
//		}
//	}
//	(void)closedir(dirp);
//	return (NOT_FOUND);


//	struct stat { /* when _DARWIN_FEATURE_64_BIT_INODE is NOT defined */
//		dev_t    st_dev;    /* device inode resides on */
//		ino_t    st_ino;    /* inode's number */
//		mode_t   st_mode;   /* inode protection mode */
//		nlink_t  st_nlink;  /* number of hard links to the file */
//		uid_t    st_uid;    /* user-id of owner */
//		gid_t    st_gid;    /* group-id of owner */
//		dev_t    st_rdev;   /* device type, for special file inode */
//		struct timespec st_atimespec;  /* time of last access */
//		struct timespec st_mtimespec;  /* time of last data modification */
//		struct timespec st_ctimespec;  /* time of last file status change */
//		off_t    st_size;   /* file size, in bytes */
//		quad_t   st_blocks; /* blocks allocated for file */
//		u_long   st_blksize;/* optimal file sys I/O ops blocksize */
//		u_long   st_flags;  /* user defined flags for file */
//		u_long   st_gen;    /* file generation number */
//	};
//
//int cmp_time(t_info info1, t_info info2)
//{
//
//}
//	return 0;
}