/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:47:12 by junykim           #+#    #+#             */
/*   Updated: 2022/04/28 21:10:14 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/** what is mlx_ptr? */
/** int	deal_key(int key, void	*data) */
/** { */
/**     ft_printf("%d", key); */
/**     return (0); */
/** } */

int	main(int ac, char **av)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (-1);
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_X_LENGTH, WINDOW_Y_LENGTH, WINDOW_TITLE);
	bresenham(10, 10, 600, 300, data);
	mlx_key_hook(data->win_ptr, NULL, NULL);//?
	mlx_loop(data->mlx_ptr);
	return (0);
}
//deal_key
