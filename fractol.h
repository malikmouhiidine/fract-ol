#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft/libft.h"

#define ERROR_MSG "usage:\n\tfractol mandelbrot\n\tfractol julia <r> <i>\n"

#define HEIGHT 800
#define WIDTH 800

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
	void	*mlx;
	void	*win;
	char	*fractol_type;
	int		max_iteration;
	t_image	*img;
}	t_program;

int	ft_strcmp(char *s1, char *s2);
