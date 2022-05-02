/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:35:36 by junykim           #+#    #+#             */
/*   Updated: 2022/05/02 22:52:23 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/** void	draw(t_fdf *data) */
/** { */
/**     int	x; */
/**     int	y; */
/**  */
/**     y = 0; */
/**     while (y < data->column) */
/**     { */
/**         x = 0; */
/**         while (x < data->row) */
/**         { */
/**             if (x < data->row - 1) */
/**                 bresenham(x, y, x + 1, y, data); */
/**             if (y < data->column - 1) */
/**                 bresenham(x, y, x, y + 1, data); */
/**             x++; */
/**         } */
/**         y++; */
/**     } */
/** } */

void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

}
