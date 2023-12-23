/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 04:59:30 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/23 08:45:26 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_max_iteration(int keycode, t_program *program)
{
	if (keycode == 24)
		program->max_iteration += 10;
	else if (keycode == 27 && program->max_iteration > 10)
		program->max_iteration -= 10;
}

void	handle_y_movement(int keycode, t_program *program, long double offset)
{
	if (keycode == 126)
	{
		program->top_y += offset;
		program->bottom_y += offset;
	}
	else if (keycode == 125)
	{
		program->top_y -= offset;
		program->bottom_y -= offset;
	}
}

void	handle_x_movement(int keycode, t_program *program, long double offset)
{
	if (keycode == 124)
	{
		program->right_x += offset;
		program->left_x += offset;
	}
	else if (keycode == 123)
	{
		program->right_x -= offset;
		program->left_x -= offset;
	}
}

void	handle_color_pallete(int keycode, t_program *program)
{
	if (keycode == 8)
	{
		if (program->color_pallete == 1)
			program->color_pallete = 2;
		else
			program->color_pallete = 1;
	}
}

void	key_hook_helper(int keycode, t_program *program, long double offset)
{
	handle_max_iteration(keycode, program);
	handle_y_movement(keycode, program, offset);
	handle_x_movement(keycode, program, offset);
	handle_color_pallete(keycode, program);
	if (keycode == 53)
		exit_handler(program);
}
