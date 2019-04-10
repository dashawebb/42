//
// Created by Christop Reek on 2019-04-10.
//

#include "ft_ls.h"

static void	ft_rbtdel(t_rbtree **root, void (*del)(t_rbtree *elem))
{
    if (*root)
    {
        if ((*root)->left)
            ft_rbtdel(&((*root)->left), del);
        if ((*root)->right)
            ft_rbtdel(&((*root)->right), del);
        del(*root);
        free(*root);
        *root = 0x0;
    }
}

void		ft_rbtclr(t_rbtree **node, void (*del)(t_rbtree *elem))
{
    *node = ft_rbtroot(*node);
    ft_rbtdel(node, del);
}

