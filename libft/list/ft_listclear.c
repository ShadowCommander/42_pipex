/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:49:40 by jtong             #+#    #+#             */
/*   Updated: 2019/06/25 17:28:22 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

void	*ft_listclear(t_llist *list, int malloced)
{
	while (list->start)
		ft_listfree(ft_listpop(list), malloced);
	list->end = NULL;
	list->length = 0;
	return (NULL);
}
