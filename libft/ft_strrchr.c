/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:21:25 by junykim           #+#    #+#             */
/*   Updated: 2022/05/02 18:29:25 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/** return address of same value with (int)c */
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
