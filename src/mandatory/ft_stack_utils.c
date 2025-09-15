/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:36:39 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/12 13:45:54 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push_top(t_stack *s, t_node *n)
{
	if (!n)
		return ;
	if (s->size == 0)
	{
		s->top = n;
		s->bot = n;
		n->next = NULL;
		n->prev = NULL;
	}
	else
	{
		n->next = s->top;
		s->top->prev = n;
		s->top = n;
		n->prev = NULL;
	}

	s->size++;
}

void	ft_stack_push_bot(t_stack *s, t_node *n)
{
	if (!n)
		return ;
	if (s->size == 0)
	{
		s->top = n;
		s->bot = n;
		n->next = NULL;
		n->prev = NULL;
	}
	else
	{
		s->bot->next = n;
		n->prev = s->bot;
		n->next = NULL;
		s->bot = n;
	}
	s->size++;
}

t_node	*ft_stack_pop_top(t_stack *s)
{
	t_node	*node;

	if (s->size == 0)
		return (NULL);

	node = s->top;
	s->top = node->next;

	if (s->top)
		s->top->prev = NULL;
	else
		s->bot = NULL;

	s->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*ft_stack_pop_bot(t_stack *s)
{
	t_node	*node;

	if (s->size == 0)
		return (NULL);

	node = s->bot;
	s->bot = node->prev;

	if (s->bot)
		s->bot->next = NULL;
	else
		s->top = NULL;

	s->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
