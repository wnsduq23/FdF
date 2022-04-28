/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:46:21 by junykim           #+#    #+#             */
/*   Updated: 2022/04/28 20:46:43 by junykim          ###   ########.fr       */
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
