#include "push_swap.h"

t_bool ft_is_sorted(const t_stack *s)
{
    t_node *node;

    if (!s || s->size <= 1)
        return (true);
    node = s->top;
    while (node->next)
    {
        if (node->idx > node->next->idx)
            return (false);
        node = node->next;
    }
    return (true);
}

int ft_min_idx(const t_stack *s)
{
    t_node *node;
    int    min_idx;

    if (!s || s->size <= 0)
        return (-1);
    
    node = s->top;
    min_idx = node->idx;
    
    while (node)
    {
        if (node->idx < min_idx)
            min_idx = node->idx;
        node = node->next;
    }
    return (min_idx);
}

int ft_max_idx(const t_stack *s)
{
    t_node *node;
    int    max_idx;

    if (!s || s->size <= 0)
        return (-1);
    
    node = s->top;
    max_idx = node->idx;
    
    while (node)
    {
        if (node->idx > max_idx)
            max_idx = node->idx;
        node = node->next;
    }
    return (max_idx);
}

int ft_pos_of_idx(const t_stack *s, int idx)
{
    t_node  *node;
    int     pos;

    if (!s || s->size <= 0)
        return (-1);

    node = s->top;
    pos = 0;
    while (node)
    {
        if (node->idx == idx)
            return (pos);
        node = node->next;
        pos++;
    }
    return (-1);
}