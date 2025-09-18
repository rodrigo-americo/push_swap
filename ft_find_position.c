/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:30:49 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 11:31:11 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_min_max_in_a(const t_stack *a, int *min_val, int *max_val)
{
	t_node	*cur;

	cur = a->top;
	*min_val = cur->idx;
	*max_val = cur->idx;
	while (cur)
	{
		if (cur->idx < *min_val)
			*min_val = cur->idx;
		if (cur->idx > *max_val)
			*max_val = cur->idx;
		cur = cur->next;
	}
}

static int	ft_pos_first_greater_in_a(const t_stack *a, int value)
{
	t_node	*cur;
	int		pos;
	int		best_pos;
	int		best_idx;

	cur = a->top;
	pos = 0;
	best_pos = -1;
	best_idx = INT_MAX;
	while (cur)
	{
		if (cur->idx > value && cur->idx < best_idx)
		{
			best_idx = cur->idx;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	if (best_pos < 0)
		return (0);
	return (best_pos);
}

int	ft_find_position_in_a(t_stack *a, int value)
{
	int	min_val;
	int	max_val;

	if (!a || !a->top)
		return (0);
	ft_min_max_in_a(a, &min_val, &max_val);
	if (value < min_val || value > max_val)
		return (ft_position_of_min(a));
	return (ft_pos_first_greater_in_a(a, value));
}
