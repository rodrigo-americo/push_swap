/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:46:02 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 16:16:43 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_handle_clean_error(t_stack *a, t_intvec *vals)
{
	ft_stack_clear(&a);
	ft_intvec_free(vals);
	return (ft_error());
}

int	ft_handle_clean_vals_error(t_intvec *vals)
{
	ft_intvec_free(vals);
	return (ft_error());
}

int	ft_handle_clean(t_stack *a, t_intvec *vals)
{
	ft_stack_clear(&a);
	ft_intvec_free(vals);
	return (0);
}
