/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_basi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:12:37 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/15 17:42:20 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_get_highest(t_stack *s)
{
	t_node	*current;
	t_node	*highest;

	current = s->top;
	highest = current;
	while (current)
	{
		if (current->idx > highest->idx)
			highest = current;
		current = current->next;
	}
	return (highest);
}

void	ft_sort_3(t_stack *a)
{
	t_node	*highest;

	highest = ft_get_highest(a);
	if (a->top == highest)
		ft_ra(a, LOG);
	else if (a->top->next == highest)
		ft_rra(a, LOG);
	if (a->top->idx > a->top->next->idx)
		ft_sa(a, LOG);
}

void	ft_sort_5(t_stack *a, t_stack *b)
{
	if (a->size != 5)
		return ;
	while (a->size > 3)
	{
		if (a->top->idx == 0 || a->top->idx == 1)
			ft_pb(a, b, LOG);
		else
			ft_ra(a, LOG);
	}
	ft_sort_3(a);
	if (b->size == 2 && b->top->idx < b->top->next->idx)
		ft_sb(b, LOG);
	ft_pa(a, b, LOG);
	ft_pa(a, b, LOG);
}

