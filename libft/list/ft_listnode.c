/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:30:12 by jtong             #+#    #+#             */
/*   Updated: 2019/06/25 17:24:01 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

t_node	*ft_listnode(void *content, size_t size)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(*node))))
		return (NULL);
	node->content = content;
	node->size = size;
	node->next = NULL;
	return (node);
}
