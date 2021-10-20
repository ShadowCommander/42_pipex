/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:32:39 by jtong             #+#    #+#             */
/*   Updated: 2019/05/02 17:33:04 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	ft_lstfree(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = tmp->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
	list = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tail;

	if (!lst)
		return (NULL);
	head = (*f)(lst);
	lst = lst->next;
	tail = head;
	while (lst)
	{
		if (!(tail->next = (*f)(lst)))
		{
			ft_lstfree(&head);
			return (NULL);
		}
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}
