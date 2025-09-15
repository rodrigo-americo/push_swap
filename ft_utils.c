/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:46:02 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/15 16:39:17 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_is_number(const char *s)
{
	int	i;
	int	has_digit;

	if (s[0] == '\0')
		return (false);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	has_digit = false;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
		has_digit = true;
		i++;
	}
	return (has_digit);
}

void	ft_free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
