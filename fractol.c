/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:40:33 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/20 04:22:42 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int iteration, int max_iteration)
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

static void	invalid_args_handler(void)
{
	ft_putstr_fd(ERROR_MSG, 2);
	exit(1);
}

int	close_window(t_program *param)
{
	(void)param;
	exit(0);
}

static void	key_hook_helper(int keycode, t_program *program, double offset)
{
	if (keycode == 24)
		program->max_iteration += 10;
	else if (keycode == 27 && program->max_iteration > 10)
		program->max_iteration -= 10;
	else if (keycode == 126)
	{
		program->top_y += offset;
		program->bottom_y += offset;
	}
	else if (keycode == 125)
	{
		program->top_y -= offset;
		program->bottom_y -= offset;
	}
	else if (keycode == 124)
	{
		program->right_x += offset;
		program->left_x += offset;
	}
	else if (keycode == 123)
	{
		program->right_x -= offset;
		program->left_x -= offset;
	}
	else if (keycode == 53)
		exit(0);
}

int	key_hook(int keycode, t_program *program)
{
	double	offset;

	offset = fabs(program->right_x - program->left_x) / 4;
	key_hook_helper(keycode, program, offset);
	return (0);
}

double	scale(double number, double inMin, double inMax,
		double outMin, double outMax)
{
	double	scaled_value;

	scaled_value = (number - inMin) * (outMax - outMin);
	scaled_value = scaled_value / (inMax - inMin);
	scaled_value = scaled_value + outMin;
	return (scaled_value);
}

int	mouse_hook(int keycode, int x, int y, t_program *program)
{
	double	mouse_x_scaled;
	double	mouse_y_scaled;
	double	zoom_factor;

	if (y >= 0 && x >= 0 && (keycode == 5 || keycode == 4))
	{
		mouse_x_scaled = scale(x, 0, WIN_WIDTH, program->left_x,
				program->right_x);
		mouse_y_scaled = scale(y, 0, WIN_HEIGHT, program->top_y,
				program->bottom_y);
		if (keycode == 4)
			zoom_factor = 0.75;
		else
			zoom_factor = 1.25;
		program->left_x = mouse_x_scaled + zoom_factor * (
				program->left_x - mouse_x_scaled);
		program->right_x = mouse_x_scaled + zoom_factor * (
				program->right_x - mouse_x_scaled);
		program->top_y = mouse_y_scaled + zoom_factor * (
				program->top_y - mouse_y_scaled);
		program->bottom_y = mouse_y_scaled + zoom_factor * (
				program->bottom_y - mouse_y_scaled);
	}
	return (0);
}

void	opt_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

static void	render_fractor_helper(t_program *program, int x, int y)
{
	opt_mlx_pixel_put(program->img, x, y,
		generate_color(
			program->max_iteration,
			scale((double)x, 0, 800, program->left_x, program->right_x),
			scale((double)y, 0, 800, program->top_y, program->bottom_y)));
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
	program->max_iteration = 30;
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
