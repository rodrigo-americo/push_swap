/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_r_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:32:29 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 14:29:56 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_ra(t_stack *a, int log)
{
	t_node	*node;

	if (!a || a->size < 2)
		return ;
	node = ft_stack_pop_top(a);
	ft_stack_push_bot(a, node);
	if (log == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b, int log)
{
	t_node	*node;

	if (!b || b->size < 2)
		return ;
	node = ft_stack_pop_top(b);
	ft_stack_push_bot(b, node);
	if (log == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b, int log)
{
	int	ok_a;
	int	ok_b;

	ok_a = (a && a->size > 1);
	ok_b = (b && b->size > 1);
	if (ok_a)
		ft_ra(a, 0);
	if (ok_b)
		ft_rb(b, 0);
	if (log && ok_a && ok_b)
		write(1, "rr\n", 3);
}
