/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:35:36 by junykim           #+#    #+#             */
/*   Updated: 2022/05/03 18:01:03 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= WINDOW_MENU_WIDTH && x < WINDOW_X_LENGTH && y >= 0 && y < WINDOW_Y_LENGTH)
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
// point p is present point, point n is next point

static void	draw_line(t_point p, t_point n, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error;

	delta.x = ft_abs(n.x - p.x);
	delta.y = ft_abs(n.y - p.y);
	sign.x = p.x < n.x ? 1 : -1;
	sign.y = p.y < n.y ? 1 : -1;
	error = delta.x - delta.y;
	cur = p;
	while (cur.x != s.x || cur.y != s.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_color(cur, p, n, delta));
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

/** draw O------ */
/**      | */
/**      | */
/**      | */
/**      | */
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
			if (x < map->row - 1)
				draw_line(project(new_point(x, y, map), fdf), 
						project(new_point(x + 1, y, map), fdf), fdf);
			if (y < map->column - 1)
				draw_line(project(new_point(x, y, map), fdf), 
						project(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	/** print_menu(fdf); */
}
