/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:55:26 by junykim           #+#    #+#             */
/*   Updated: 2022/05/06 20:21:17 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/define.h"
#include "../include/draw.h"
#include <math.h>

t_point	new_point(int x, int y, t_map *map)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = map->z_matrix[y][x];
	p.color = get_default_color(p.z, map);
	return (p);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}
