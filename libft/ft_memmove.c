/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:18:41 by junykim           #+#    #+#             */
/*   Updated: 2022/03/21 16:07:32 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/* to overlaps with from */
		/*  <src......>         */
		/*         <dest........>  */
		/* copy in reverse, to avoid overwriting from */

/* to overlaps with from */
		/*        <src......>   */
		/*  <dest........>         */
		/* copy forwards, to avoid overwriting from */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (!dest && !src)
		return (dest);
	pdst = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (dest <= src)
		while (n--)
			*pdst++ = *psrc++;
	else
	{
		pdst += n;
		psrc += n;
		while (n--)
			*--pdst = *--psrc;
	}
	return (dest);
}
