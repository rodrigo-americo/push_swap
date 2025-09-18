/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:54:55 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/16 17:26:02 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_position_in_a(t_stack *a, int value)
{
	t_node	*cur;
	t_node	*best;
	int		pos;
	int		best_pos;
	int		min_val;
	int		max_val;

	if (!a || !a->top)
		return (0);
	cur = a->top;
	best = NULL;
	pos = 0;
	best_pos = 0;
	min_val = cur->idx;
	max_val = cur->idx;

	// acha min e max
	while (cur)
	{
		if (cur->idx < min_val)
			min_val = cur->idx;
		if (cur->idx > max_val)
			max_val = cur->idx;
		cur = cur->next;
	}

	// caso menor que o mínimo → antes do mínimo
	if (value < min_val)
		return (ft_position_of_min(a));

	// caso maior que o máximo → depois do máximo
	if (value > max_val)
		return (ft_position_of_min(a));

	// caso geral → menor valor maior que "value"
	cur = a->top;
	pos = 0;
	while (cur)
	{
		if (cur->idx > value && (!best || cur->idx < best->idx))
		{
			best = cur;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best_pos);
}


t_move	ft_cheapest_move(t_stack *a, t_stack *b)
{
	t_move	calc;
	t_node	*current_b;
	int		current_cost;
	int		pos_a;
	int		pos_b;

	calc.cost = INT_MAX;
	calc.pos_a = 0;
	calc.pos_b = 0;
	current_b = b->top;
	pos_b = 0;
	while (current_b)
	{
		pos_a = ft_find_position_in_a(a, current_b->idx);
		if (pos_a > a->size / 2)
			pos_a = -(a->size - pos_a);
		if (pos_b > b->size / 2)
			pos_b = -(b->size - pos_b);
		current_cost = calculate_cost(pos_a, a->size, pos_b, b->size);
		if (current_cost < calc.cost)
		{
			calc.cost = current_cost;
			calc.pos_a = pos_a;
			calc.pos_b = pos_b;
		}
		current_b = current_b->next;
		pos_b++;
	}
	return (calc);
}


void	ft_execute_move(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
		ft_rr(a, b, LOG);
		pos_a--;
		pos_b--;
	}
	while (pos_a < 0 && pos_b < 0)
	{
		ft_rrr(a, b, LOG);
		pos_a++;
		pos_b++;
	}
	while (pos_a > 0)
	{
		ft_ra(a, LOG);
		pos_a--;
	}
	while (pos_a < 0)
	{
		ft_rra(a, LOG);
		pos_a++;
	}
	while (pos_b > 0)
	{
		ft_rb(b, LOG);
		pos_b--;
	}
	while (pos_b < 0)
	{
		ft_rrb(b, LOG);
		pos_b++;
	}
	ft_pa(a, b, LOG);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_move	best;

	while (a->size > 5)
		ft_pb(a, b, LOG);

	ft_sort_5(a, b);
	while (b->size > 0)
	{
		best = ft_cheapest_move(a, b);
		ft_execute_move(a, b, best.pos_a, best.pos_b);
	}
	ft_align_min_on_top(a);
}
