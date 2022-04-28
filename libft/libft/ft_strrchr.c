/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:21:25 by junykim           #+#    #+#             */
/*   Updated: 2022/03/22 15:37:45 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = 0;
	while (*s)
	{
		if (*s == (char)c)
			save = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (save);
}
