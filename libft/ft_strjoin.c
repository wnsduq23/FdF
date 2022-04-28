/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:19:50 by junykim           #+#    #+#             */
/*   Updated: 2022/04/25 21:11:50 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)

{
	char	*total;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total = malloc(s1_len + s2_len + 1);
	if (!total)
		return (0);
	ft_memcpy(total, s1, s1_len);
	ft_memcpy(total + s1_len, s2, s2_len);
	total[s1_len + s2_len] = 0;
	return (total);
}
