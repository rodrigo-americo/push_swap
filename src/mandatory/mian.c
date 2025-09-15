/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:43:08 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/13 15:06:58 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_free_error(char **c, int *vals)
{
	ft_free_temp(c);
	ft_free_vals(vals);
	return (false);
}

void	ft_sort_3(t_stack *a);
void	ft_sort_5(t_stack *a, t_stack *b);

void ft_sort_3(t_stack *a)
{
    int top_idx;
    int mid_idx;
    int bot_idx;

    if (!a || a->size <= 1 || ft_is_sorted(a))
        return ;
    top_idx = a->top->idx;
    mid_idx = a->top->next->idx;
    bot_idx = a->bot->idx;
    if (top_idx == 2 && mid_idx == 0 && bot_idx == 1)
    {
        ft_ra(a, 1);
        ft_sa(a, 1);
    }
    else if (top_idx == 1 && mid_idx == 0 && bot_idx == 2)
        ft_sa(a, 1);
    else if (top_idx == 1 && mid_idx == 2 && bot_idx == 0)
        ft_rra(a, 1);
    else if (top_idx == 2 && mid_idx == 1 && bot_idx == 0)
    {
        ft_ra(a, 1);
        ft_sa(a, 1);
        ft_rra(a, 1);
    }
    else if (top_idx == 0 && mid_idx == 2 && bot_idx == 1)
    {
        ft_ra(a, 1);
        ft_sa(a, 1);
    }
}

static t_bool build_nodes(const t_intvec *vals, t_stack *a, int *sorted)
{
    size_t  i;
    t_node  *node;
    int     idx;

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

t_bool ft_build_stack_a(const t_intvec *vals, t_stack *a)
{
    int *sorted;
    t_bool status;

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
	if (ft_build_stack_a(vals, a) == false)
		return (NULL);
	return (a);
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
	ft_stack_clear(&a);
	ft_intvec_free(&vals);
	return (0);
}
