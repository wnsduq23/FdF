/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_to_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:55:26 by junykim           #+#    #+#             */
/*   Updated: 2022/05/03 16:59:15 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"
#include <math.h>

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}
//it's bresenham algorithm
// point p is present point, point n is next point
void	draw_line(t_point *p, t_point *n, t_fdf *fdf)
{

}
