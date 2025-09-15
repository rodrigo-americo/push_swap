/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:00:18 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/12 13:17:35 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_free_error(char **s, t_intvec *vals)
{
	if (s)
		ft_free_split(s);
	if (vals)
		ft_intvec_free(vals);
	ft_error();
	return (false);
}

static t_bool	ft_handle_token(t_intvec *vals, char *val_str)
{
	int	num;

	if (ft_is_number(val_str) == false)
		return (false);
	if (ft_atoi_safe(val_str, &num) == false)
		return (false);
	if (ft_intvec_push(vals, num) == false)
		return (false);
	return (true);
}

static t_bool	ft_process_tokens(t_intvec *vals, char **tokens)
{
	int	j;

	j = 0;
	while (tokens[j])
	{
		if (ft_handle_token(vals, tokens[j]) == false)
		{
			ft_free_split(tokens);
			return (false);
		}
		j++;
	}
	ft_free_split(tokens);
	return (true);
}

t_bool	ft_parse_args(int ac, char **av, t_intvec *vals)
{
	int		i;
	char	**temp;

	i = 1;
	while (i < ac)
	{
		temp = ft_split(av[i], ' ');
		if (!temp)
			return (false);
		if (ft_process_tokens(vals, temp) == false)
		{
			ft_free_error(temp, vals);
			return (false);
		}
		i++;
	}
	if (ft_has_duplicates(vals) == true)
		return (false);
	return (true);
}
