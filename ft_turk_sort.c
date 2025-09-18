/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:54:55 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 11:36:38 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	ft_move_for_b_node(t_stack *a, t_stack *b,
			int raw_pos_b, int idx_b)
{
	t_move	move;
	int		raw_pos_a;
	int		pos_a;
	int		pos_b;

	raw_pos_a = ft_find_position_in_a(a, idx_b);
	pos_a = raw_pos_a;
	if (pos_a > a->size / 2)
		pos_a = -(a->size - pos_a);
	pos_b = raw_pos_b;
	if (pos_b > b->size / 2)
		pos_b = -(b->size - pos_b);
	move.pos_a = pos_a;
	move.pos_b = pos_b;
	move.cost = calculate_cost(pos_a, a->size, pos_b, b->size);
	return (move);
}

t_move	ft_cheapest_move(t_stack *a, t_stack *b)
{
	t_move	best;
	t_move	cand;
	t_node	*cur;
	int		i;

	best.cost = INT_MAX;
	best.pos_a = 0;
	best.pos_b = 0;
	if (!b || !b->top || b->size <= 0)
		return (best);
	cur = b->top;
	i = 0;
	while (cur)
	{
		cand = ft_move_for_b_node(a, b, i, cur->idx);
		if (cand.cost < best.cost)
			best = cand;
		cur = cur->next;
		i++;
	}
	return (best);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_move	best;

	while (a->size > 3)
		ft_pb(a, b, LOG);
	ft_sort_3(a);
	while (b->size > 0)
	{
		best = ft_cheapest_move(a, b);
		ft_execute_move(a, b, &best);
	}
	ft_align_min_on_top(a);
}
