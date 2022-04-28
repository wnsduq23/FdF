/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_to_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:52:32 by junykim           #+#    #+#             */
/*   Updated: 2022/04/28 19:45:36 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
# define MAX(a, b) (a > b ? a : b)
# define ABS(a) (a < 0) ? -a : a

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(ABS(x_step), ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffffff);
		x += x_step;
		y += y_step;
	}
}
