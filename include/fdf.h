/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:38:17 by junykim           #+#    #+#             */
/*   Updated: 2022/04/28 17:20:28 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <mlx.h>

# define BUFFER_SIZE 10
typedef struct s_node
{
	int				fd;
	char			*save;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

// this is for window data
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

// this is for read file & save each data
typedef struct s_fdf
{
	int	width;
	int	height;
	int	**z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
} t_fdf;

char		*get_next_line(int fd);
t_node		*get_node(t_node *head, int fd);
void		*del_node(t_node **node);

#endif
