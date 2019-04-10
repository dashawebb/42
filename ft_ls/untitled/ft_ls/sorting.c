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

int writing_file_data(struct dirent *ent)
{
    int a;
    struct stat buf;
    struct passwd *pwd;
    struct group *group_name;
    t_info attr;

    char *time;

    a = lstat(ent, &buf);

    t_info file_info;
    file_info.name = ent;
    file_info.path = (char *)malloc(sizeof(char*) * ft_strlen((file_info.name) + 3));
    file_info.path = ft_strjoin("./", file_info.name); // но это только для файлов?
    file_info.size = buf.st_size;
    file_info.access_time = (unsigned long long)&buf.st_atimespec;
    file_info.mod_time = (unsigned long long)&buf.st_mtimespec;
    file_info.change_time = (unsigned long long)&buf.st_ctimespec;
    define_file_type(&buf, &file_info);

    file_info.serial_number = buf.st_ino;
    pwd = getpwuid(buf.st_uid);
    if(pwd == NULL)
        perror("getpwuid");
    else
        file_info.uid = pwd->pw_name;
    group_name = getgrgid(buf.st_gid);
    if(group_name == NULL)
        perror("getgrgid");
    else
        file_info.gid = group_name->gr_name;
    file_info.chmod_int = buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO); // надо ли перевести его в восьмеричную систему?
    writing_chmod(&buf, &file_info); // здесь происходит запись в chmod_char
    file_info.links = buf.st_nlink;
//	file_info.symb_link = getting_symlink(&file_info); // здесь invalid argument, нужен full_path

// к этому моменту надо уже спарсить флаги и понимать, по какому принципу идет сортировка
    t_rbtree *file_info_tree;

    if (file_info_tree == NULL)
        file_info_tree = ft_rbtnew((void *)&file_info, sizeof(t_info));
    else
        file_info_tree = ft_rbtadd(**file_info_tree, *file_info,
    int (*cmp)(t_rbtree *elem1, t_rbtree *elem2))




    t_rbtree		*ft_rbtnew(void const *content, size_t content_size)


    void		ft_rbtadd(t_rbtree **root, t_rbtree *new,
                          int (*cmp)(t_rbtree *elem1, t_rbtree *elem2))




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

}

int name_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
    return (ft_strcmp(elem1))

    elem1->content->





}