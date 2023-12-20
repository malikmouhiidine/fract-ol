#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "libft/libft.h"

#define ERROR_MSG "usage:\n\tfractol mandelbrot\n\tfractol julia <r> <i>\n"

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
	void		*mlx;
	void		*win;
	char		*fractol_type;
	int			max_iteration;
	double		right_x;
	double		left_x;
	double		top_y;
	double		bottom_y;
	t_image		*img;
}	t_program;

int	ft_strcmp(char *s1, char *s2);
