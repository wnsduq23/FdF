/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:38:17 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 21:26:59 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "define.h"
# include "draw.h"
# include <stdlib.h>
# include "error_message.h"

// ================================
//			  read_map.c
// ================================
void		read_map(char *file, t_map *map);

// ================================
//				init.c
// ================================
t_map		*map_init(void);
t_fdf		*fdf_init(t_map *map);
t_camera	*camera_init(t_fdf *fdf);

// ================================
//				util.c
// ================================
void		ft_error(char *s);
size_t		ft_wordcnt(char *s, char c);
int			ft_min(int a, int b);

#endif
