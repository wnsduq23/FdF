/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:47:12 by junykim           #+#    #+#             */
/*   Updated: 2022/05/02 22:51:45 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

/** what is mlx_ptr? */
/** int	deal_key(int key, t_fdf *fdf) */
/** { */
/**     [> ft_printf("%d\n", key); <] */
/**     if (key == 126) */
/**         fdf->shift_y -= 10; */
/**     if (key == 125) */
/**         fdf->shift_y += 10; */
/**     if (key == 124) */
/**         fdf->shift_x += 10; */
/**     if (key == 123) */
/**         fdf->shift_x -= 10; */
/**     mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr); */
/**     draw(fdf); */
/**     return (0); */
/** } */

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;
	/** int i = 0, j = 0; */
	if (ac == 2)
	{
		map = map_init();
		fdf = fdf_init(map);
		read_map(av[1], fdf);
		draw(fdf->map, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	/** [> draw(fdf); <] */
	/** mlx_key_hook(fdf->win_ptr, deal_key, NULL);//? */
	/** i = 0; */
	/** while (i < fdf->column) */
	/** { */
	/**     j = 0; */
	/**     while (j < fdf->row) */
	/**     { */
	/**         printf("%3d", fdf->z_matrix[i][j]); */
	/**         j++; */
	/**     } */
	/**     printf("\n"); */
	/**     i++; */
	/** } */
	ft_error(ERR_USAGE);
	return (0);
}
