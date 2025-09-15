/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:12:29 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/15 18:21:03 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static void	ft_empty_b(t_stack *a, t_stack *b)
{
	int	max_idx;

	while (b->size > 0)
	{
		max_idx = b->size - 1;
		ft_move_idx_to_top(b, max_idx, LOG);
		ft_pa(a, b, 1);
	}
}

void	ft_sort_chunks(t_stack *a, t_stack *b, int chunks)
{
	int	chunk_size;
	int	low;
	int	high;
	int	len_a;
	int	pos;

	chunk_size = a->size / chunks;
	low = 0;
	len_a = a->size;
	high = chunk_size - 1;
	while (low < len_a)
	{
		while (1)
		{
			pos = ft_cheapest_pos_to_push(a, low, high);
			if (pos == -1)
				break ;
			ft_rotate_to_top(a, pos, LOG);
			ft_pb(a, b, LOG);
		}
		low = high + 1;
		high += chunk_size;
		if (high >= len_a)
			high = a->size - 1;
	}
	ft_empty_b(a, b);
}
