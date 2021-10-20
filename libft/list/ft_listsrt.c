/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:35:50 by jtong             #+#    #+#             */
/*   Updated: 2019/06/25 17:23:31 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_node	*ft_listsrt(t_node **next, t_node *node)
{
	if (!next)
		return (NULL);
	node->next = *next;
	*next = node;
	return (*next);
}
