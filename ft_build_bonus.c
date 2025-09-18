/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:21:30 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 12:52:49 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_bool	build_nodes(const t_intvec *vals, t_stack *a)
{
	size_t	i;
	t_node	*node;

	i = 0;
	while (i < vals->len)
	{
		node = ft_node_new(vals->data[i]);
		if (!node)
			return (false);
		ft_stack_push_bot(a, node);
		i++;
	}
	return (true);
}

static t_bool	ft_build_stack(const t_intvec *vals, t_stack *a)
{
	t_bool	status;

	if (!vals || !a)
		return (false);
	status = build_nodes(vals, a);
	if (!status)
		return (false);
	return (true);
}

t_stack	*ft_handle_stack(t_intvec *vals)
{
	t_stack		*a;

	a = ft_stack_new('a');
	if (!a)
		return (NULL);
	if (ft_build_stack(vals, a) == false)
		return (NULL);
	return (a);
}
