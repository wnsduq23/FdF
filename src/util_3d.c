/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:42:31 by junykim           #+#    #+#             */
/*   Updated: 2022/05/04 21:20:17 by junykim          ###   ########.fr       */
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
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf->map, fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->camera->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		fdf->camera->x_offset += 10;
	else if (key == ARROW_UP)
		fdf->camera->y_offset -= 10;
	else
		fdf->camera->y_offset += 10;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf->map, fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_K)
		fdf->camera->alpha += 0.05;
	else if (key == KEY_J)
		fdf->camera->alpha -= 0.05;
	else if (key == KEY_H)
		fdf->camera->beta -= 0.05;
	else if (key == KEY_L)
		fdf->camera->beta += 0.05;
	else if (key == KEY_MORE)
		fdf->camera->gamma += 0.05;
	else if (key == KEY_LESS)
		fdf->camera->gamma -= 0.05;
	mlx_clear_window(fdf->mlx, fdf->win);
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
	mlx_clear_window(fdf->mlx, fdf->win);
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
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf->map, fdf);
}
