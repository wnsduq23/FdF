/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:19:21 by junykim           #+#    #+#             */
/*   Updated: 2022/05/02 18:31:02 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/** it's ft_split_malloc */

static size_t	ft_wordcnt(char *s, char c)
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

static int	ft_wordcpy(char **ret, char c, char *s)
{
	size_t	i;
	size_t	from;
	size_t	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			from = i;
			while ((s[i] != c) && s[i])
				i++;
			ret[index] = malloc(i - from + 1);
			if (!ret[index])
				return (0);
			ft_strlcpy(ret[index++], s + from, i - from + 1);
		}
		else
			i++;
	}
	return (1);
}

static void	ft_free(char **ret, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word && ret[i] != 0)
		free(ret[i++]);
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	word;
	int		success;

	if (!s)
		return (0);
	word = ft_wordcnt((char *)s, c);
	ret = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ret)
		return (0);
	success = ft_wordcpy(ret, c, (char *)s);
	if (!success)
	{
		ft_free(ret, word);
		return (0);
	}
	ret[word] = 0;
	return (ret);
}
