/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:21:51 by junykim           #+#    #+#             */
/*   Updated: 2022/03/18 20:59:53 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	unsigned int	i;
	char			*ret;
	size_t			ret_s;
	size_t			ret_len;

	if (!s)
		return (0);
	if (ft_strlen(s) < n)
		ret_len = ft_strlen(s);
	else
		ret_len = n;
	ret = malloc(sizeof(char) *(ret_len + 1));
	if (!ret)
		return (0);
	i = 0;
	ret_s = 0;
	while (s[i])
	{
		if (start <= i && ret_s < n)
			ret[ret_s++] = s[i];
		i++;
	}
	ret[ret_s] = 0;
	return (ret);
}
