#include <sys/attr.h>
#include "ft_ls/ft_ls.h"

int sort_by_time(long time_1, long time_2) {
	if (time_1 && time_2)
	{
		if (time_1 > time_2)
			return (1);
		if (time_1 == time_2)
			return (0);
		if (time_2 < time_1)
			return (-1);
	}
}

int sort_lexic(char *name_1, char *name_2)
{
	int i;

	i = 0;
	if (ft_strcmp(name_1, name_2))
		return (1);
	if (name_1[i] == name_2[i])
		return (0);
	if (name_1[i] < name_2[i])
		return (-1);


}

int sort_lexic_rev(char *name_1, char *name_2)
{


}

//int int_flags(char *argv[])
//{
//	int i;
//
//	i = 0;
//	int result;
//
//	//i = ft_strlen(argv[i]);
//	i -= 1;
//	if (!(index = ft_strchr(OPTIONS, argv[i][j])))
//	{
//		printf("illegal option -- %c\n", argv[i][j]);
//		printf("usage: ls [-ACLOPRST@adefhiklmnoprst1] [file ...]\n");
//		return (1);
//	}
//	else
//	{
//		((result >> index) & 1);
//		result += (1 << index); // что это??
//	}
//
//
//	}
//	return (result);
//}
//
//

//
//int validation(int argc, char *argv[])
//{
//	// считывание начинается с конца
//	// один из противоречащих аргументов - считывается первый
//	// строка вида ""
//
//	int i;
//	int j;
//	int k;
//
//	i = 2;
//	char good_flags[26] = "-ACLOPRST@adefhiklmnoprst1"; // надо добавить обработку флага -- (валидный)
//
//	while (argv[i])
//	{
//		j = 0;
//		while (argv[i][j])
//		{
//			k = 0;
//			while (good_flags[k])
//			{
//				if (argv[i][j] == good_flags[k]) // вот эту хуету надо переписать пожалуйста Даша
//					break ;
//				k++;
//			}
//			if (!good_flags[k])
//			{
//				printf("illegal option -- %c\n", argv[i][j]);
//				printf("usage: ls [-ACLOPRST@adefhiklmnoprst1] [file ...]\n");
//				return (1) ;
//			}
//			j++;
//		}
//		i++;
//	}
//	return (0);
//}

//
//	int check_dash(int argc, char *argv[])
//	{
//
//		int i;
//		int j;
//		int k;
//
//		i = 2;
//		k = 0;
//		while (argv[i])
//		{
//			j = 0;
//			k = 0;
//			while (argv[i][j])
//			{
//				if (argv[i][j] == '-')
//					k++;
//				if (k == 2 && argv[i][j + 1])
//				{
//					printf("illegal option -- -\n");
//					printf("usage: ls [-ACLOPRST@adefhiklmnoprst1] [file ...]\n");
//					return (1);
//				}
//				j++;
//			}
//			i++;
//		}
//		return (0);
//	}
	/* для сравнения по дате не нужно вызывать ctime)
	printf("Access time: %s\n", ctime(&buf.st_atimespec));
	printf("Modification time: %s\n", ctime(&buf.st_mtimespec));
	printf("Change time: %s\n", ctime(&buf.st_ctimespec));

	unsigned long long time

*/
	int print_chmod(struct stat buf)
	{
		int statchmod = buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
		//printf("chmod: %o\n", statchmod);

		int i = 3;
		int j = 1;
		char str[11];
		if (S_ISREG(buf.st_mode))
			str[0] = "-";
		if (S_ISDIR(buf.st_mode))
			str[0] = "d";
		if (S_ISCHR(buf.st_mode))
			str[0] = "c";
		if (S_ISBLK(buf.st_mode))
			str[0] = "b";
		if (S_ISFIFO(buf.st_mode))
			str[0] = "p";
		if (S_ISLNK(buf.st_mode))
			str[0] = "l";
		if (S_ISSOCK(buf.st_mode))
			str[0] = "s";
		while (i--)
		{
			str[j++] = ((statchmod >> ((i * 3) + 2) & 1) ? 'r' : '-');
			str[j++] = ((statchmod >> ((i * 3) + 1) & 1) ? 'w' : '-');
			str[j++] = ((statchmod >> (i * 3) & 1) ? 'x' : '-');
		}
		ft_putstr(str);

	}

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
		printf("eta attribute %s: \n", key);

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

int check_valid_option(char *str, int result)
{
	/* 0-й символ уже '-' */
	int i;
	int index;

	i = 1;
	index = 0;

	if ((str[i] == '-') && (!(str[i + 1])))
		return (0); // это норм, флаг '--' валидный, возвращаем нолик
	while(str[i])
	{
		if (!(ft_strchr(OPTIONS, str[i])))
		{
			write(1, "illegal option -- ", 18);
			write (1, &str[i], 1);
			write (1, "\n", 1);
			write(1, "usage: ls [-ACLOPRST@adefhiklmnoprst1] [file ...]\n", 50);
			return (-1); // инвалидный флаг
		}
		else {
//			for (int z = 0; z < 100 && OPTIONS[z] != str[i]; z++)
//				index = 31 - (z + 1 + OPTIONS_SHIFT); //
//			// как i
//			printf("eto index %d\n", index);
//			if (!((result >> (31 - index)) & 1));
//				result += (1 << (index));
//				result += (1 << (index));

			for (int z = 0; z < 100 && OPTIONS[z] != str[i]; z++)
				index = z + 1; //
			// как i
			//printf("eto index %d\n", index);
			if (!(((result) >> index) & 1))
				(result) += (1 << (index));
			//printf("result: %d\n", result);
			//printf("the letter was: %c\n", str[i]);
			i++;
		}
	}
	return (result);
//	-ladefhikemnoprst1@CLOPRST
// на k случилось переполнение инта
}

int writing_file_data(struct dirent *ent)
{
	int a;
	struct stat buf;
	struct passwd *pwd;
	struct group *group_name;
	char *time;

	a = lstat(ent, &buf);
	print_chmod(buf);
	write (1, "  ", 2);
	ft_putnbr(buf.st_nlink);
	write (1, " ", 1);
	pwd = getpwuid(buf.st_uid);
	if(pwd == NULL)
		perror("getpwuid");
	else
		ft_putstr(pwd->pw_name);
	write (1, " ", 1);
	group_name = getgrgid(buf.st_gid);
	if(group_name == NULL)
		perror("getgrgid");
	else
		ft_putstr(group_name->gr_name);
	write (1, " ", 1);
	ft_putnbr(buf.st_size);
	write (1, " ", 1);
	time = ctime(&buf.st_atimespec);
	time += 4;
	ft_putstr(time);
	write (1, " ", 1);
	ft_putstr(ent);
//	printf("serial number: %llu\n", buf.st_ino);

//	printf("links: %hu\n", buf.st_nlink);
//	printf("Amount of blocks allocated: %lld\n", buf.st_blocks);

}

int check_file(char *str)
{
	int a = 0;
	DIR *dir;
	struct dirent *ent;
	struct stat buf;

	if (ft_strlen(str) > 255)
	{
		write(1, "ls: ", 4);
		ft_putstr(str);
		write (1, ": File name too long\n", 20);
	}
	if ((dir = opendir (str)) != NULL)
	{
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) {
			//printf ("file or dir: ");
			//ft_putstr(ent->d_name);
			writing_file_data(ent->d_name);
			// и здесь кастовать lstat на file_name;
			write(1, "\n", 1);
		}
		closedir (dir);
	} else {
		/* could not open directory */
		if ((a = lstat(str, &buf)) == -1) // а здесь вызывается функция, которая пишет в список
		{
			write(1, "ls: ", 4);
			ft_putstr(str);
			write(1, ": No such file or directory\n", 28);
			return EXIT_FAILURE;
		}
		else
			printf("Нашел файлик!: %s\n", str);
	}
	return (0);

}

int validation(int argc, char *argv[])
{
	int j;
	int result = 0;

	j = 0;
	if (argc > 1)
	{
		argc -= 1;
		while (argc > 0) {

//			while (argv[argc])
//			{
				if (argv[argc][0] == '-')
				{
					if (!(argv[argc][1])) {
						write(1, "ls: -: No such file or directory\n", 33);
						return(-1);
					}
					if ((result = (check_valid_option(argv[argc], result))) == -1) // если есть -, значит это флаг. Отправляемся проверять его валидность. Если возвращает -1, выходим, else return options;
						return (-1);
				}
				else
					check_file(argv[argc]); // если минуса нет, значит это файл, и надо проверять его валидность. Дальше в мейне сделать проверку на отсутствие файла.
				argc--;
//			}
		}
		return (result);
	}
	return (0);
}

int	main(int argc, char *argv[])
{

	int a;
	int options; // здесь будут записываться флаги в интовом варианте

	options = 0;
	//if (!(check_dash(argc, argv)))
	if ((options = (validation(argc, argv))) == -1) // она вызывает check_valid_option, которая вернет интовый OPTIONS. Их же надо передавать туда и апдейтить с разными флагами
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	//printf("options после всех манипуляций %d\n", options);
 	DIR *directory;
	struct dirent *dirent1;

    directory = opendir("./");
	dirent1 = readdir(directory);
	closedir(directory);

	char *path;
	struct stat buf;

	path = "/Users/creek/CLionProjects/untitled/cmake-build-debug";
//	path = "/Users/creek/.brew/Library/Homebrew/os/mac/pkgconfig/fuse";
//	path = "/Users/creek/test_ls/6";
	a = lstat(path, &buf); //

	// print name
	char *name;
	name = strrchr(path, '/');
	printf("name: %s\n", ++name);
	// print attr
	print_attributes(path);

	// print size
	printf("size in bytes: %lld\n", buf.st_size);
	// print date mod
	// print date created
	printf("Access time: %s\n", ctime(&buf.st_atimespec));
	printf("Modification time: %s\n", ctime(&buf.st_mtimespec));
	printf("Change time: %s\n", ctime(&buf.st_ctimespec));

	printf("Access time in sec: %llu\n", buf.st_atimespec);
	printf("Modification time in sec: %llu\n", buf.st_mtimespec);
	printf("Change time in sec : %llu\n", buf.st_ctimespec);
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
	print_chmod(buf);

	//	printf("user defined flags:\n", buf.st_mode);

	// THE HELL THIS MEANS?


	// column 2? in ls -la - amount of links
	printf("links: %hu\n", buf.st_nlink);
	// contents of a link
//	char *linkname;
//
//	linkname = malloc(buf.st_size + 1);
//	if (linkname == NULL)
//	{
//		fprintf(stderr, "insufficient memory\n");
//		exit(EXIT_FAILURE);
//	}
//	ssize_t r;
//	r = readlink(path, linkname, buf.st_size + 1);
//
//	if (r < 0)
//	{
//		perror("lstat");
//		exit(EXIT_FAILURE);
//	}
//
//	if (r > buf.st_size)
//	{
//		fprintf(stderr, "symlink increased in size "
//						"between lstat() and readlink()\n");
//		exit(EXIT_FAILURE);
//	}
//
//	linkname[buf.st_size] = '\0';

	// printf("'%s' points to '%s'\n", path, linkname);


	// amount of blocks allocated for this file
	printf("Amount of blocks allocated: %lld\n", buf.st_blocks);

	printf("sizeof time_t is: %lu\n", sizeof(time_t));


//	 get list of files in dir
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir (".")) != NULL)
	{
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) {
			printf ("file or dir: %s\n", ent->d_name);
		}
		closedir (dir);
	} else {
		/* could not open directory */
		perror ("");
		return EXIT_FAILURE;
	}

//	 get list of dirs in dir

/* этот код ищет filename в директории */
//	DIR *dirp;
//	struct dirent *dp;
//
//	dirp = opendir(".");
//	if (dirp == NULL)
//		return (1);
//	size_t len = ft_strlen(name);
//	while ((dp = readdir(dirp)) != NULL) {
//		if (dp->d_namlen == len && strcmp(dp->d_name, name) == 0) {
//			(void)closedir(dirp);
//			return (0);
//		}
//	}
//	(void)closedir(dirp);
//	return (-1);
//


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