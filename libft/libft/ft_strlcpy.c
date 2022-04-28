/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:20:12 by junykim           #+#    #+#             */
/*   Updated: 2022/03/22 20:26:16 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* Copy up to dstsize - 1 characters from the NUL-terminated*/
/* string src to dest, NUL-terminating the result. */

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < n)
		ft_memcpy(dst, src, srclen + 1);
	else if (n != 0)
	{
		ft_memcpy(dst, src, n - 1);
		dst[n - 1] = 0;
	}
	return (srclen);
}
