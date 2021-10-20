/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:29:13 by jtong             #+#    #+#             */
/*   Updated: 2019/06/25 17:21:50 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_node	*ft_listpush(t_llist *list, t_node *node)
{
	if (!list || !node)
		return (NULL);
	node->next = list->start;
	list->start = node;
	if (!list->end)
		list->end = list->start;
	list->length += 1;
	return (list->start);
}
