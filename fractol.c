#include "fractol.h"

void	invalid_args_handler(void)
{
	ft_putstr_fd(ERROR_MSG, 2);
	exit(1);
}

int	close_window(t_program *param)
{
	(void)param;
	exit(1);
}

int	key_hook(int keycode, t_program *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	mouse_hook(int keycode, t_program *param)
{
	(void)param;
	(void)keycode;
	return (0);
}

double	scale(double number, double inMin, double inMax, double outMin, double outMax)
{
    return ((number - inMin) * (outMax - outMin) / (inMax - inMin) + outMin);
}

void	opt_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_program	fractol_init(char **argv)
{
	t_program	program;

	program.mlx = mlx_init();
	program.win = mlx_new_window(program.mlx, WIDTH, HEIGHT, argv[1]);
	mlx_key_hook(program.win, key_hook, &program);
	mlx_mouse_hook(program.win, mouse_hook, &program);
	mlx_hook(program.win, 17, 0, close_window, &program);
	program.img.img = mlx_new_image(program.win, WIDTH, HEIGHT);
	program.img.addr = mlx_get_data_addr(program.img.img,
			&program.img.bits_per_pixel,
			&program.img.line_length,
			&program.img.endian);
	return (program);
}

int	generate_color(double xo, double yo)
{
	float	x;
	float	y;
	float	temp_x;
	int	iteration;
	int	max_iteration;

	x = 0;
	y = 0;
	iteration = 0;
	max_iteration = 5000;
	while (((x * x) + (y * y)) < 4 && iteration < max_iteration)
	{
		temp_x = (x * x) - (y * y) + xo;
		y = ((2 * y) * x) + yo;
		x = temp_x;
		iteration++;
	}
	//printf("Log xo: %f, yo: %f, x: %f, y: %f, scale: %f, scale in hex %x, iteration %d\n", xo, yo, x, y, scale(iteration, 0, 1000, 0, 16777215), (int)scale(iteration, 0, 1000, 0, 16777215), iteration);
	return (scale(iteration, 0, 5000, 0, 16777215));
}

void	render_fractor(t_program program, char **argv)
{
	int	x;
	int	y;

	if (!ft_strcmp("mandelbrot", argv[1]))
	{
		y = 0;
		while (y < HEIGHT)
		{
			x = 0;
			while (x < WIDTH)
			{
				opt_mlx_pixel_put(&program.img, x, y,
					generate_color(
						scale((double)x, 0, 800, -2, 2),
						scale((double)y, 0, 800, 2, -2)));
				x++;
			}
			y++;
		}
	}
}

void	fract_handler(char **argv)
{
	t_program	program;

	program = fractol_init(argv);
	render_fractor(program, argv);
	mlx_put_image_to_window(program.mlx, program.win, program.img.img, 0, 0);
	mlx_loop(program.mlx);
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
