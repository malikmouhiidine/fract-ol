/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:40:33 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/23 08:42:52 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render_fractor_helper(t_program *program,
		long double x, long double y)
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
	render_fractor(program);
	mlx_loop(program->mlx);
}

int	main(int argc, char **argv)
{
	if ((argc == 2 && !ft_strcmp("mandelbrot", argv[1]))
		|| (argc == 4 && !ft_strcmp("julia", argv[1])
			&& is_valid_double(argv[2])
			&& is_valid_double(argv[3]))
		|| (argc == 2 && !ft_strcmp("burningship", argv[1])))
		fract_handler(argv);
	else
	{
		ft_putstr_fd(ERROR_MSG, 2);
		exit(1);
	}
	return (0);
}
