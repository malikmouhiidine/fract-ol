/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:40:40 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/20 23:05:27 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft/libft.h"

#define ERROR_MSG "usage:\n\tfractol mandelbrot\n\tfractol julia <r> <i>\n"

#define WIN_HEIGHT 1200
#define WIN_WIDTH 1200

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_program
{
	void		*mlx;
	void		*win;
	char		*fractol_type;
	int			color_pallete;
	int			max_iteration;
	double		right_x;
	double		left_x;
	double		top_y;
	double		bottom_y;
	t_image		*img;
}	t_program;

void	invalid_args_handler(void);
int		ft_strcmp(char *s1, char *s2);
void	opt_mlx_pixel_put(t_image *img, int x, int y, int color);
double	scale(double number, double inMin, double inMax,
			double outMin, double outMax);

int		close_window(t_program *param);
void	key_hook_helper(int keycode, t_program *program, double offset);
int		key_hook(int keycode, t_program *program);
int		mouse_hook(int keycode, int x, int y, t_program *program);

int		get_color(int iteration, int max_iteration, int color_pallete);
int		generate_color(int max_iteration, double xo, double yo,
			int color_pallete);
