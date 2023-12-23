/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoildbl_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:42:54 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/23 09:11:49 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	skip_whitespace(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

long double	process_digits(char *str, size_t *i, long double decimal_place)
{
	long double	res;

	res = 0L;
	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '.')
	{
		if (str[*i] == '.')
		{
			decimal_place = 0.1;
			(*i)++;
		}
		if (decimal_place == 1)
			res = res * 10 + (str[*i] - '0');
		else
		{
			res = res + (str[*i] - '0') * decimal_place;
			decimal_place /= 10;
		}
		(*i)++;
	}
	return (res);
}

long double	ft_atoildbl(char *str)
{
	size_t			i;
	long double		res;
	long double		sign;
	long double		decimal_place;

	res = 0L;
	sign = 1;
	decimal_place = 1;
	i = skip_whitespace(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = process_digits(str, &i, decimal_place);
	return (res * sign);
}

int	is_valid_double(char *str)
{
	size_t	i;
	int		dot_count;

	i = 0;
	dot_count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		if (dot_count > 1)
			return (0);
		if (str[i] == '-' || str[i] == '+')
		{
			if (i != 0)
				return (0);
		}
		else if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}
