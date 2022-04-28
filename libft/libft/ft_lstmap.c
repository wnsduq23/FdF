/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:28:14 by junykim           #+#    #+#             */
/*   Updated: 2022/03/21 17:19:21 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*ret;

	if (lst == 0 || !f)
		return (0);
	ret = ft_lstnew(f(lst->content));
	head = ret;
	lst = lst->next;
	while (lst)
	{
		head->next = ft_lstnew(f(lst->content));
		if (!head->next)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		head = head->next;
		lst = lst->next;
	}
	head = 0;
	return (ret);
}
