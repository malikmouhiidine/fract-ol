/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 05:10:12 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/20 05:10:13 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, int max_iteration)
{
	int		i;
	int		mapping[16] = {0x421E0F, 0x19071A, 0x09012F, 0x040449, 0x000764,
		0x0C2C8A, 0x1852B1, 0x397DD1, 0x86B5E5, 0xD3ECF8, 0xF1E9BF, 0xF8C95F,
		0xFFAA00, 0xCC8000, 0x995700, 0x6A3403};

	if (iteration < max_iteration && iteration > 0)
	{
		i = iteration % 16;
		return (mapping[i]);
	}
	else
	{
		return (0);
	}
}

int	generate_color(int max_iteration, double xo, double yo)
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
	return (get_color(iteration, max_iteration));
}
