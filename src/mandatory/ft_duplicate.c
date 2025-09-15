/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:31:42 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/13 14:57:54 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	hold;

	hold = *a;
	*a = *b ;
	*b = hold;
}

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < size)
	{
		swapped = 0;
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
		{
			break ;
		}
		i++;
	}
}

int	*ft_copy_data(int *data, int len)
{
	int		*cop;
	size_t	i;

	cop = malloc(len * sizeof(int));
	if (!cop)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cop[i] = data[i];
		i++;
	}
	return (cop);
}

t_bool	ft_has_duplicates(const t_intvec *v)
{
	int			*cop;
	t_bool		has_cop;
	size_t		i;

	if (v->len < 2)
		return (false);
	cop = ft_copy_data(v->data, v->len);
	if (!cop)
		ft_error_and_exit();
	has_cop = false;
	i = 0;
	ft_sort_int_tab(cop, v->len);
	while (i < v->len - 1)
	{
		if (cop[i] == cop[i + 1])
		{
			has_cop = true;
			break ;
		}
		i++;
	}
	free(cop);
	return (has_cop);
}
