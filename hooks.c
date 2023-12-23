/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 04:59:30 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/23 09:18:58 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_program *program)
{
	long double	offset;

	offset = fabsl(program->right_x - program->left_x) / 16;
	key_hook_helper(keycode, program, offset);
	render_fractor(program);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_program *program)
{
	long double	mouse_x_scaled;
	long double	mouse_y_scaled;
	long double	zoom_factor;

	if (y >= 0 && x >= 0 && (keycode == 5 || keycode == 4))
	{
		mouse_x_scaled = scale(x, WIN_WIDTH, program->left_x,
				program->right_x);
		mouse_y_scaled = scale(y, WIN_HEIGHT, program->top_y,
				program->bottom_y);
		if (keycode == 4)
			zoom_factor = 0.85;
		else
			zoom_factor = 1.15;
		program->left_x = mouse_x_scaled + zoom_factor * (
				program->left_x - mouse_x_scaled);
		program->right_x = mouse_x_scaled + zoom_factor * (
				program->right_x - mouse_x_scaled);
		program->top_y = mouse_y_scaled + zoom_factor * (
				program->top_y - mouse_y_scaled);
		program->bottom_y = mouse_y_scaled + zoom_factor * (
				program->bottom_y - mouse_y_scaled);
		render_fractor(program);
	}
	return (0);
}
