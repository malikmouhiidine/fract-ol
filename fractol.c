/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:40:33 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/22 17:10:22 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render_fractor_helper(t_program *program, long double x, long double y)
{
	opt_mlx_pixel_put(program->img, x, y,
		generate_color(
			program,
			scale(x, 0, WIN_WIDTH, program->left_x, program->right_x),
			scale(y, 0, WIN_HEIGHT, program->top_y, program->bottom_y)));
}

int	render_fractor(t_program *program)
{
	long double	x;
	long double	y;

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
	mlx_put_image_to_window(program->mlx,
		program->win, program->img->img, 0, 0);
	return (0);
}

void	fractol_init(t_program *program, char **argv)
{
	program->fractol_type = argv[1];
	if (argv[1][0] == 'j')
	{
		program->c_x = ft_atoildbl(argv[2]);
		program->c_y = ft_atoildbl(argv[3]);
	}
	program->color_pallete = 1;
	program->max_iteration = 60;
	program->right_x = 2;
	program->left_x = -2;
	program->top_y = 2;
	program->bottom_y = -2;
	program->mlx = mlx_init();
	if (!program->mlx)
		exit_handler(program);
	program->win = mlx_new_window(program->mlx, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	if (!program->win)
		exit_handler(program);
	mlx_key_hook(program->win, key_hook, program);
	mlx_mouse_hook(program->win, mouse_hook, program);
	mlx_hook(program->win, 17, 0, exit_handler, program);
	program->img->img = mlx_new_image(program->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!program->img->img)
		exit_handler(program);
	program->img->addr = mlx_get_data_addr(program->img->img,
			&program->img->bits_per_pixel,
			&program->img->line_length,
			&program->img->endian);
	if (!program->img->addr)
		exit_handler(program);
}

void	fract_handler(char **argv)
{
	t_program	*program;

	program = (t_program *)malloc(sizeof(t_program));
	if (!program)
		exit_handler(program);
	program->img = (t_image *)malloc(sizeof(t_image));
	if (!program->img)
		exit_handler(program);
	fractol_init(program, argv);
	mlx_loop_hook(program->mlx, render_fractor, program);
	mlx_loop(program->mlx);
}

int	main(int argc, char **argv)
{
	if ((argc == 2 && !ft_strcmp("mandelbrot", argv[1]))
		|| (argc == 4 && !ft_strcmp("julia", argv[1]))
		|| (argc == 2 && !ft_strcmp("burningship", argv[1])))
		fract_handler(argv);
	else
	{
		ft_putstr_fd(ERROR_MSG, 2);
		exit(1);
	}
	return (0);
}
