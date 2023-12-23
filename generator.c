/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 05:10:12 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/23 08:40:47 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_mandelbrot_color(t_program *program, t_vars *vars,
			long double xo, long double yo)
{
	while ((vars->x2 + vars->y2) <= 4
		&& vars->iteration < program->max_iteration)
	{
		vars->y = 2 * vars->y * vars->x + yo;
		vars->x = vars->x2 - vars->y2 + xo;
		vars->x2 = vars->x * vars->x;
		vars->y2 = vars->y * vars->y;
		vars->iteration++;
	}
}

void	generate_julia_color(t_program *program, t_vars *vars,
			long double xo, long double yo)
{
	long double	xtemp;

	vars->r = 0;
	while (vars->r * vars->r
		- vars->r < sqrt(program->c_x * program->c_x
			+ program->c_y * program->c_y))
	{
		vars->r += 0.1;
	}
	vars->x = xo;
	vars->y = yo;
	vars->x2 = vars->x * vars->x;
	vars->y2 = vars->y * vars->y;
	while ((vars->x2 + vars->y2) <= vars->r * vars->r
		&& vars->iteration < program->max_iteration)
	{
		xtemp = vars->x2 - vars->y2 + program->c_x;
		vars->y = 2 * vars->x * vars->y + program->c_y;
		vars->x = xtemp;
		vars->x2 = vars->x * vars->x;
		vars->y2 = vars->y * vars->y;
		vars->iteration++;
	}
}

void	generate_burningship_color(t_program *program, t_vars *vars,
			long double xo, long double yo)
{
	while ((vars->x2 + vars->y2) <= 4
		&& vars->iteration < program->max_iteration)
	{
		vars->y = fabsl(2 * vars->y * vars->x + yo);
		vars->x = fabsl(vars->x2 - vars->y2 + xo);
		vars->x2 = vars->x * vars->x;
		vars->y2 = vars->y * vars->y;
		vars->iteration++;
	}
}

int	generate_color(t_program *program, long double xo, long double yo)
{
	t_vars	vars;

	vars.x = 0;
	vars.y = 0;
	vars.x2 = 0;
	vars.y2 = 0;
	vars.r = 0;
	vars.iteration = 0;
	if (!ft_strcmp("mandelbrot", program->fractol_type))
		generate_mandelbrot_color(program, &vars, xo, yo);
	else if (!ft_strcmp("julia", program->fractol_type))
		generate_julia_color(program, &vars, xo, yo);
	else if (!ft_strcmp("burningship", program->fractol_type))
		generate_burningship_color(program, &vars, xo, yo);
	return (get_color(vars.iteration,
			program->max_iteration, program->color_pallete));
}
