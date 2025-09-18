/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movep copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:51:05 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 14:29:14 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_pa(t_stack *a, t_stack *b, int log)
{
	t_node	*node;

	if (b->size == 0)
		return ;
	node = ft_stack_pop_top(b);
	ft_stack_push_top(a, node);
	if (log == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b, int log)
{
	t_node	*node;

	if (a->size == 0)
		return ;
	node = ft_stack_pop_top(a);
	ft_stack_push_top(b, node);
	if (log == 1)
		write(1, "pb\n", 3);
}
