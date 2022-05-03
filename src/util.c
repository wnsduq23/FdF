/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:46:21 by junykim           #+#    #+#             */
/*   Updated: 2022/05/03 17:26:40 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

size_t	ft_wordcnt(char *s, char c)
{
	size_t	i;
	size_t	num;

	num = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while ((s[i] != c) && s[i])
				i++;
			num++;
		}
		else
			i++;
	}
	return (num);
}

void	ft_error(char *s)
{
	ft_putstr_fd(s, 1);
	exit(1);//how to use it?
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else 
		return (b);
}

int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}

t_point	new_point(int x, int y, t_map *map)
{

}
