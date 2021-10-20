/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:02:45 by jtong             #+#    #+#             */
/*   Updated: 2019/05/02 13:26:33 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_node	*ft_listlop(t_llist *list)
{
	t_node	*node;
	t_node	*prev;

	if (!list->start)
		return (NULL);
	node = list->start;
	prev = NULL;
	while (node->next)
	{
		prev = node;
		node = node->next;
	}
	if (prev)
		prev->next = NULL;
	list->end = prev;
	if (list->end == NULL)
		list->start = NULL;
	list->length -= 1;
	return (node);
}
