/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:38:17 by junykim           #+#    #+#             */
/*   Updated: 2022/05/02 18:51:25 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <mlx.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	 10
#endif
# define WINDOW_X_LENGTH 1920
# define WINDOW_Y_LENGTH 1080
# define WINDOW_TITLE	 "fdf"
typedef struct s_node
{
	int				fd;
	char			*save;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

// this is for read file & save each data
typedef struct s_fdf
{
	int		row;
	int		column;
	int		**z_matrix;
	int		zoom;
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
	int		shift_x;
	int		shift_y;
} t_fdf;

char		*get_next_line(int fd);
t_node		*get_node(t_node *head, int fd);
void		*del_node(t_node **node);
size_t	ft_wordcnt(char *s, char c);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	read_file(char *file, t_fdf *data);
void	draw(t_fdf *data);
void	isometric(float *x, float *y, int z);

#endif
