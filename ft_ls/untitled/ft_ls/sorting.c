//
// Created by Christop Reek on 2019-04-08.
//

#include "ft_ls.h"

void writing_chmod(struct stat *buf, t_info *file_info)
{
    int i = 3;
    int j = 1;
    if (S_ISREG(buf->st_mode))
        file_info->chmod_char[0] = '-';
    if (S_ISDIR(buf->st_mode))
        file_info->chmod_char[0] = 'd';
    if (S_ISCHR(buf->st_mode))
        file_info->chmod_char[0] = 'c';
    if (S_ISBLK(buf->st_mode))
        file_info->chmod_char[0] = 'b';
    if (S_ISFIFO(buf->st_mode))
        file_info->chmod_char[0] = 'p';
    if (S_ISLNK(buf->st_mode))
        file_info->chmod_char[0] = 'l';
    if (S_ISSOCK(buf->st_mode))
        file_info->chmod_char[0] = 's';
    while (i--) {
        file_info->chmod_char[j++] = ((file_info->chmod_int >> ((i * 3) + 2) & 1) ? 'r' : '-');
        file_info->chmod_char[j++] = ((file_info->chmod_int >> ((i * 3) + 1) & 1) ? 'w' : '-');
        file_info->chmod_char[j++] = ((file_info->chmod_int >> (i * 3) & 1) ? 'x' : '-');
    }
}

int define_file_type(struct stat *buf, t_info *file_info)
{

    if (S_ISREG(buf->st_mode))
        file_info->filetype = TYPE_REG_FILE;
    if (S_ISDIR(buf->st_mode))
        file_info->filetype = TYPE_DIR;
    if (S_ISCHR(buf->st_mode))
        file_info->filetype = TYPE_CHR;
    if (S_ISBLK(buf->st_mode))
        file_info->filetype = TYPE_BLK;
    if (S_ISFIFO(buf->st_mode))
        file_info->filetype = TYPE_FIFO;
    if (S_ISLNK(buf->st_mode))
        file_info->filetype = TYPE_LNK;
    if (S_ISSOCK(buf->st_mode))
        file_info->filetype = TYPE_SOCK;
    return (0);
}

    int writing_file_data_long(char *d_name, char *str) {

    int a;
    struct stat buf;
    char *d_name_path;
    struct passwd *pwd = NULL;
    struct group *group_name;
    //t_info attr;

    //char *time;

//    printf("%s\n", ent->d_name);
    errno = 0;

    d_name_path = ft_strjoin(str, "/");
    d_name_path = ft_strjoin(d_name_path, d_name);
    a = lstat(d_name_path, &buf);
//        printf("%s\n", strerror(errno));
/* lstat падает на файлах, потому что я передаю ему имя папки   */
    printf("возврат lstat %d\n", a);
    t_info file_info;
    file_info.name = d_name;
    file_info.path = (char *)malloc(sizeof(char *) * ft_strlen((file_info.name) + 3));
    file_info.path = ft_strjoin("./", file_info.name); // но это только для файлов?
    file_info.size = buf.st_size;
    file_info.access_time = (unsigned long long) &buf.st_atimespec;
    file_info.mod_time = (unsigned long long) &buf.st_mtimespec;
    file_info.change_time = (unsigned long long) &buf.st_ctimespec;
    define_file_type(&buf, &file_info);
    file_info.serial_number = buf.st_ino;
    pwd = getpwuid(buf.st_uid); // здесь записывается uid
    if (pwd == NULL)
        perror("getpwuid");
    else
        file_info.uid = pwd->pw_name;
//    char *name = ft_strdup(getpwuid(buf.st_uid)->pw_name);
//    if (!getpwuid(buf.st_uid) || !getpwuid(buf.st_uid)->pw_name)
//        printf("UPAL\n");
//    else {
//        file_info.uid = ft_strdup(getpwuid(buf.st_uid)->pw_name);
//        printf("here's your uid blya: %s\n", file_info.uid);
//    }
//        printf("OOOK2\n");

    group_name = getgrgid(buf.st_gid); // здесь grid
    if (group_name == NULL)
        perror("getgrgid");
    else
        file_info.gid = group_name->gr_name;
//    file_info.gid = ft_strdup(getgrgid(buf.st_gid)->gr_name);
//    file_info.chmod_int = buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO); // надо ли перевести его в восьмеричную систему?
//    writing_chmod(&buf, &file_info); // здесь происходит запись в chmod_char
//    file_info.links = buf.st_nlink;

//	file_info.symb_link = getting_symlink(&file_info); // здесь invalid argument, нужен full_path

// к этому моменту надо уже спарсить флаги и понимать, по какому принципу идет сортировка
//    t_rbtree *file_info_tree;
//
//    if (file_info_tree == NULL)
//        file_info_tree = ft_rbtnew((void *)&file_info, sizeof(t_info));
//    else
//        file_info_tree = ft_rbtadd(**file_info_tree, *file_info,
//    int (*cmp)(t_rbtree *elem1, t_rbtree *elem2))
//



//    t_rbtree		*ft_rbtnew(void const *content, size_t content_size)
//
//
//    void		ft_rbtadd(t_rbtree **root, t_rbtree *new,
//                          int (*cmp)(t_rbtree *elem1, t_rbtree *elem2))




/* Здесь происходит запись в лист
 *
 *
    t_list	*file_details; // Do I need to initialize it to NULL?
    t_list	*f_info;

    f_info = ft_lstnew(&file_info, sizeof(t_info));
    if (f_info == NULL)
        free_list(file_details);
    ft_listadd_to_end(&file_details, f_info);

   */

//	printf("chmod: %o\n", file_info.chmod_int);
//
//	printf("chmod: %s\n", buf.st_mode);
//	write (1, "  ", 2);
//	ft_putnbr(buf.st_nlink);
//	ft_putnbr(buf.st_size);
//	write (1, " ", 1);
//	time = ctime(&buf.st_atimespec);
//	time += 4;
//	ft_putstr(time);
//	write (1, " ", 1);
//	ft_putstr(ent);

//	printf("serial number: %llu\n", buf.st_ino);

//	printf("links: %hu\n", buf.st_nlink);
//	printf("Amount of blocks allocated: %lld\n", buf.st_blocks);
    return (0);
}

    int writing_file_data(char *d_name, char *str)
    {
        int a;
        struct stat buf;
        struct passwd *pwd = NULL;
        struct group *group_name;
        a = lstat(d_name, &buf);
        printf("возврат lstat %d\n", a);
        t_info file_info;
        file_info.name = d_name;
        file_info.path = (char *)malloc(sizeof(char *) * ft_strlen((file_info.name) + 3));
        file_info.path = ft_strjoin("./", file_info.name); // но это только для файлов?
        file_info.size = buf.st_size;
        /* че из этого мне оставить?? */

        file_info.access_time = (unsigned long long) &buf.st_atimespec;
        file_info.mod_time = (unsigned long long) &buf.st_mtimespec;
        file_info.change_time = (unsigned long long) &buf.st_ctimespec;
        define_file_type(&buf, &file_info);
        file_info.serial_number = buf.st_ino;
        pwd = getpwuid(buf.st_uid); // здесь записывается uid
        if (pwd == NULL)
            perror("getpwuid");
        else
            file_info.uid = pwd->pw_name;
        group_name = getgrgid(buf.st_gid); // здесь grid
        if (group_name == NULL)
            perror("getgrgid");
        else
            file_info.gid = group_name->gr_name;
        str = "abc";
        return (0);
    }

//int name_cmp(t_rbtree *elem1, t_rbtree *elem2)
//{
//    int i;
//    return (ft_strcmp(elem1, elem2));
//
//    elem1->content->
//}