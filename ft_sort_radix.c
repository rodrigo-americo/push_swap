/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:44:04 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/15 16:10:24 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_radix(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	size = a->size;
	max_bits = ft_get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->idx >> i) & 1) == 0)
				ft_pb(a, b, LOG);
			else
				ft_ra(a, LOG);
			j++;
		}
		while (b->size > 0)
			ft_pa(a, b, LOG);
		i++;
	}
}
