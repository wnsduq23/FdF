/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:47:12 by junykim           #+#    #+#             */
/*   Updated: 2022/05/03 20:52:06 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

/** what is mlx? */
int	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;

	if (ac == 2)
	{
		map = map_init();
		fdf = fdf_init(map);
		read_map(av[1], map);
		fdf->camera = camera_init(fdf);
		draw(fdf->map, fdf);
		mlx_loop(fdf->mlx);
	}
	ft_error(ERR_USAGE);
	return (0);
}
