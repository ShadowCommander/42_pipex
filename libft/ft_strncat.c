/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:05:15 by jtong             #+#    #+#             */
/*   Updated: 2018/11/12 20:43:59 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*o;
	size_t	i;

	o = s1 + ft_strlen(s1);
	i = 0;
	if (n == 0)
		return (s1);
	while ((o[i] = s2[i]) && ++i < n)
		;
	o[i] = '\0';
	return (s1);
}
