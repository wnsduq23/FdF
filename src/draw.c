/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:35:36 by junykim           #+#    #+#             */
/*   Updated: 2022/05/04 17:34:01 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

/** static void	draw_background(t_fdf *fdf) */
/** { */
/**  */
/** } */

//it's bresenham algorithm
// point s is start point, point n is next point
// delta is difference between point s and point n coordinate
static void	draw_line(t_point s, t_point n, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error;

	delta.x = ft_abs(n.x - s.x);
	delta.y = ft_abs(n.y - s.y);
	if (s.x < n.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (s.y < n.y)
		sign.y = 1;
	else
		sign.y = -1;
	error = delta.x - delta.y;
	cur = s;
	while (cur.x != n.x || cur.y != n.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_color(cur, s, n, delta));
		if ((error * 2) > -delta.y)
		{
			error -= delta.y;
			cur.x += sign.x;
		}
		if ((error * 2) < delta.x)
		{
			error += delta.x;
			cur.y += sign.y;
		}
	}
}

/** draw 0------ 0------ ... */
/**      |		 | */
/**      |		 | */
/**      |		 | */
void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	/** draw_background(fdf); */
	y = 0;
	while (y < map->column)
	{
		x = 0;
		while (x < map->row)
		{
			if (x < fdf->map->row - 1) //is it different map->row?
				draw_line(project(new_point(x, y, map), fdf), \
						project(new_point(x + 1, y, map), fdf), fdf);
			if (y < fdf->map->column - 1)
				draw_line(project(new_point(x, y, map), fdf), \
						project(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	/** print_menu(fdf); */
}
