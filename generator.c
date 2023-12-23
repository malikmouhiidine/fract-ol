/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 05:10:12 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/23 08:22:52 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	generate_color(t_program *program, long double xo, long double yo)
{
	long double	x;
	long double	y;
	long double	x2;
	long double	y2;
	long double R;
	int		iteration;

	x = 0;
	y = 0;
	x2 = 0;
	y2 = 0;
	iteration = 0;
	
	if (!ft_strcmp("mandelbrot", program->fractol_type))
	{
		while ((x2 + y2) <= 4 && iteration < program->max_iteration)
		{
			y = 2 * y * x + yo;
			x = x2 - y2 + xo;
			x2 = x * x;
			y2 = y * y;
			iteration++;
		}
	}
	else if (!ft_strcmp("julia", program->fractol_type))
	{
		R = 0;
		while (R * R - R < sqrt(program->c_x * program->c_x + program->c_y * program->c_y)) {
			R += 0.1;
		}
		x = xo;
		y = yo;
		x2 = x * x;
		y2 = y * y;
		while ((x2 + y2) <= R * R && iteration < program->max_iteration)
		{
			long double xtemp = x2 - y2 + program->c_x;
			y = 2 * x * y + program->c_y;
			x = xtemp;
			x2 = x * x;
			y2 = y * y;
			iteration++;
		}
	}
	else if (!ft_strcmp("burningship", program->fractol_type))
	{
		while ((x2 + y2) <= 4 && iteration < program->max_iteration)
		{
			y = fabsl(2 * y * x + yo);
			x = fabsl(x2 - y2 + xo);
			x2 = x * x;
			y2 = y * y;
			iteration++;
		}
	}
	return (get_color(iteration, program->max_iteration, program->color_pallete));
}
