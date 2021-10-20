/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:55:55 by jtong             #+#    #+#             */
/*   Updated: 2019/07/09 14:32:44 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include "../libft.h"

typedef struct s_node	t_node;
struct	s_node
{
	void	*content;
	size_t	size;
	t_node	*next;
};

typedef struct s_llist	t_llist;
struct	s_llist
{
	t_node	*start;
	t_node	*end;
	size_t	length;
};

/*
** push adds to front
** pop takes from front
** lop takes from end
** add adds to end
*/
/* Adds to front */
t_node	*ft_listpush(t_llist *list, t_node *node);
/* Takes from front */
t_node	*ft_listpop(t_llist *list);
/* Adds to end */
t_node	*ft_listadd(t_llist *list, t_node *node);
/* Takes from end */
t_node	*ft_listlop(t_llist *list);

/* Sets prev->next to node->next and returns node */
t_node	*ft_listrm(t_node *prev, t_node *node);
t_node	*ft_listsrt(t_node **next, t_node *node);

void	ft_listfree(t_node *nptr, int malloced);
void	*ft_listclear(t_llist *list, int malloced);

t_node	*ft_listnode(void *content, size_t size);
t_llist	*ft_listnew(void);

void	ft_listsort(t_llist *list, int (*f)(t_node *, t_node *), int rev);
t_node	*ft_listfind(t_llist *list, int (*f)(t_node *, void *, size_t),
    void *content, size_t size);
#endif
