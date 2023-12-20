/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 05:10:12 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/21 00:15:44 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, int max_iteration, int color_pallete)
{
	int		i;
	int		first_pallete[16] = {0x421E0F, 0x19071A, 0x09012F, 0x040449,
		0x000764, 0x0C2C8A, 0x1852B1, 0x397DD1, 0x86B5E5, 0xD3ECF8,
		0xF1E9BF, 0xF8C95F, 0xFFAA00, 0xCC8000, 0x995700, 0x6A3403};
	int		second_pallete[16] = {0x421E3F, 0x19074A, 0x09015F, 0x040499,
		0x0007A4, 0x0C2CCA, 0x1852F3, 0x397DF3, 0x86B5F6, 0xD3ECF9,
		0xF1E9EF, 0xF8C99F, 0xFFAA51, 0xCC8051, 0x995751, 0x6A3454};

	if (iteration < max_iteration && iteration > 0)
	{
		i = iteration % 16;
		if (color_pallete == 1)
			return (first_pallete[i]);
		else if (color_pallete == 2)
			return (second_pallete[i]);
		else
			return (0);
	}
	else
	{
		return (0);
	}
}

int	generate_color(int max_iteration, long double xo, long double yo, int color_pallete)
{
	long double	x;
	long double	y;
	long double	x2;
	long double	y2;
	int		iteration;

	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	iteration = 0;
	while ((x2 + y2) <= 4 && iteration < max_iteration)
	{
		y = 2 * y * x + yo;
		x = x2 - y2 + xo;
		x2 = x * x;
		y2 = y * y;
		iteration++;
	}
	return (get_color(iteration, max_iteration, color_pallete));
}
