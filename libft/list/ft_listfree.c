/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:47:06 by jtong             #+#    #+#             */
/*   Updated: 2019/06/25 14:35:57 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

void	ft_listfree(t_node *nptr, int malloced)
{
	if (!nptr)
		return ;
	if (malloced && nptr->content)
		free(nptr->content);
	free(nptr);
}
