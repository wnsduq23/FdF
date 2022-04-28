/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:35:17 by junykim           #+#    #+#             */
/*   Updated: 2022/03/22 20:26:00 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/* Append the NUL-terminated string src to the end of dest.*/
/* It will append at most size - strlen(dest) - 1 bytes,*/
/* NUL-terminating the result. */
size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	keep_d;

	keep_d = 0;
	while (keep_d < n && dst[keep_d])
		keep_d++;
	i = 0;
	while (src[i] && keep_d + i + 1 < n)
	{
		dst[keep_d + i] = src[i];
		i++;
	}
	if (keep_d < n)
		dst[keep_d + i] = 0;
	return (keep_d + ft_strlen(src));
}
