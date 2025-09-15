/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:20:23 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/15 13:13:37 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_normalize_indice(int *sorted, int len, int val)
{
	size_t	low;
	size_t	high;
	size_t	mid;

	if (len == 0)
		return (-1);
	low = 0;
	high = len - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (sorted[mid] == val)
			return ((int)mid);
		else if (sorted[mid] < val)
			low = mid + 1;
		else
		{
			if (mid == 0)
				break ;
			high = mid - 1;
		}
	}
	return (-1);
}

int	ft_get_max_bits(const t_stack *a)
{
	int		max;
	int		bits;
	t_node	*node;

	node = a->top;
	max = 0;
	while (node)
	{
		if (node->idx > max)
			max = node->idx;
		node = node->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
