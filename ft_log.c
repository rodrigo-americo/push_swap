/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:06:17 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/15 14:38:24 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	ft_print_stack(const t_stack *s)
{
	t_node	*node;

	if (!s || s->size == 0)
		return ;
	node = s->top;
	while (node)
	{
		ft_putnbr_fd(node->val, 1);
		node = node->next;
	}
}
