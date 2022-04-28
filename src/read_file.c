/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:36:38 by junykim           #+#    #+#             */
/*   Updated: 2022/04/28 18:03:33 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_width(const char *file)
{
	int	width;

	return (width);
}
int	get_height(const char *file)
{
	int	height;

	return (height);
}

void	read_file(const char *file, t_fdf *data)
{
	int		fd;
	char	*line;

	while (1)
	{
		fd = open(file, O_RDONLY);
		line = get_next_line(fd);
	}
	data->height = get_height(file);// z value
	data->width = get_width(file);
}

/** call gnl and split the each dot. atoi and list(save x,y coordinate & value)  */
/** how to know BUFFER_SIZE? (== ONE LINE) */
