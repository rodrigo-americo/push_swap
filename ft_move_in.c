/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:43:00 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 11:36:09 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_top(t_stack *s, int pos, int log)
{
	int	up;
	int	down;

	if (!s || s->size < 2 || pos < 0 || pos >= (int)s->size)
		return ;
	if (pos == 0)
		return ;
	up = pos;
	down = s->size - pos;
	if (up <= down)
	{
		while (up--)
		{
			ft_rotate_up(s, log);
		}
	}
	else
	{
		while (down--)
		{
			ft_reverse_rotate(s, log);
		}
	}
}

void	ft_move_idx_to_top(t_stack *s, int target_idx, int log)
{
	int		pos;
	t_node	*node;

	if (!s || s->size < 2 || target_idx < 0)
		return ;
	pos = 0;
	node = s->top;
	while (node && node->idx != target_idx)
	{
		pos++;
		node = node->next;
	}
	if (!node || (pos <= 0 || pos > (int)(s->size - 1)))
		return ;
	ft_rotate_to_top(s, pos, log);
}

static void	ft_update_cheapest(const t_node *node, t_cheapest_ctx *ctx)
{
	int	up;
	int	down;
	int	cost;

	if (!node)
		return ;
	if (node->idx < ctx->limit_low || node->idx > ctx->limit_high)
		return ;
	up = ctx->pos;
	down = ctx->size - ctx->pos;
	if (up < down)
		cost = up;
	else
		cost = down;
	if (cost < ctx->best_cost || (cost == ctx->best_cost
			&& ctx->pos < ctx->best_pos))
	{
		ctx->best_cost = cost;
		ctx->best_pos = ctx->pos;
	}
}

int	ft_cheapest_pos_to_push(const t_stack *s, int limit_low, int limit_high)
{
	t_cheapest_ctx	ctx;
	t_node			*node;

	if (!s || s->size == 0 || limit_low < 0 || limit_low > limit_high)
		return (-1);
	ctx.limit_low = limit_low;
	ctx.limit_high = limit_high;
	ctx.size = (int)s->size;
	ctx.pos = 0;
	ctx.best_cost = 2147483647;
	ctx.best_pos = -1;
	node = s->top;
	while (node)
	{
		ft_update_cheapest(node, &ctx);
		node = node->next;
		ctx.pos++;
	}
	return (ctx.best_pos);
}
