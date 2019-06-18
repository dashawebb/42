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

# define LEFT -1
# define RIGHT 1
# define PREFIX -1
# define INFIX 0
# define POSTFIX 1

# define P(x) (x->parent)
# define GRAND(node) node->parent->parent
# define UNCLE(x) (GRAND(x)->left == P(x)) ? GRAND(x)->right : GRAND(x)->left
# define SIBLING(x) ((P(x)->left == x) ? P(x)->right : P(x)->left)
# define SR(node) (SIBLING((*node))->right)
# define SL(node) (SIBLING((*node))->left)

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
#include "libft/includes/libft.h"
#include <errno.h>

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
	char *mod_time_char;
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

typedef struct s_length
{
    int links;
    int uid;
    int gid;
    int size;
    int total_length;
    int elements;


} t_length;

enum	e_color
{
    RB_BLACK = 0,
    RB_RED = 1
};

typedef struct	s_rbtree
{
    void			*content;
    size_t			content_size;
    struct s_rbtree *parent;
    struct s_rbtree *left;
    struct s_rbtree *right;
    enum e_color	color;
}				t_rbtree;

int check_valid_option(char *str, int result);

int check_file(char *str, int result);

int validation(int argc, char *argv[]);

void writing_chmod(struct stat *buf, t_info *file_info);

int define_file_type(struct stat *buf, t_info *file_info);

int writing_file_data_long_dir(char *d_name, char *str, int result, t_rbtree **file_info_tree);

int writing_file_data_dir(char *d_name, char *str, int result, t_rbtree **file_info_tree);

int writing_file_data_long(char *str, int result, t_rbtree **file_info_tree);

int writing_file_data(char *str, int result, t_rbtree **file_info_tree);

int rbt_insertion_func(t_info *file_info, int result, t_rbtree **file_info_tree);

t_list	*ft_lstnew(void const *content, size_t content_size);

void	ft_listadd_to_end(t_list **begin_list, t_list *new);

void	free_list(t_list *head);

int file_size_cmp(t_rbtree *elem1, t_rbtree *elem2);

int ft_ctime_cmp(t_rbtree *elem1, t_rbtree *elem2);

int sort_lexic_rev(char *name_1, char *name_2); // это вообще не нужно

int ft_strcmp_rbt(t_rbtree *elem1, t_rbtree *elem2);

void ft_putstr_rbt(t_rbtree *elem);

void str_elem_length(t_rbtree **file_info_tree);

void strlen_calc(t_rbtree *elem, t_length *str_length);

void str_concat(t_rbtree *elem, t_length *str_length, char *str);

void ft_rbt_putnbr(t_rbtree *elem);

int some_printing_func(t_rbtree *file_info_tree);

int printing(int options, t_list *file_details);

void			ft_rbtadd(t_rbtree **root, t_rbtree *new,
                          int(*cmp)(t_rbtree *elem1, t_rbtree *elem2));

void			ft_rbtclr(t_rbtree **node, void (*del)(t_rbtree *elem));

t_rbtree		*ft_rbtfind(t_rbtree *root, t_rbtree *elem,
                            int (*cmp)(t_rbtree *elem1, t_rbtree *elem2));

size_t			ft_rbtlen(t_rbtree *root);

t_rbtree		*ft_rbtnew(void const *content, size_t content_size);

t_rbtree		*ft_rbtnew0(void const *content, size_t content_size);

void			ft_rbtrmv(t_rbtree **elem);

size_t			ft_rbtsize(t_rbtree *root);

t_rbtree		*ft_rbtroot(t_rbtree *elem);

void        ft_rbtforeach(t_rbtree *root, void (*f)(t_rbtree *elem), int order); // от этой хуеты надо избавиться

void        ft_rbtforeach_two(t_rbtree *root, t_length *str_length, void (*f)(t_rbtree *elem, t_length *str_length), int order);

void        ft_rbtforeach_three(t_rbtree *root, t_length *str_length, void (*f)(t_rbtree *elem, t_length *str_length, char *str), int order, char *str);

#endif
