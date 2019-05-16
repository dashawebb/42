/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:20:44 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/22 16:52:44 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <dirent.h>
# include <fcntl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include "../libft/libft.h"

# define RCL_R 0
# define RCL_C 1
# define RCL_L 2
# define COL_V 0
# define COL_H 1
# define E_ILL_OPT 0
# define E_MLLC_CRSH 1
# define DEF_SZ 80

# define CNT(elem) ((t_data *)elem->content)

typedef struct	s_flags
{
	unsigned	l: 1;
	unsigned	y: 1;
	unsigned	a: 1;
	unsigned	r: 1;
	unsigned	t: 1;
	unsigned	one: 1;
	unsigned	b_a: 1;
	unsigned	b_t: 1;
	unsigned	x: 1;
	unsigned	f: 1;
	unsigned	u: 1;
	unsigned	c: 1;
	unsigned	g: 1;
	unsigned	b_u: 1;
	unsigned	p: 1;
	unsigned	o: 1;
}				t_flags;

typedef struct	s_info
{
	unsigned int	links_width;
	unsigned int	size_width;
	unsigned int	user_width;
	unsigned int	group_width;
	unsigned int	blocks;
	unsigned int	ext;
	unsigned int	maj_width;
	unsigned int	min_width;
	unsigned int	mm;
}				t_info;

typedef struct	s_data
{
	char			*perms;
	int				links;
	char			*user;
	char			*group;
	int				size;
	char			*time;
	char			*name;
	char			*link;
	size_t			id;
	time_t			stime;
	char			xattr;
	char			acl;
	int				major;
	int				minor;
}				t_data;

t_flags			*g_flags;
t_info			*g_info;

void			render(t_rbtree *queue);
void			init_flags(void);
t_rbtree		*parse_args(int ac, char **av);
void			read_dir(t_rbtree *elem);
void			handle_error(unsigned int i, char *arg);
int				handle_errno(char *arg);
void			print_tree(t_rbtree *tree);
void			del_queue(t_rbtree *elem);
void			del_tree(t_rbtree *elem);
void			ft_set_id(t_rbtree *root, size_t *n);
int				ft_cmp_id(t_rbtree *elem1, t_rbtree *elem2);
void			print_data(t_rbtree *elem);
int				select_tree_sort(t_rbtree **tree, t_rbtree *new);
int				select_queue_sort(t_rbtree **queue, t_rbtree *new);
int				fill_fflags(char c);
int				fill_sflags(char c);
int				fill_tflags(char c);
void			fill_info(t_data *data);
void			fill_perms(t_data *data, struct stat stats);
void			fill_file_type(t_data *data, int mode);
void			fill_time(t_data *data, struct stat stats);
void			init_info(void);
int				try_fill_list(t_data *new, struct dirent *cdir, char *path);
void			fill_list(t_data *data, struct stat stats, char *path);
void			fill_acl(t_data *data, struct stat stats, char *path);

#endif
