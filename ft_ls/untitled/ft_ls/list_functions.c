//
// Created by Christop Reek on 2019-04-08.
//

#include "ft_ls.h"


t_list          *ft_lstnew(void const *content, size_t content_size)
{
    t_list  *elem;

    elem = (t_list *)ft_memalloc(sizeof(t_list));
    if (elem == NULL)
        return (NULL);
    if (content == NULL)
    {
        content_size = 0;
        elem->content = NULL;
    }
    else
    {
        elem->content = ft_memalloc(content_size);
        if (elem->content == NULL)
        {
            ft_memdel((void **)&elem);
            return (NULL);
        }
        ft_memcpy(elem->content, content, content_size);
    }
    elem->content_size = content_size;
    elem->next = NULL;
    return (elem);
}

void		free_list(t_list *head)
{
    t_list	*temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void		ft_listadd_to_end(t_list **begin_list, t_list *new)
{
    t_list	*current;

    current = *begin_list;
    if (current == NULL)
        *begin_list = new;
    else
    {
        while (current->next)
            current = current->next;
        current->next = new;
    }
}