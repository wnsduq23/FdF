/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:42:31 by junykim           #+#    #+#             */
/*   Updated: 2022/05/04 22:40:49 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == MOUSE_SCROLL_UP)
		fdf->camera->zoom++;
	else if (key == MOUSE_SCROLL_DOWN)
		fdf->camera->zoom--;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf->map, fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->camera->x_offset -= SHIFT_LEFT;
	else if (key == ARROW_RIGHT)
		fdf->camera->x_offset += SHIFT_RIGHT;
	else if (key == ARROW_UP)
		fdf->camera->y_offset -= SHIFT_UP;
	else
		fdf->camera->y_offset += SHIFT_DOWN;
	draw(fdf->map, fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_K)
		fdf->camera->alpha += ROTATE_X;
	else if (key == KEY_J)
		fdf->camera->alpha -= ROTATE_X;
	else if (key == KEY_H)
		fdf->camera->beta -= ROTATE_Y;
	else if (key == KEY_L)
		fdf->camera->beta += ROTATE_Y;
	else if (key == KEY_MORE)
		fdf->camera->gamma += ROTATE_Z;
	else if (key == KEY_LESS)
		fdf->camera->gamma -= ROTATE_Z;
	draw(fdf->map, fdf);
}

void	flatten(int key, t_fdf *fdf)
{
	if (key == KEY_MINUS)
		fdf->camera->z_divisor -= 0.1;
	else if (key == KEY_PLUS)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	draw(fdf->map, fdf);
}

void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == KEY_I)
		fdf->camera->projection = ISO;
	else if (key == KEY_P)
		fdf->camera->projection = PARALLEL;
	draw(fdf->map, fdf);
}
