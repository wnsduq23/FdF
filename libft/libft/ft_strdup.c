/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:20:07 by junykim           #+#    #+#             */
/*   Updated: 2022/04/25 21:12:08 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	s_len;

	s_len = ft_strlen(s);
	dst = malloc(sizeof(char) * (s_len + 1));
	if (!dst)
		return (0);
	ft_memcpy(dst, s, s_len);
	dst[s_len] = 0;
	return (dst);
}
