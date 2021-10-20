/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 21:08:16 by jtong             #+#    #+#             */
/*   Updated: 2018/11/08 16:16:22 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dst == src)
		return (dst);
	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst < src)
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	else
		while (len-- > 0)
			d[len] = s[len];
	return (dst);
}
