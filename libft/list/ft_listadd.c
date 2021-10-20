/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:29:13 by jtong             #+#    #+#             */
/*   Updated: 2019/06/25 17:22:47 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_node	*ft_listadd(t_llist *list, t_node *node)
{
	if (!list)
		return (NULL);
	if (list->end)
	{
		list->end->next = node;
		list->end = list->end->next;
	}
	else
	{
		list->end = node;
		list->start = list->end;
	}
	list->length += 1;
	return (list->end);
}
