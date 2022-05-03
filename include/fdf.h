/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:38:17 by junykim           #+#    #+#             */
/*   Updated: 2022/05/03 18:10:13 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>// is that need?
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "error_message.h"
# include <mlx.h>

#ifndef BUFFER_SIZE
	# define BUFFER_SIZE	 10
#endif
# define WINDOW_X_LENGTH 1920
# define WINDOW_Y_LENGTH 1080
# define WINDOW_TITLE	 "fdf"
# define WINDOW_MENU_WIDTH 250

typedef enum e_projection_type
{
	ISO,
	PARELLE
}				t_projection;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;
typedef struct s_node
{
	int				fd;
	char			*save;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

// save map information 
typedef struct s_map
{
	int	row;
	int	column;
	int	**z_matrix;
}				t_map;

typedef struct s_camera
{
	int	zoom;
	int rotate;

}				t_camera;

typedef struct s_mouse
{
	int	up;
	int	down;
	int	left;
	int right;
}				t_mouse;
// this is for read file & save each data
typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_camera	*camera;
	t_map		*map;
	t_mouse		*mouse;
}				 t_fdf;

// ================================
//			read_map.c
// ================================
void	read_map(char *file, t_map *map);

// ================================
//			get_next_line.c
// ================================
char		*get_next_line(int fd);
t_node		*get_node(t_node *head, int fd);
void		*del_node(t_node **node);

// ================================
//				init.c
// ================================
t_map	*map_init(void);
t_fdf	*fdf_init(t_map *map);

// ================================
//				draw.c
// ================================
void	draw(t_map *map, t_fdf *fdf);

// ================================
//	       util_draw.c
// ================================
t_point	new_point(int x, int y, t_map *map);
void	isometric(float *x, float *y, int z);

// ================================
//	       util_draw.c
// ================================
t_point	project(t_point p, t_fdf *fdf);

// ================================
//				util.c
// ================================
int	ft_abs(int a);
int ft_max(int a, int b);
void	ft_error(char *s);
size_t	ft_wordcnt(char *s, char c);

#endif
