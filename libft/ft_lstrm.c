/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:06:54 by jtong             #+#    #+#             */
/*   Updated: 2018/12/04 18:31:20 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstrm(t_list **alst, t_list *elem)
{
	t_list	*list;
	t_list	*back;

	if (!alst || !*alst || !elem)
		return ;
	list = *alst;
	back = NULL;
	while (list && list != elem)
	{
		back = list;
		list = list->next;
	}
	if (list == elem)
	{
		if (back)
			back->next = list->next;
		else
			*alst = list->next;
		if (list->content)
			free(list->content);
		free(list);
	}
}
