/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:03:29 by junykim           #+#    #+#             */
/*   Updated: 2022/05/02 22:46:10 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->row = 0;
	map->column = 0;
	return (map);
}

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (0);
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		ft_error(ERR_FDF_INIT);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WINDOW_X_LENGTH, WINDOW_Y_LENGTH, WINDOW_TITLE);
	if (!fdf->win_ptr)
		ft_error(ERR_FDF_INIT);
	fdf->img = mlx_new_image(fdf->mlx_ptr, WINDOW_X_LENGTH, WINDOW_Y_LENGTH);
	if (!fdf->img)
		ft_error(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	if (!fdf->data_addr)
		ft_error(ERR_FDF_INIT);
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		return (0);
	return (fdf);
}
