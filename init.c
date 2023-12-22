/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:40:33 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/22 22:34:12 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_program(t_program *program, char **argv)
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
}

void	initialize_mlx(t_program *program)
{
	program->mlx = mlx_init();
	if (!program->mlx)
		exit_handler(program);
}

void	initialize_window(t_program *program, char **argv)
{
	program->win = mlx_new_window(program->mlx, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	if (!program->win)
		exit_handler(program);
	mlx_key_hook(program->win, key_hook, program);
	mlx_mouse_hook(program->win, mouse_hook, program);
	mlx_hook(program->win, 17, 0, exit_handler, program);
}

void	initialize_image(t_program *program)
{
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

void	fractol_init(t_program *program, char **argv)
{
	initialize_program(program, argv);
	initialize_mlx(program);
	initialize_window(program, argv);
	initialize_image(program);
}
