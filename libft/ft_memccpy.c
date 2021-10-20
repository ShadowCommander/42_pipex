/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:10:13 by jtong             #+#    #+#             */
/*   Updated: 2018/11/03 16:10:15 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	unsigned char		uc;

	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	uc = (unsigned char)c;
	while (n-- > 0)
		if ((*d++ = *s++) == uc)
			return (d);
	return (NULL);
}
