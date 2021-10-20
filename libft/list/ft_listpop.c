/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:59:01 by jtong             #+#    #+#             */
/*   Updated: 2019/04/05 18:57:58 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

t_node	*ft_listpop(t_llist *list)
{
	t_node	*node;

	if (!list || !list->start)
		return (NULL);
	node = list->start;
	list->start = node->next;
	if (list->start == NULL)
		list->end = NULL;
	node->next = NULL;
	list->length -= 1;
	return (node);
}
