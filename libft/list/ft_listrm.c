/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listrm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:25:15 by jtong             #+#    #+#             */
/*   Updated: 2019/06/25 17:27:05 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_node	*ft_listrm(t_node *prev, t_node *node)
{
	if (!prev || !node)
		return NULL;
	prev->next = node->next;
	node->next = NULL;
	return (node);
}
