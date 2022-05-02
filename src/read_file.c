/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:36:38 by junykim           #+#    #+#             */
/*   Updated: 2022/05/02 18:46:20 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
// fill_matrix : save coordinate by int type
// nums : save temporarily split word of each line 
static void	fill_matrix(char *file, t_fdf *data)
{
	int	i;
	int j;
	int	fd;
	char	*line;
	char	**nums;

	fd = open(file, O_RDONLY);//is this reset read pointer?
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->column));
	if (!data->z_matrix)
		return ;
	i = -1;
	while (++i < data->column)
	{
		line = get_next_line(fd);
		*ft_strrchr(line, '\n') = 0;
		nums = ft_split(line, ' ');
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->row));
		if (!data->z_matrix[i])
			return ;
		j = -1;
		while (++j < data->row)
			data->z_matrix[i][j] = ft_atoi(nums[j]);
		/** free(nums[i]); */
	}
	close(fd);
	free(nums);
}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		column;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	data->row = ft_wordcnt(line, ' ');
	column = 0;
	while (line)
	{
		column++;
		free(line);
		/** line = NULL; */
		line = get_next_line(fd);
		// if there isnt same wordcnt each line, return -1
	}
	data->column = column;
	close(fd);
	fill_matrix(file, data);
}

/** call gnl and split the each dot. atoi and list(save x,y coordinate & value)  */
/** how to know BUFFER_SIZE? (== ONE LINE) */
