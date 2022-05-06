/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:10:32 by junykim           #+#    #+#             */
/*   Updated: 2022/05/06 20:22:46 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

// ================================
//				draw.c
// ================================
void		draw(t_map *map, t_fdf *fdf);

// ================================
//			 util_draw.c
// ================================
t_point		new_point(int x, int y, t_map *map);
int			ft_abs(int a);
int			ft_max(int a, int b);

// ================================
//				color.c
// ================================
int			get_color(t_point cur, t_point p, t_point n, t_point delta);
int			get_default_color(int z, t_map *map);
double		percent(int start, int end, int current);
int			get_light(int start, int end, double percentage);

// ================================
//				menu.c
// ================================
void		print_menu(t_fdf *fdf);

// ================================
//			  projection.c
// ================================
t_point		project(t_point p, t_fdf *fdf);

#endif
