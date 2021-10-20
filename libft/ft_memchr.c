/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:53:50 by jtong             #+#    #+#             */
/*   Updated: 2018/11/26 16:45:57 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n-- > 0)
		if (*str++ == chr)
			return ((void *)(str - 1));
	return (NULL);
}
