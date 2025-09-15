/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:07:34 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/12 13:46:46 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(char name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = name;
	stack->bot = NULL;
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	ft_stack_clear(t_stack **s)
{
	t_node	*current;
	t_node	*next_node;

	if (!s || !*s)
		return ;
	current = (*s)->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(*s);
	(*s) = NULL;
}
