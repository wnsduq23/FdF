/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:44:14 by junykim           #+#    #+#             */
/*   Updated: 2022/04/25 21:10:31 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strnstr(const char *dst, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*tofind)
		return ((char *)dst);
	i = 0;
	while (dst[i] && i < len)
	{
		j = 0;
		while (dst[i + j] == tofind[j] && i + j < len)
		{
			j++;
			if (!tofind[j])
				return ((char *)(dst + i));
		}
		i++;
	}
	return (0);
}
