//
// Created by Christop Reek on 2019-04-10.
//

#include "ft_ls.h"

t_rbtree	*ft_rbtroot(t_rbtree *elem)
{
    if (elem)
    {
        while (elem->parent)
            elem = elem->parent;
    }
    return (elem);
}
