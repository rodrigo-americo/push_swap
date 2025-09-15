/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:06:17 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/12 14:18:15 by rgregori         ###   ########.fr       */
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
	t_node	*next_node;

	if (!s || s->size == 0)
		return ;
	node = s->top;
	while (node)
	{
		next_node = node->next;
		ft_printf("%d\n", node->val);
		node = next_node;
	}
}
