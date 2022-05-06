/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:05:56 by junykim           #+#    #+#             */
/*   Updated: 2022/05/06 20:09:53 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_3D_H
# define CONTROL_3D_H

// ================================
//			   control.c
// ================================
void		set_key_control(t_fdf *fdf);

// ================================
//			  util_3d.c
// ================================
void		zoom(int key, t_fdf *fdf);
void		move(int key, t_fdf *fdf);
void		rotate(int key, t_fdf *fdf);
void		flatten(int key, t_fdf *fdf);
void		change_projection(int key, t_fdf *fdf);
#endif
