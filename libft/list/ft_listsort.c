/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:08:19 by jtong             #+#    #+#             */
/*   Updated: 2019/06/25 17:34:42 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

static void	split(t_llist *list, t_llist *a, t_llist *b)
{
	a->start = list->start;
	b->start = list->start;
	b->end = list->start->next;
	if (b->end)
		b->end = b->end->next;
	while (b->end)
	{
		b->end = b->end->next;
		if (b->end)
		{
			b->end = b->end->next;
			b->start = b->start->next;
		}
	}
	a->end = b->start;
	b->start = b->start->next;
	a->end->next = NULL;
}

void		ft_listsort(t_llist *list, int (*f)(t_node *, t_node *), int rev)
{
	t_llist	*a;
	t_llist	*b;

	if (!list || !list->start)
		return ;
	a = ft_listnew();
	b = ft_listnew();
	split(list, a, b);
	ft_listsort(a, f, rev);
	ft_listsort(b, f, rev);
	if ((rev ? -1 : 1) * (*f)(a->start, b->start) > 0)
		list->start = ft_listpop(b);
	else
		list->start = ft_listpop(a);
	list->end = list->start;
	while (a || b)
	{
		if (b && (!a || (rev ? -1 : 1) * (*f)(a->start, b->start) > 0))
			ft_listadd(list, ft_listpop(b));
		else
			ft_listadd(list, ft_listpop(a));
	}
	free(a);
	free(b);
}
