/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:12:29 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/16 16:26:52 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_empty_b(t_stack *a, t_stack *b)
{
	int	max_idx;

	while (b->size > 0)
	{
		max_idx = b->size - 1;
		ft_move_idx_to_top(b, max_idx, LOG);
		ft_pa(a, b, 1);
	}
}

static void ft_do_moves(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
    if (pos_a < (a->size / 2) && pos_b < (b->size / 2))
    {
        while (pos_a > 0 && pos_b > 0)
        {
            ft_rr(a, b, 1);
            pos_a--;
            pos_b--;
        }
        while (pos_a > 0)
            ft_ra(a, 1);
        while (pos_b > 0)
            ft_rb(b, 1);
    }
    else if (pos_a >= (a->size / 2) && pos_b >= (b->size / 2))
    {
        while (pos_a < a->size && pos_b < b->size)
        {
            ft_rrr(a, b, 1);
            pos_a++;
            pos_b++;
        }
        while (pos_a < a->size)
            ft_rra(a, 1);
        while (pos_b < b->size)
            ft_rrb(b, 1);
    }
    else
    {
        while (pos_a < (a->size / 2) && pos_a > 0)
        {
            ft_ra(a, 1);
            pos_a--;
        }
        while (pos_a >= (a->size / 2) && pos_a < a->size)
        {
            ft_rra(a, 1);
            pos_a++;
        }
        while (pos_b < (b->size / 2) && pos_b > 0)
        {
            ft_rb(b, 1);
            pos_b--;
        }
        while (pos_b >= (b->size / 2) && pos_b < b->size)
        {
            ft_rrb(b, 1);
            pos_b++;
        }
    }
}

int ft_find_pos_by_idx(t_stack *s, int target_idx)
{
    t_node *node;
    int pos;

    pos = 0;
    node = s->top;
    while (node && node->idx != target_idx)
    {
        pos++;
        node = node->next;
    }
    return (pos);
}

void	ft_fill_b(t_stack *a, t_stack *b)
{
	t_move	best_move;
	int		pos_a;
	int		pos_b;

	while (a->size > 5)
	{
		best_move = ft_cheapest_move(a, b);
		pos_a = ft_find_pos_by_idx(a, best_move.target_idx_a);
		pos_b = ft_find_pos_by_idx(b, best_move.target_idx_b);
		ft_do_moves(a, b, pos_a, pos_b);
		ft_pb(a, b, 1);
	}
}

void	ft_sort_chunks(t_stack *a, t_stack *b, int chunks)
{
	int	chunk_size;
	int	low;
	int	high;
	int	len_a;

	chunk_size = a->size / chunks;
	low = 0;
	len_a = a->size;
	high = chunk_size - 1;

	while (a->size > 5)
	{
		// Encontra e move o elemento mais barato dentro do chunk atual para B.
		int cheapest_pos = ft_cheapest_pos_to_push(a, low, high);
		if (cheapest_pos != -1)
		{
			ft_rotate_to_top(a, cheapest_pos, LOG);
			ft_pb(a, b, 1);
		}
		// Se todos os elementos do chunk foram movidos, avança para o próximo.
		else
		{
			low = high + 1;
			high += chunk_size;
			if (high >= len_a)
				high = len_a - 1;
		}
	}
	ft_sort_5(a, b); // Ordena os 5 que ficaram
	ft_empty_b(a, b); // Esvazia B
}
