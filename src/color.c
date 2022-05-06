/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:06:19 by junykim           #+#    #+#             */
/*   Updated: 2022/05/06 18:41:02 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return ((placement / distance));
}

int	get_default_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

/** point cur is current point , start, next point */
int	get_color(t_point cur, t_point s, t_point n, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (cur.color == n.color)
		return (cur.color);
	if (delta.x > delta.y)
		percentage = percent(s.x, n.x, cur.x);
	else
		percentage = percent(s.y, n.y, cur.y);
	red = get_light((s.color >> 16) & 0xFF, \
			(n.color >> 16) & 0xFF, percentage);
	green = get_light((s.color >> 8) & 0xFF, \
			(n.color >> 8) & 0xFF, percentage);
	blue = get_light(s.color & 0xFF, \
			n.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
