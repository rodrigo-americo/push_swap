/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:12:03 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 14:30:40 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

t_bool	ft_atoi_safe(const char *s, int *out)
{
	int			i;
	long long	result;
	int			sign;

	result = 0;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	sign = ft_sign(s, &i);
	if (s[i] < '0' || s[i] > '9')
		return (false);
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		if (sign > 0 && result > INT_MAX)
			return (false);
		if (sign < 0 && result > (-(long long)INT_MIN))
			return (false);
		i++;
	}
	result *= sign;
	*out = (int)result;
	return (true);
}
