//
// Created by Christop Reek on 2019-04-10.
//

#include "ft_ls.h"

static void	ft_rotation(t_rbtree *node, int dest)
{
    t_rbtree *son;

    son = (dest == LEFT) ? node->right : node->left;
    if (node->parent)
    {
        ((node)->parent->left == node) ?
        ((node)->parent->left = son) :
        ((node)->parent->right = son);
    }
    son->parent = node->parent;
    node->parent = son;
    if (dest == LEFT)
    {
        node->right = son->left;
        son->left = node;
        node->right->parent = node;
    }
    else
    {
        node->left = son->right;
        son->right = node;
        node->left->parent = node;
    }
}

static void	ft_recolor(t_rbtree *node)
{
    node->parent->color = RB_BLACK;
    (SIBLING(node))->color = RB_RED;
}

static void	ft_rotate(t_rbtree *node)
{
        if ((GRAND(node)->right == node->parent) && (node->parent->right == node)) {
            ft_rotation(GRAND(node), LEFT);
            ft_recolor(node);
        } else if ((GRAND(node)->left == node->parent) &&
                   (node->parent->left == node)) {
            ft_rotation(GRAND(node), RIGHT);
            ft_recolor(node);
        } else if ((GRAND(node)->right == node->parent) &&
                   (node->parent->left == node)) {
            ft_rotation(node->parent, RIGHT);
            ft_rotation(node->parent, LEFT);
            ft_recolor(node->right);
        } else if ((GRAND(node)->left == node->parent) &&
                   (node->parent->right == node)) {
            ft_rotation(node->parent, LEFT);
            ft_rotation(node->parent, RIGHT);
            ft_recolor(node->left);
        }
}

static void	ft_check_double_red(t_rbtree *new)
{
    if (!(new->parent)) {
        new->color = RB_BLACK;
    }
    else if (new->parent->color == RB_RED)
    {
        if ((UNCLE(new))->color == RB_RED)
        {
            (UNCLE(new))->color = RB_BLACK;
            new->parent->color = RB_BLACK;
            (GRAND(new))->color = RB_RED;
            ft_check_double_red(GRAND(new));
        }
        else {
            ft_rotate(new);
        }
    }
}

void		ft_rbtadd(t_rbtree **root, t_rbtree *new,
                      int (*cmp)(t_rbtree *elem1, t_rbtree *elem2))
{
    t_rbtree *temp;

//    printf("%p\n", new->parent);
    if (!*root)
    {
        *root = new;
        (*root)->color = RB_BLACK;
        return ;
    }
    temp = *root;
//    printf("sega1\n");
    while (temp->content)
        temp = ((cmp(temp, new) > 0) ? temp->left : temp->right);
//    printf("sega2\n");
    new->parent = temp->parent;
    (cmp(new->parent, new) > 0) ? (new->parent->left = new) :
    (new->parent->right = new);
//    printf("sega2\n");
    ft_check_double_red(new);

//    printf("sega3\n");
    free(temp);

//    printf("sega4\n");
    *root = ft_rbtroot(*root);
//    printf("sega5\n");
}
