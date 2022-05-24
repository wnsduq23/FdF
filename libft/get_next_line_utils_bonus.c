/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:19:37 by junykim           #+#    #+#             */
/*   Updated: 2022/05/24 21:00:22 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_node	*get_node(t_node *head, int fd)
{
	t_node	*node;

	node = head->next;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		else
			node = node->next;
	}
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->save = NULL;
	node->prev = head;
	node->next = head->next;
	if (head->next)
		head->next->prev = node;
	head->next = node;
	return (node);
}

void	*del_node(t_node **node)
{
	free((*node)->save);
	(*node)->save = NULL;
	(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	free(*node);
	*node = NULL;
	return (NULL);
}
