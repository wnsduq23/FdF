/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:03:29 by junykim           #+#    #+#             */
/*   Updated: 2022/05/06 17:16:44 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	ft_memset(map, 0, sizeof(t_map));
	return (map);
}

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (0);
	ft_memset(fdf, 0, sizeof(t_fdf));
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_error(ERR_FDF_INIT);
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_X_LEN, WINDOW_Y_LEN, \
			WINDOW_TITLE);
	if (!fdf->win)
		ft_error(ERR_FDF_INIT);
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_X_LEN, WINDOW_Y_LEN);
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

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (0);
	ft_memset(camera, 0, sizeof(t_camera));
	camera->projection = PARALLEL;
	camera->zoom = ft_min((WINDOW_X_LEN - WINDOW_MENU_WIDTH) \
			/ fdf->map->row / 2, \
			WINDOW_Y_LEN / fdf->map->column / 2);
	camera->alpha = -1;
	camera->beta = -1;
	camera->gamma = -1;
	camera->z_divisor = 1;
	return (camera);
}
