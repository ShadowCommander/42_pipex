/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:02:25 by jtong             #+#    #+#             */
/*   Updated: 2019/06/25 17:23:42 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

t_llist	*ft_listnew(void)
{
	t_llist	*list;

	list = (t_llist *)malloc(sizeof(*list));
	list->start = NULL;
	list->end = NULL;
	list->length = 0;
	return (list);
}
