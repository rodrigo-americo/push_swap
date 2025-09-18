/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:14:19 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 15:40:19 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_bool	ft_is_sorted(const t_stack *s)
{
	t_node	*node;

	if (!s || s->size <= 1)
		return (true);
	node = s->top;
	while (node->next)
	{
		if (node->val > node->next->val)
			return (false);
		node = node->next;
	}
	return (true);
}
