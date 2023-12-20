/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 05:10:12 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/20 06:03:23 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, int max_iteration, int color_pallete)
{
	int		i;
	int		first_pallete[16] = {0x421E0F, 0x19071A, 0x09012F, 0x040449,
		0x000764, 0x0C2C8A, 0x1852B1, 0x397DD1, 0x86B5E5, 0xD3ECF8,
		0xF1E9BF, 0xF8C95F, 0xFFAA00, 0xCC8000, 0x995700, 0x6A3403};
	int		second_pallete[16] = {0xffd1b3, 0xffc680, 0xe5a873, 0xcb8b66,
		0xdb9558, 0x743494, 0x3a1183, 0xccd041, 0x979b05, 0xe15420, 0xf05a7e,
		0xe77992, 0xd3c211, 0x845486, 0xdbf56b, 0x9ba1d3};

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

int	generate_color(int max_iteration, double xo, double yo, int color_pallete)
{
	double	x;
	double	y;
	double	temp_x;
	int		iteration;

	x = 0;
	y = 0;
	iteration = 0;
	while (((x * x) + (y * y)) < 4 && iteration < max_iteration)
	{
		temp_x = (x * x) - (y * y) + xo;
		y = ((2 * y) * x) + yo;
		x = temp_x;
		iteration++;
	}
	return (get_color(iteration, max_iteration, color_pallete));
}
