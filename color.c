/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <mmouhiid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 05:10:12 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/12/22 20:09:58 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_first_palette(int *first_pallete)
{
	first_pallete[0] = 0x421E0F;
	first_pallete[1] = 0x19071A;
	first_pallete[2] = 0x09012F;
	first_pallete[3] = 0x040449;
	first_pallete[4] = 0x000764;
	first_pallete[5] = 0x0C2C8A;
	first_pallete[6] = 0x1852B1;
	first_pallete[7] = 0x397DD1;
	first_pallete[8] = 0x86B5E5;
	first_pallete[9] = 0xD3ECF8;
	first_pallete[10] = 0xF1E9BF;
	first_pallete[11] = 0xF8C95F;
	first_pallete[12] = 0xFFAA00;
	first_pallete[13] = 0xCC8000;
	first_pallete[14] = 0x995700;
	first_pallete[15] = 0x6A3403;
}

void	initialize_second_palette(int *second_pallete)
{
	second_pallete[0] = 0x421E3F;
	second_pallete[1] = 0x19074A;
	second_pallete[2] = 0x09015F;
	second_pallete[3] = 0x040499;
	second_pallete[4] = 0x0007A4;
	second_pallete[5] = 0x0C2CCA;
	second_pallete[6] = 0x1852F3;
	second_pallete[7] = 0x397DF3;
	second_pallete[8] = 0x86B5F6;
	second_pallete[9] = 0xD3ECF9;
	second_pallete[10] = 0xF1E9EF;
	second_pallete[11] = 0xF8C99F;
	second_pallete[12] = 0xFFAA51;
	second_pallete[13] = 0xCC8051;
	second_pallete[14] = 0x995751;
	second_pallete[15] = 0x6A3454;
}

int	select_color(int i, int color_pallete, int *first_pallete,
				int *second_pallete)
{
	int	color;

	color = 0;
	if (color_pallete == 1)
		color = first_pallete[i];
	else if (color_pallete == 2)
		color = second_pallete[i];
	return (color);
}

int	get_color(int iteration, int max_iteration, int color_pallete)
{
	int	i;
	int	color;
	int	first_pallete[16];
	int	second_pallete[16];

	initialize_first_palette(first_pallete);
	initialize_second_palette(second_pallete);
	color = 0;
	if (iteration < max_iteration && iteration > 0)
	{
		i = iteration % 16;
		color = select_color(i, color_pallete, first_pallete, second_pallete);
	}
	return (color);
}
