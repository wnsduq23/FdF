/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:35:36 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 21:23:35 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"
#include "../include/color.h"
#include <mlx.h>

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= WINDOW_MENU_WIDTH && x < WINDOW_X_LEN && \
			y >= 0 && y < WINDOW_Y_LEN)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

static int	ft_sign(int present, int next)
{
	if (present < next)
		return (1);
	else
		return (-1);
}

static void	draw_line(t_point s, t_point n, t_fdf *fdf)
{
	t_point	delta;
	t_point	cur;
	int		error[2];

	delta.x = ft_abs(n.x - s.x);
	delta.y = ft_abs(n.y - s.y);
	error[0] = delta.x - delta.y;
	cur = s;
	while (cur.x != n.x || cur.y != n.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_color(cur, s, n, delta));
		error[1] = 2 * error[0];
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += ft_sign(s.x, n.x);
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += ft_sign(s.y, n.y);
		}
	}
}

static void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_memset(fdf->data_addr, 0, \
			WINDOW_X_LEN * WINDOW_Y_LEN * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < WINDOW_X_LEN * WINDOW_Y_LEN)
	{
		if (i % WINDOW_X_LEN < WINDOW_MENU_WIDTH)
			image[i] = MENU_BACKGROUND;
		else
			image[i] = BACKGROUND;
		i++;
	}
}

void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	draw_background(fdf);
	y = 0;
	while (y < map->column)
	{
		x = 0;
		while (x < map->row)
		{
			if (x < map->row - 1)
				draw_line(project(new_point(x, y, map), fdf), \
						project(new_point(x + 1, y, map), fdf), fdf);
			if (y < map->column - 1)
				draw_line(project(new_point(x, y, map), fdf), \
						project(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_menu(fdf);
}
