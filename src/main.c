/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:47:12 by junykim           #+#    #+#             */
/*   Updated: 2022/05/02 19:16:48 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/** what is mlx_ptr? */
int	deal_key(int key, t_fdf *data)
{
	/** ft_printf("%d\n", key); */
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 123)
		data->shift_x -= 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	(void)ac;
	/** if (ac == 1) */
	/**     ft_error("Error : no input\n"); */
	/** else if (ac > 2) */
	/**     ft_error("Error : too many input\n"); */
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (-1);
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_X_LENGTH, WINDOW_Y_LENGTH, WINDOW_TITLE);
	data->zoom = 20;
	/** bresenham(10, 10, 600, 300, data); */
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);//?
	mlx_loop(data->mlx_ptr);
	return (0);
}
