/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:46:31 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 16:18:19 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

static void	ft_make_r_moves(t_stack *a, t_stack *b, char *line)

{
	if (ft_strncmp(line, "rra", 3) == 0)
		ft_rra(a, LOG);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		ft_rrb(b, LOG);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		ft_rrr(a, b, LOG);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ft_ra(a, LOG);
	else if (ft_strncmp(line, "rb", 2) == 0)
		ft_rb(b, LOG);
	else if (ft_strncmp(line, "rr", 2) == 0)
		ft_rr(a, b, LOG);
}

t_bool	ft_make_move(t_stack *a, t_stack *b, char *line)
{
	t_bool	has_move;

	has_move = true;
	if (ft_strncmp(line, "sa", 2) == 0)
		ft_sa(a, LOG);
	else if (ft_strncmp(line, "sb", 2) == 0)
		ft_sb(b, LOG);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ft_ss(a, b, LOG);
	else if (ft_strncmp(line, "pa", 2) == 0)
		ft_pa(a, b, LOG);
	else if (ft_strncmp(line, "pb", 2) == 0)
		ft_pb(a, b, LOG);
	else if (ft_strncmp(line, "r", 1) == 0)
		ft_make_r_moves(a, b, line);
	else
		has_move = false;
	return (has_move);
}

t_bool	ft_cheker(t_stack *a)
{
	t_stack	*b;
	char	*line;
	t_bool	is_ok;

	b = ft_stack_new('b');
	if (!b)
		return (false);
	is_ok = true;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_make_move(a, b, line) == false)
		{
			is_ok = false;
			break ;
		}
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	if (b)
		ft_stack_clear(&b);
	return (is_ok);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_intvec	vals;

	if (argc == 1)
		return (0);
	if (ft_intvec_init(&vals, 16) == false)
		return (ft_error());
	if (ft_parse_args(argc, argv, &vals) == false)
		return (ft_handle_clean_vals_error(&vals));
	a = ft_handle_stack(&vals);
	if (!a)
		return (ft_handle_clean_error(a, &vals));
	if (ft_is_sorted(a) == true)
	{
		write(1, "OK\n", 3);
		return (ft_handle_clean(a, &vals));
	}
	if (ft_cheker(a) == false)
		return (ft_handle_clean_error(a, &vals));
	if (ft_is_sorted(a) == true)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_handle_clean(a, &vals));
}
