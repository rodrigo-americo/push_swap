/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:51:05 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/13 11:34:46 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, int log)
{
	t_node	*node;

	if (!a || a->size < 2)
		return ;
	node = ft_stack_pop_bot(a);
	ft_stack_push_top(a, node);
	if (log == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b, int log)
{
	t_node	*node;

	if (!b || b->size < 2)
		return ;
	node = ft_stack_pop_bot(b);
	ft_stack_push_top(b, node);
	if (log == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b, int log)
{
	int	has_a;
	int	has_b;

	has_a = (!a || a->size < 2);
	has_b = (!b || b->size < 2);
	if (!has_a && !has_b)
		return ;
	if (has_a)
		ft_rra(a, 0);
	if (has_b)
		ft_rrb(b, 0);
	if (log == 1 && (has_a && has_b))
		write(1, "rrr\n", 4);
}
