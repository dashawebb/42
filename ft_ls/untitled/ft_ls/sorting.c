//
// Created by Christop Reek on 2019-04-08.
//

#include <mach/mach_types.h>
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

    int writing_file_data_long_dir(char *d_name, char *str, int result, t_rbtree *file_info_tree) {

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
    file_info.chmod_int = buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO); // надо ли перевести его в восьмеричную систему?
    writing_chmod(&buf, &file_info); // здесь происходит запись в chmod_char
    rbt_insertion_func(&file_info, result, file_info_tree);
//    file_info.links = buf.st_nlink;

//	file_info.symb_link = getting_symlink(&file_info); // здесь invalid argument, нужен full_path

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

void ft_putstr_rbt(t_rbtree *elem)
{
    if (((t_info *)elem->content)->name == NULL)
        return ;
    while (*(((t_info *)elem->content)->name) != '\0')
    {
//        printf("%s ya ebal\n", (((t_info *)elem->content)->name)++);
        ft_putchar(*((t_info *)elem->content)->name);
        (((t_info *)elem->content)->name)++;
    }
}

int rbt_insertion_func(t_info *file_info, int result, t_rbtree *file_info_tree)
{
    int (*cmp)(t_rbtree *elem1, t_rbtree *elem2);
    void (*f)(t_rbtree *elem);

    if ((result >> 23) & 1)
        cmp = &ft_ctime_cmp;
    if ((result >> 6) & 1)
        cmp = &file_size_cmp;
    else
        cmp = &ft_strcmp_rbt;

    if (file_info_tree == NULL)
    {
        printf("Это пустое дерево\n");
        file_info_tree = ft_rbtnew((void *)file_info, sizeof(t_info));
    }
    else
    {
        printf("О! А это непустое дерево\n");
        ft_rbtadd(&file_info_tree, (t_rbtree *)&file_info, cmp);
    }
    printf("Закинул\n");
    f = &ft_putstr_rbt;
//    some_printing_func(file_info_tree);
    ft_rbtforeach(file_info_tree, f, PREFIX);

    /* Здесь происходит запись в лист
     *
    t_list	*file_details; // Do I need to initialize it to NULL?
    t_list	*f_info;

    f_info = ft_lstnew(&file_info, sizeof(t_info));
    if (f_info == NULL)
    free_list(file_details);
    ft_listadd_to_end(&file_details, f_info);
    */

    return (0);

}

//(t_tetr *)tetris->content
//((T_tetr *)tetr->content)->height

int ft_ctime_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
    return (int)(((t_info *)elem1->content)->change_time - ((t_info *)elem2->content)->change_time);

}

int file_size_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
    return (int)(((t_info *)elem1->content)->size - ((t_info *)elem2->content)->size);
}

int ft_strcmp_rbt(t_rbtree *elem1, t_rbtree *elem2)
{
    return (int)(ft_strcmp(((t_info *)elem1->content)->name, ((t_info *)elem2->content)->name));
}

    int writing_file_data_dir(char *d_name, int result, t_rbtree *file_info_tree)
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
        rbt_insertion_func(&file_info, result, file_info_tree);
        return (0);
    }


int writing_file_data_long(char *str, int result, t_rbtree *file_info_tree) {

    int a;
    struct stat buf;
    char *d_name_path;
    struct passwd *pwd = NULL;
    struct group *group_name;
    errno = 0;

//    d_name_path = ft_strjoin(str, "/");
    d_name_path = ft_strjoin("./", str);
    a = lstat(d_name_path, &buf);
    printf("возврат lstat %d\n", a);
    t_info file_info;
    file_info.name = str;
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

    group_name = getgrgid(buf.st_gid); // здесь grid
    if (group_name == NULL)
        perror("getgrgid");
    else
        file_info.gid = group_name->gr_name;
    file_info.chmod_int = buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO); // надо ли перевести его в восьмеричную систему?
    writing_chmod(&buf, &file_info); // здесь происходит запись в chmod_char
    rbt_insertion_func(&file_info, result, file_info_tree);
    return (0);
}

int writing_file_data(char *str, int result, t_rbtree *file_info_tree)
{
    int a;
    struct stat buf;
    struct passwd *pwd = NULL;
    struct group *group_name;
    a = lstat(str, &buf);
    printf("возврат lstat %d\n", a);
    t_info file_info;
    file_info.name = str;
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
    rbt_insertion_func(&file_info, result, file_info_tree);
    return (0);
}


//int name_cmp(t_rbtree *elem1, t_rbtree *elem2)
//{
//    int i;
//    return (ft_strcmp(elem1, elem2));
//
//    elem1->content->
//}