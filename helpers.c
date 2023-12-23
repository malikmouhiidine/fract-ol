/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:42:54 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/23 09:09:06 by mmouhiid         ###   ########.fr       */
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
