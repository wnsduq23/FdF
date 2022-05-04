/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:07:31 by junykim           #+#    #+#             */
/*   Updated: 2022/05/04 21:13:52 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_ESC)
		exit(0);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT \
			|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fdf);
	else if (key == KEY_K || key == KEY_J \
			|| key == KEY_H || key == KEY_L \
			|| key == KEY_MORE || key == KEY_LESS)
		rotate(key, fdf);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		flatten(key, fdf);
	else if (key == KEY_P || key == KEY_I)
		change_projection(key, fdf);
	return (0);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = true;
	return (0);
}

static int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = false;
	return (0);
}

static int	mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->camera->beta += (x - fdf->mouse->previous_x) * 0.002;
		fdf->camera->alpha += (y - fdf->mouse->previous_y) * 0.002;
		draw(fdf->map, fdf);
	}
	return (0);
}

void	set_key_control(t_fdf *fdf)
{
	mlx_mouse_hook(fdf->win, mouse_press, fdf);
	mlx_mouse_hook(fdf->win, mouse_release, fdf);
	mlx_mouse_hook(fdf->win, mouse_move, fdf);
	mlx_key_hook(fdf->win, key_press, fdf);
	/** mlx_loop_hook(fdf->win,close,fdf); */
}

