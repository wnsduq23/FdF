/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:03:09 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 21:25:53 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// about WINDOW
# define WINDOW_X_LEN		1920
# define WINDOW_Y_LEN		1080
# define WINDOW_TITLE		"fdf"
# define WINDOW_MENU_WIDTH	250

// about COORDINATE MOVE
# define SHIFT_LEFT			20
# define SHIFT_RIGHT		20
# define SHIFT_UP			20
# define SHIFT_DOWN			20

// about COORDINATE ROTATE
# define ROTATE_X			0.05
# define ROTATE_Y			0.05
# define ROTATE_Z			0.05

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef enum e_projection_type
{
	ISO,
	PARALLEL
}				t_projection;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

// save map information 
typedef struct s_map
{
	int			row;
	int			column;
	int			**z_matrix;
	int			z_max;
	int			z_min;
}				t_map;

// camera is (a,b,c) orientation vector
typedef struct s_camera
{
	t_projection	projection;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				zoom;
	int				x_offset;
	int				y_offset;
}					t_camera;

// x,y is mouse's coordinate
typedef struct s_mouse
{
	t_bool		is_pressed;
	int			x;
	int			y;
	int			previous_x;
	int			previous_y;
}				t_mouse;

// this is for read file & save each data
typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_camera	*camera;
	t_map		*map;
	t_mouse		*mouse;
}				t_fdf;

#endif
