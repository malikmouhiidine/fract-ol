/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:40:40 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/22 17:39:14 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft/libft.h"

#define ERROR_MSG "usage:\n\tfractol mandelbrot\n\tfractol julia <r> <i>\n\tfractol burningship\n"

#define WIN_HEIGHT 800
#define WIN_WIDTH 800

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
	void			*mlx;
	void			*win;
	char			*fractol_type;
	int				color_pallete;
	int				max_iteration;
	long double		right_x;
	long double		left_x;
	long double		top_y;
	long double		bottom_y;
	long double		c_x;
	long double		c_y;
	t_image			*img;
}	t_program;

long double ft_atoildbl(char *str);
int 		exit_handler(t_program *program);
int			ft_strcmp(char *s1, char *s2);
void		opt_mlx_pixel_put(t_image *img, int x, int y, int color);
long double	scale(long double number, long double inMin, long double inMax,
			long double outMin, long double outMax);
int			close_window(t_program *param);
void		key_hook_helper(int keycode, t_program *program, long double offset);
int			key_hook(int keycode, t_program *program);
int			mouse_hook(int keycode, int x, int y, t_program *program);
int			render_fractor(t_program *program);
int			get_color(int iteration, int max_iteration, int color_pallete);
int			generate_color(t_program *program, long double xo, long double yo);
