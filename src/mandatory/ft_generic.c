/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:39:59 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/13 13:03:45 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_up(t_stack *s, int log)
{
	if (!s || s->size < 2)
		return ;
	if (s->name == 'a')
		ft_ra(s, log);
	else if (s->name == 'b')
		ft_rb(s, log);
}

void	ft_reverse_rotate(t_stack *s, int log)
{
	if (!s || s->size < 2)
		return ;
	if (s->name == 'a')
		ft_rra(s, log);
	else if (s->name == 'b')
		ft_rrb(s, log);
}
