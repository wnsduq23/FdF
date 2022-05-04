/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:38:17 by junykim           #+#    #+#             */
/*   Updated: 2022/05/04 22:40:00 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "error_message.h"
# include "color.h"
# include "key_macro.h"
# include <mlx.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE		10
#endif

// about WINDOW
# define WINDOW_X_LEN		1920
# define WINDOW_Y_LEN		1080
# define WINDOW_TITLE		"fdf"
# define WINDOW_MENU_WIDTH	250

// about COORDINATE MOVEMENT
# define SHIFT_LEFT			20
# define SHIFT_RIGHT		20
# define SHIFT_UP			20
# define SHIFT_DOWN			20
# define ROTATE_X			0.05
# define ROTATE_Y			0.05
# define ROTATE_Z			0.05

typedef enum e_bool
{
	false,
	true
}			 t_bool;

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
typedef struct s_node
{
	int				fd;
	char			*save;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

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
	t_projection	projection;// enum must first member variable?
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
}				 t_fdf;

// ================================
//			  read_map.c
// ================================
void		read_map(char *file, t_map *map);

// ================================
//			get_next_line.c
// ================================
char		*get_next_line(int fd);
t_node		*get_node(t_node *head, int fd);
void		*del_node(t_node **node);

// ================================
//				init.c
// ================================
t_map		*map_init(void);
t_fdf		*fdf_init(t_map *map);
t_camera	*camera_init(t_fdf *fdf);

// ================================
//			   control.c
// ================================
void	set_key_control(t_fdf *fdf);
int	key_press(int key, void *param);
int	mouse_press(int button, int x, int y, void *param);
int	mouse_release(int button, int x, int y, void *param);
int	mouse_move(int x, int y, void *param);

// ================================
//				color.c
// ================================
int			get_color(t_point cur, t_point p, t_point n, t_point delta);
int			get_default_color(int z, t_map *map);
double		percent(int start, int end, int current);
int			get_light(int start, int end, double percentage);

// ================================
//				draw.c
// ================================
void		draw(t_map *map, t_fdf *fdf);

// ================================
//			  projection.c
// ================================
t_point		project(t_point p, t_fdf *fdf);

// ================================
//			 util_draw.c
// ================================
t_point		new_point(int x, int y, t_map *map);
int			ft_abs(int a);
int			ft_max(int a, int b);

// ================================
//			  util_3d.c
// ================================
void		zoom(int key, t_fdf *fdf);
void		move(int key, t_fdf *fdf);
void		rotate(int key, t_fdf *fdf);
void		flatten(int key, t_fdf *fdf);
void		change_projection(int key, t_fdf *fdf);

// ================================
//				util.c
// ================================
void		ft_error(char *s);
size_t		ft_wordcnt(char *s, char c);
int			ft_min(int a, int b);

#endif
