/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:43:08 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 11:36:51 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack *a)
{
	t_stack	*b;

	if (!a || a->size < 2)
		return ;
	b = ft_stack_new('b');
	if (!b)
		return ;
	if (a->size == 2 && a->top->idx > a->top->next->idx)
		ft_sa(a, LOG);
	else if (a->size == 3)
		ft_sort_3(a);
	else if (a->size <= 5)
		ft_sort_5(a, b);
	else
		turk_sort(a, b);
	if (b)
		ft_stack_clear(&b);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_intvec	vals;

	if (ft_intvec_init(&vals, 16) == false)
		return (ft_error());
	if (argc == 1)
		return (0);
	if (ft_parse_args(argc, argv, &vals) == false)
	{
		ft_intvec_free(&vals);
		return (1);
	}
	a = ft_handle_stack(&vals);
	if (!a)
	{
		ft_stack_clear(&a);
		ft_intvec_free(&vals);
		return (ft_error());
	}
	ft_sort_stack(a);
	ft_stack_clear(&a);
	ft_intvec_free(&vals);
	return (0);
}
