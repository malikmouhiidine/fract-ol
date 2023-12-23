/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:42:54 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/22 22:41:10 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

long double	scale(long double number, long double inMin, long double inMax,
		long double outMin, long double outMax)
{
	long double	scaled_value;

	scaled_value = (number - inMin) * (outMax - outMin);
	scaled_value = scaled_value / (inMax - inMin);
	scaled_value = scaled_value + outMin;
	return (scaled_value);
}

int	exit_handler(t_program *program)
{
	printf("exit_handler\n");
	if (program->img)
		mlx_destroy_image(program->mlx, program->img->img);
	if (program->win && program->mlx)
		mlx_destroy_window(program->mlx, program->win);
	if (program)
		free(program);
	if (program->img)
		free(program->img);
	exit(0);
}

void	opt_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

long double	ft_atoildbl(char *str)
{
	size_t			i;
	long double		res;
	long double		sign;
	long double		decimal_place;

	res = 0L;
	sign = 1;
	i = 0;
	decimal_place = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] == '.')
		{
			decimal_place = 0.1;
			i++;
		}
		if (decimal_place == 1)
			res = res * 10 + (str[i] - '0');
		else
		{
			res = res + (str[i] - '0') * decimal_place;
			decimal_place /= 10;
		}
		i++;
	}
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
