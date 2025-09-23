/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_basi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:12:37 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 11:37:15 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_rotate_single(t_stack *stack, char direction)
{
    t_node *node;

    if (!stack || stack->size < 2)
        return;

    if (direction == 'f')
    {
        node = ft_stack_pop_top(stack);
        ft_stack_push_bot(stack, node);
    }
    else if (direction == 'b')
    {
        node = ft_stack_pop_bot(stack);
        ft_stack_push_top(stack, node);
    }
}

static t_bool	ft_swap_top(t_stack *s)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;
	t_bool	did_swap;

	did_swap = false;
	if (s->size < 2)
		return (did_swap);
	did_swap = true;
	n1 = s->top;
	n2 = n1->next;
	n3 = n2->next;
	s->top = n2;
	n2->prev = NULL;
	n2->next = n1;
	n1->prev = n2;
	n1->next = n3;
	if (n3 != NULL)
		n3->prev = n1;
	else
		s->bot = n1;
	return (did_swap);
}

void ft_move_rr(t_stack *a, t_stack *b, char move)
{
    if (move == 'a')
    {
        ft_rotate_single(a, 'b');
        write(1, "rra\n", 4);
    }
    else if (move == 'b')
    {
        ft_rotate_single(b, 'b');
        write(1, "rrb\n", 4);
    }
    else if (move == 'r')
    {
        ft_rotate_single(a, 'b');
        ft_rotate_single(b, 'b');
        write(1, "rrr\n", 4);
    }
}

void ft_move_r(t_stack *a, t_stack *b, char move)
{
    if (move == 'a')
    {
        ft_rotate_single(a, 'f');
        write(1, "ra\n", 3);
    }
    else if (move == 'b')
    {
        ft_rotate_single(b, 'f');
        write(1, "rb\n", 3);
    }
    else if (move == 'r')
    {
        ft_rotate_single(a, 'f');
        ft_rotate_single(b, 'f');
        write(1, "rr\n", 3);
    }
}

void ft_move_s(t_stack *a, t_stack *b, char move)
{
    if (move == 'a')
    {
        ft_swap_top(a);
        write(1, "sa\n", 3);
    }
    else if (move == 'b')
    {
        ft_swap_top(b);
        write(1, "sb\n", 3);
    }
    else if (move == 'r')
    {
        ft_swap_top(a);
        ft_swap_top(b);
        write(1, "ss\n", 3);
    }
}
