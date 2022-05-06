/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:41:29 by junykim           #+#    #+#             */
/*   Updated: 2022/05/06 17:46:35 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: ");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis - K/J");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis - L/H");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis - </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
}
