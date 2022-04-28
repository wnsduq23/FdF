/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:36:38 by junykim           #+#    #+#             */
/*   Updated: 2022/04/28 21:12:59 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	fill_matrix(char *file, t_fdf *data)
{
	int	i;
	int j;
	int	fd;
	char	*line;
	char	**nums;

	fd = open(file, O_RDONLY, 0);//is this reset read pointer?
	i = 0;
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->column + 1));
	if (!data->z_matrix)
		return ;
	while (i <= data->column)
	{
		line = get_next_line(fd);
		nums = ft_split(line, ' ');
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->row + 1));
		if (!data->z_matrix[i])
			return ;	
		j = -1;
		while (++j <= data->row)
			data->z_matrix[i][j] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	close(fd);
}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		column;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	data->row = ft_wordcnt(line, ' ');
	column = 0;
	while (line)
	{
		column++;
		free(line);
		line = get_next_line(fd);
	}
	data->column = column;
	close(fd);
	fill_matrix(file, data);
}

/** call gnl and split the each dot. atoi and list(save x,y coordinate & value)  */
/** how to know BUFFER_SIZE? (== ONE LINE) */
