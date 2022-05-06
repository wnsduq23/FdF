/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:36:38 by junykim           #+#    #+#             */
/*   Updated: 2022/05/06 20:25:52 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../include/fdf.h"
#include "../include/libft.h"
// fill_matrix : save coordinate by int type
// nums : save temporarily split word of each line 
static void	find_z_max_and_min(t_map *map)
{
	int		max;
	int		min;
	int		x;
	int		y;

	max = 0;
	min = 0;
	y = 0;
	while (y < map->column)
	{
		x = 0;
		while (x < map->row)
		{
			if (map->z_matrix[y][x] > max)
				max = map->z_matrix[y][x];
			if (map->z_matrix[y][x] < min)
				min = map->z_matrix[y][x];
			x++;
		}
		y++;
	}
	map->z_max = max;
	map->z_min = min;
}

static void	change_to_num(t_map *map, char **nums, int i)
{
	int	j;

	j = -1;
	while (++j < map->row)
		map->z_matrix[i][j] = ft_atoi(nums[j]);
}

static void	fill_matrix(char *file, t_map *map)
{
	int		i;
	int		fd;
	char	*line;
	char	**nums;

	fd = open(file, O_RDONLY);
	map->z_matrix = (int **)malloc(sizeof(int *) * (map->column));
	if (!map->z_matrix)
		return ;
	i = -1;
	while (++i < map->column)
	{
		line = get_next_line(fd);
		*ft_strrchr(line, '\n') = 0;
		nums = ft_split(line, ' ');
		map->z_matrix[i] = (int *)malloc(sizeof(int) * (map->row));
		if (!map->z_matrix[i])
			return ;
		change_to_num(map, nums, i);
		free(nums[i]);
	}
	close(fd);
	free(nums);
}

void	read_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		column;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map->row = ft_wordcnt(line, ' ');
	column = 0;
	while (line)
	{
		column++;
		free(line);
		line = get_next_line(fd);
	}
	map->column = column;
	close(fd);
	fill_matrix(file, map);
	find_z_max_and_min(map);
}
