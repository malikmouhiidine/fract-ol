/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:40:33 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/20 19:28:08 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render_fractor_helper(t_program *program, int x, int y)
{
	opt_mlx_pixel_put(program->img, x, y,
		generate_color(
			program->max_iteration,
			scale((double)x, 0, WIN_WIDTH, program->left_x, program->right_x),
			scale((double)y, 0, WIN_HEIGHT, program->top_y, program->bottom_y),
			program->color_pallete));
}

int	render_fractor(t_program *program)
{
	int	x;
	int	y;

	if (!ft_strcmp("mandelbrot", program->fractol_type))
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			x = 0;
			while (x < WIN_WIDTH)
			{
				render_fractor_helper(program, x, y);
				x++;
			}
			y++;
		}
	}
	mlx_put_image_to_window(program->mlx,
		program->win, program->img->img, 0, 0);
	return (0);
}

void	fractol_init(t_program *program, char **argv)
{
	program->fractol_type = argv[1];
	program->color_pallete = 1;
	program->max_iteration = 70;
	program->right_x = 2;
	program->left_x = -2;
	program->top_y = 2;
	program->bottom_y = -2;
	program->mlx = mlx_init();
	program->win = mlx_new_window(program->mlx, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	mlx_key_hook(program->win, key_hook, program);
	mlx_mouse_hook(program->win, mouse_hook, program);
	mlx_hook(program->win, 17, 0, close_window, program);
	program->img->img = mlx_new_image(program->mlx, WIN_WIDTH, WIN_HEIGHT);
	program->img->addr = mlx_get_data_addr(program->img->img,
			&program->img->bits_per_pixel,
			&program->img->line_length,
			&program->img->endian);
}

void	fract_handler(char **argv)
{
	t_program	*program;

	program = (t_program *)malloc(sizeof(t_program));
	program->img = (t_image *)malloc(sizeof(t_image));
	fractol_init(program, argv);
	mlx_loop_hook(program->mlx, render_fractor, program);
	mlx_loop(program->mlx);
}

int	main(int argc, char **argv)
{
	if ((argc == 2 && !ft_strcmp("mandelbrot", argv[1]))
		|| (argc == 4 && !ft_strcmp("julia", argv[1])))
		fract_handler(argv);
	else
		invalid_args_handler();
	return (0);
}
