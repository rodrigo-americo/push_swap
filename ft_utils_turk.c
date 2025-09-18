/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_turk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:19:02 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 11:17:41 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(int pos_a, int size_a, int pos_b, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (pos_a > size_a / 2)
		pos_a = -(size_a - pos_a);
	if (pos_b > size_b / 2)
		pos_b = -(size_b - pos_b);
	if (pos_a >= 0)
		cost_a = pos_a;
	else
		cost_a = -pos_a;
	if (pos_b >= 0)
		cost_b = pos_b;
	else
		cost_b = -pos_b;
	if ((pos_a >= 0 && pos_b >= 0) || (pos_a < 0 && pos_b < 0))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

int	ft_position_of_min(t_stack *a)
{
	t_node	*cur;
	int		min_val;
	int		min_pos;
	int		i;

	if (!a || !a->top)
		return (-1);
	cur = a->top;
	min_val = cur->idx;
	min_pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->idx < min_val)
		{
			min_val = cur->idx;
			min_pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_pos);
}

void	ft_align_min_on_top(t_stack *a)
{
	int	pos;
	int	size;

	if (!a || a->size < 2)
		return ;
	size = a->size;
	pos = ft_position_of_min(a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ft_ra(a, LOG);
	}
	else
	{
		while (pos++ < size)
			ft_rra(a, LOG);
	}
}

static void	ft_execute_doble_move(t_stack *a, t_stack *b, t_move *best)
{
	while (best->pos_a > 0 && best->pos_b > 0)
	{
		ft_rr(a, b, LOG);
		best->pos_a--;
		best->pos_b--;
	}
	while (best->pos_a < 0 && best->pos_b < 0)
	{
		ft_rrr(a, b, LOG);
		best->pos_a++;
		best->pos_b++;
	}
}

void	ft_execute_move(t_stack *a, t_stack *b, t_move *best)
{
	ft_execute_doble_move(a, b, best);
	while (best->pos_a > 0)
	{
		ft_ra(a, LOG);
		best->pos_a--;
	}
	while (best->pos_a < 0)
	{
		ft_rra(a, LOG);
		best->pos_a++;
	}
	while (best->pos_b > 0)
	{
		ft_rb(b, LOG);
		best->pos_b--;
	}
	while (best->pos_b < 0)
	{
		ft_rrb(b, LOG);
		best->pos_b++;
	}
	ft_pa(a, b, LOG);
}
