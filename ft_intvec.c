/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_intvec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:35:10 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/11 16:11:56 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_intvec_init(t_intvec *v, size_t initial_cap)
{
	if (initial_cap == 0)
		initial_cap = 1;
	v->data = malloc(initial_cap * sizeof(int));
	if (!v->data)
	{
		v->data = NULL;
		v->cap = 0;
		v->len = 0;
		return (false);
	}
	v->cap = initial_cap;
	v->len = 0;
	return (true);
}

static t_bool	ft_intvec_grow(t_intvec *v)
{
	int		*data_temp;
	size_t	new_cap;
	size_t	i;


	if (v->cap == 0)
		new_cap = 1;
	else
		new_cap = v->cap * 2;
	i = 0;
	data_temp = malloc(new_cap * sizeof(int));
	if (!data_temp)
		return (false);
	while (i < v->len)
	{
		data_temp[i] = v->data[i];
		i++;
	}
	free(v->data);
	v->data = data_temp;
	v->cap = new_cap;
	return (true);
}

t_bool	ft_intvec_push(t_intvec *v, int value)
{

	if (!v || !v->data)
		return (false);
	if (v->cap == v->len)
	{
		if (ft_intvec_grow(v) == false)
			return (false);
	}
	v->data[v->len] = value;
	v->len++;
	return (true);
}

void	ft_intvec_free(t_intvec *v)
{
	if (v->data)
		free(v->data);
	v->data = NULL;
	v->cap = 0;
	v->len = 0;
}
