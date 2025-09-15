/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:32:29 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/13 11:52:16 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, int log)
{
	t_node	*node;

	if (!a || a->size < 2)
		return ;
	node = ft_stack_pop_top(a);
	ft_stack_push_bot(a, node);
	if (log == 1)
		ft_printf("ra\n");
}

void	ft_rb(t_stack *b, int log)
{
	t_node	*node;

	if (!b || b->size < 2)
		return ;
	node = ft_stack_pop_top(b);
	ft_stack_push_bot(b, node);
	if (log == 1)
		ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b, int log)
{
	int	has_a;
	int	has_b;

	has_a = (!a || a->size < 2);
	has_b = (!b || b->size < 2);
	if (!has_a && !has_b)
		return ;
	if (has_a)
		ft_ra(a, 0);
	if (has_b)
		ft_rb(b, 0);
	if (log == 1 && (has_a && has_b))
		write(1, "rr\n", 4);
}
