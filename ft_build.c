/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:21:30 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/15 16:13:09 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	build_nodes(const t_intvec *vals, t_stack *a, int *sorted)
{
	size_t	i;
	t_node	*node;
	int		idx;

	i = 0;
	while (i < vals->len)
	{
		idx = ft_normalize_indice(sorted, vals->len, vals->data[i]);
		if (idx == -1)
			return (false);
		node = ft_node_new(vals->data[i], idx);
		if (!node)
			return (false);
		ft_stack_push_bot(a, node);
		i++;
	}
	return (true);
}

static t_bool	ft_build_stack(const t_intvec *vals, t_stack *a)
{
	int		*sorted;
	t_bool	status;

	if (!vals || !a)
		return (false);
	sorted = ft_copy_data(vals->data, vals->len);
	if (!sorted)
		return (false);
	ft_sort_int_tab(sorted, vals->len);
	status = build_nodes(vals, a, sorted);
	free(sorted);
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
