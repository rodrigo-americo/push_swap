/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:45:07 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/15 17:45:50 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_swap_top(t_stack *s)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;
	t_bool	did_swap;

	did_swap = false;
	if (s->size < 2)
		return (did_swap);
	did_swap = true;
	n1 = s->top;
	n2 = n1->next;
	n3 = n2->next;
	s->top = n2;
	n2->prev = NULL;
	n2->next = n1;
	n1->prev = n2;
	n1->next = n3;
	if (n3 != NULL)
		n3->prev = n1;
	else
		s->bot = n1;
	return (did_swap);
}

void	ft_sa(t_stack *a, int log)
{
	t_bool	swap;

	if (!a)
		return ;
	swap = ft_swap_top(a);
	if (log == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, int log)
{
	t_bool	swap;

	if (!b)
		return ;
	swap = ft_swap_top(b);
	if (log == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b, int log)
{
	t_bool	swap_a;
	t_bool	swap_b;

	if (!a || !b)
		return ;
	swap_a = ft_swap_top(a);
	swap_b = ft_swap_top(b);
	if (log == 1)
		write(1, "ss\n", 3);
}
