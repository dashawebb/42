//
// Created by Christop Reek on 2019-05-12.
//

#include "libft.h"
#include "ft_ls.h"

static void ft_rbtforeach_pre(t_rbtree *root, void (*f)(t_rbtree *elem))
{
    if (root->content)
        f(root);
    if (root->left->content)
        ft_rbtforeach_pre(root->left, f);
    if (root->right->content)
        ft_rbtforeach_pre(root->right, f);
}

static void ft_rbtforeach_in(t_rbtree *root, void (*f)(t_rbtree *elem))
{
    if (root->left->content)
        ft_rbtforeach_in(root->left, f);
    if (root->content)
        f(root);
    if (root->right->content)
        ft_rbtforeach_in(root->right, f);
}

static void ft_rbtforeach_post(t_rbtree *root, void (*f)(t_rbtree *elem))
{
    if (root->left->content)
        ft_rbtforeach_post(root->left, f);
    if (root->right->content)
        ft_rbtforeach_post(root->right, f);
    if (root->content)
        f(root);
}

void        ft_rbtforeach(t_rbtree *root, void (*f)(t_rbtree *elem), int order)
{
    if (!root || !f) {
        printf("o nihuya %p   %p\n", root, f);
        return;
    }
    if (order == PREFIX)
    {
        ft_rbtforeach_pre(root, f);
    }
    else if (order == INFIX)
    {
        ft_rbtforeach_in(root, f);
    }
    else if (order == POSTFIX)
    {
        ft_rbtforeach_post(root, f);
    }
}

static void ft_rbtforeach_pre_two(t_rbtree *root, t_length *str_length, void (*f)(t_rbtree *elem, t_length *str_length))
{
    if (root->content)
        f(root, str_length);
    if (root->left->content)
        ft_rbtforeach_pre_two(root->left, str_length, f);
    if (root->right->content)
        ft_rbtforeach_pre_two(root->right, str_length, f);
}

static void ft_rbtforeach_in_two(t_rbtree *root, t_length *str_length, void (*f)(t_rbtree *elem, t_length *str_length))
{
    if (root->left->content)
        ft_rbtforeach_in_two(root->left, str_length, f);
    if (root->content)
        f(root, str_length);
    if (root->right->content)
        ft_rbtforeach_in_two(root->right, str_length, f);
}

static void ft_rbtforeach_post_two(t_rbtree *root, t_length *str_length, void (*f)(t_rbtree *elem, t_length *str_length))
{
    if (root->left->content)
        ft_rbtforeach_post_two(root->left, str_length, f);
    if (root->right->content)
        ft_rbtforeach_post_two(root->right, str_length, f);
    if (root->content)
        f(root, str_length);
}

void        ft_rbtforeach_two(t_rbtree *root, t_length *str_length, void (*f)(t_rbtree *elem, t_length *str_length), int order)
{
if (!root || !f) {
    printf("o nihuya %p   %p\n", root, f);
    return;
    }
    if (order == PREFIX)
    {
        ft_rbtforeach_pre_two(root, str_length,  f);
    }
    else if (order == INFIX)
    {
        ft_rbtforeach_in_two(root, str_length, f);
    }
    else if (order == POSTFIX)
    {
        ft_rbtforeach_post_two(root, str_length, f);
    }
}