/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_to_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:52:32 by junykim           #+#    #+#             */
/*   Updated: 2022/05/02 20:39:17 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>
# define MAX(a, b) (a > b ? a : b)
# define ABS(a) (a < 0) ? -a : a

/** void	isometric(float *x, float *y, int z) */
/** { */
/**     *x = (*x - *y) * cos(0.8); */
/**     *y = (*x + *y) * sin(0.8) - z; */
/** } */

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = (z) ? 0xe80c0c : 0xffffff;// if z value isnt 0 color red
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;// if z or z1 is 10 color red
	/** [> isometric(&x, &y, z); <] */
	/** [> isometric(&x1, &y1, z); <] */
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(ABS(x_step), ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, data->color);
		x += x_step;
		y += y_step;
	}
}
