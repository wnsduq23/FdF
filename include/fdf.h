/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:38:17 by junykim           #+#    #+#             */
/*   Updated: 2022/04/28 21:12:24 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <mlx.h>

# define BUFFER_SIZE	 10
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
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
} t_fdf;

char		*get_next_line(int fd);
t_node		*get_node(t_node *head, int fd);
void		*del_node(t_node **node);
size_t	ft_wordcnt(char *s, char c);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	read_file(char *file, t_fdf *data);

#endif
