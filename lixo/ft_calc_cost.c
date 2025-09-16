/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:37:29 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/16 16:54:20 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_target_pos_b(t_stack *b, int val_a)
{
    t_node  *node;
    int     pos;
    int     best_pos;
    int     best_val;

    if (!b || b->size == 0)
        return (0);
    pos = 0;
    best_pos = -1;
    best_val = INT_MIN;
    node = b->top;
    
    while (node)
    {
        if (node->val < val_a && node->val > best_val)
        {
            best_val = node->val;
            best_pos = pos;
        }
        pos++;
        node = node->next;
    }
    // Se nenhum valor em b for menor que val_a,
    // significa que val_a é o menor de todos.
    if (best_pos == -1)
    {
        pos = 0;
        best_val = INT_MAX; // Encontra o menor valor em b
        node = b->top;
        while (node)
        {
            if (node->val < best_val)
            {
                best_val = node->val;
                best_pos = pos;
            }
            pos++;
            node = node->next;
        }
    }
    return (best_pos);
}

int	calculate_cost(int pos_a, int size_a, int pos_b, int size_b)
{
	int	cost;
	int	cost_a;
	int	cost_b;

	if (pos_a < (size_a / 2))
		cost_a = pos_a;
	else
		cost_a = size_a - pos_a;
	if (pos_b < (size_b / 2))
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	if ((pos_a < (size_a / 2) && pos_b < (size_b / 2))
		|| (pos_a >= (size_a / 2) && pos_b >= (size_b / 2)))
	{
		if (cost_a > cost_b)
			cost = cost_a;
		else
			cost = cost_b;
	}
	else
		cost = cost_a + cost_b;
	return (cost);
}

int	ft_find_position_in_a(t_stack *s, int pos)
{
	t_node	*node;
	int		i;

	i = 0;
	node = s->top;
	while (node && i < pos)
	{
		node = node->next;
		i++;
	}
	if (node)
		return (i);
	return (-1);
}

t_move ft_cheapest_move(t_stack *a, t_stack *b)
{
    t_move  calc;
    t_node  *current_a;
    int     pos_a;
    int     pos_b;
    
    calc.cost = INT_MAX;
    calc.target_idx_a = -1;
    calc.target_idx_b = -1;
    current_a = a->top;
    pos_a = 0;
    while (current_a)
    {
        pos_b = find_target_pos_b(b, current_a->val);
        int current_cost = calculate_cost(pos_a, a->size, pos_b, b->size);
        if (current_cost < calc.cost)
        {
            calc.cost = current_cost;
            calc.target_idx_a = current_a->idx;
            calc.target_idx_b = ft_find_idx_by_pos(b, pos_b); // Corrigido
        }
        current_a = current_a->next;
        pos_a++;
    }
    return (calc);
}
