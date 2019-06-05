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
    file_info->chmod_char[j] = '\0';
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

    int writing_file_data_long_dir(char *d_name, char *str, int result, t_rbtree **file_info_tree) {

    int a;
    struct stat buf;
    char *d_name_path;
    struct passwd *pwd = NULL;
    struct group *group_name;

    errno = 0;
    d_name_path = ft_strjoin(str, "/");
    d_name_path = ft_strjoin(d_name_path, d_name);
    a = lstat(d_name_path, &buf);
    printf("возврат lstat %d\n", a);
    t_info file_info;
    file_info.name = d_name;
    file_info.path = (char *)malloc(sizeof(char *) * ft_strlen((file_info.name) + 3));
    file_info.path = ft_strjoin("./", file_info.name); // но это только для файлов?
    file_info.size = buf.st_size;
    file_info.access_time = (unsigned long long) &buf.st_atimespec;
    file_info.mod_time = (unsigned long long) &buf.st_mtimespec;
    file_info.change_time = (unsigned long long) &buf.st_ctimespec;
    char *tmp_str = ctime((const time_t *)&buf.st_mtimespec);
    int n = ft_strchr(tmp_str, '\n') - tmp_str;

    file_info.mod_time_char = tmp_str;
    file_info.mod_time_char[n] = '\0'; // ?
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
//    file_info.gid = ft_strdup(getgrgid(buf.st_gid)->gr_name);
    file_info.chmod_int = buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO); // надо ли перевести его в восьмеричную систему?
    writing_chmod(&buf, &file_info); // здесь происходит запись в chmod_char
    rbt_insertion_func(&file_info, result, file_info_tree);

//    file_info.links = buf.st_nlink;

//	file_info.symb_link = getting_symlink(&file_info); // здесь invalid argument, нужен full_path
//	printf("serial number: %llu\n", buf.st_ino);

//	printf("links: %hu\n", buf.st_nlink);
//	printf("Amount of blocks allocated: %lld\n", buf.st_blocks);
    return (0);
}

void ft_putstr_rbt(t_rbtree *elem)
{
    char *str;
    if (((t_info *)elem->content)->name == NULL)
        return ;
    printf("Сейчас выведу элемент\n"); // строку в итоа
//    str = ft_strjoin(((t_info *)elem->content)->name, ft_itoa(((t_info *)elem->content)->size)); // переписать стрджойн с stdarg чтобы принимал дохуя
//    ft_putstr(str);
//    free(str);
    str = malloc(sizeof(char) * 100); // избавиться от этого magic_number;

    printf("%s ", ((t_info *)elem->content)->chmod_char);
    printf("%d ", ((t_info *)elem->content)->links);
    printf("%s ", ((t_info *)elem->content)->uid);
    printf("%s ", ((t_info *)elem->content)->gid);
    printf("%zu ", ((t_info *)elem->content)->size);
    printf("%s ", ((t_info *)elem->content)->mod_time_char);
    printf("%s\n", ((t_info *)elem->content)->name);
}

void str_elem_length(t_rbtree **file_info_tree)
{
    t_length str_length;

    str_length.links = 0;
    str_length.uid = 0;
    str_length.gid = 0;
    str_length.size = 0;

    void (*f)(t_rbtree *elem, t_length *str_length);
    f = &strlen_calc;

    ft_rbtforeach_two(*file_info_tree, &str_length, f, INFIX);
    printf("links: %d\n", str_length.links);
    printf("uid: %d\n", str_length.uid);
    printf("gid: %d\n", str_length.gid);
    printf("size: %d\n", str_length.size);
    printf("total length: %d\n", str_length.total_length);

}

void strlen_calc(t_rbtree *elem, t_length *str_length)
{
    int links = ft_strlen(ft_itoa(((t_info *)elem->content)->links));
    int uid = ft_strlen(((t_info *)elem->content)->uid);
    int gid = ft_strlen(((t_info *)elem->content)->gid);
    int size = ft_strlen(ft_itoa(((t_info *)elem->content)->size));

    if (links > str_length->links)
        str_length->links = links;
    if (uid > str_length->uid)
        str_length->uid = uid;
    if (gid > str_length->gid)
        str_length->gid = gid;
    if (size > str_length->size)
        str_length->size = size;
    str_length->total_length = str_length->links + str_length->uid + str_length->gid + str_length->size;
}

void str_concat()
{
//    char *str;
//    str = malloc





}

void ft_rbt_putnbr(t_rbtree *elem)
{
    if (((t_info *)elem->content)== NULL)
        return ;
    printf("Сейчас выведу элемент\n");
    ft_putnbr(*(int *)elem->content);
    ft_putstr("          ");
    ft_putnbr(elem->color);
    printf("\n");
}


int ft_intcmp(t_rbtree *elem1, t_rbtree *elem2)
{
    return ((*(int *)(elem1->content)) - (*(int *)(elem2->content)));
}

int rbt_insertion_func(t_info *file_info, int result, t_rbtree **file_info_tree)
{
    int (*cmp)(t_rbtree *elem1, t_rbtree *elem2);
    void (*f)(t_rbtree *elem);

    f = &ft_putstr_rbt;
    if ((result >> 23) & 1)
    {
        cmp = &ft_ctime_cmp;
        printf("Спарсил флаг t\n");
    }
    else if ((result >> 6) & 1)
    {
        cmp = &file_size_cmp;
        printf("Спарсил флаг S\n");
    }
    else
    {
        printf("Спарсил нихуя\n");
        cmp = &ft_strcmp_rbt;
    }
//    int array[10] = {0, 2 , 5, 7, 4, 8, 9, 3, 1, 6};
//    cmp = &ft_intcmp;
//
//    for (int i = 0; i < 10; i++)
//    {
//        ft_rbtadd(file_info_tree, ft_rbtnew((void *)&(array[i]), sizeof(int *)), cmp);
//    }
//    void (*f)(t_rbtree *elem);
//
//    f = &ft_rbt_putnbr;
    ft_rbtadd(file_info_tree, ft_rbtnew((void *)file_info, sizeof(t_info)), cmp);
//    printf("А вот вышел из функции и выведу дерево\n");
//    ft_rbtforeach(*file_info_tree, f, INFIX);
//    printf("\nВывел\n");


    printf("Закинул\n");
    return (0);

}

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

    int writing_file_data_dir(char *d_name, char *str, int result, t_rbtree **file_info_tree)
    {
        int a;
        struct stat buf;
        char *d_name_path;
        struct passwd *pwd = NULL;
        struct group *group_name;
        d_name_path = ft_strjoin("./", str);
        a = lstat(d_name_path, &buf);
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


int writing_file_data_long(char *str, int result, t_rbtree **file_info_tree) {

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

int writing_file_data(char *str, int result, t_rbtree **file_info_tree)
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