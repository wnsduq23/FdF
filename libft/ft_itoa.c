/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:17:06 by junykim           #+#    #+#             */
/*   Updated: 2022/03/25 12:41:21 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static size_t	intlen(long long n)
{
	size_t	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char		*ret;
	size_t		int_len;
	long long	tmp;

	int_len = intlen(n);
	ret = (char *)malloc(sizeof(char) * int_len + 1);
	if (!ret)
		return (0);
	ret[int_len] = 0;
	tmp = n;
	if (tmp == 0)
		ret[0] = '0';
	if (tmp < 0)
	{
		tmp *= -1;
		ret[0] = '-';
	}
	while (tmp)
	{
		ret[--int_len] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (ret);
}
