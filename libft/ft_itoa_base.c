/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:32:37 by jtong             #+#    #+#             */
/*   Updated: 2018/11/14 22:31:20 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	ft_getdigit(int i)
{
	if (i >= 0 && i <= 35)
		return ("0123456789abcdefghijklmnopqrstuvwxyz"[i]);
	return ('\0');
}

char		*ft_itoa_base(int n, int base)
{
	int		cpy;
	int		size;
	int		offset;
	char	*str;

	if (base < 2 || base > 35)
		return (NULL);
	cpy = n;
	size = n ? 0 : 1;
	if (cpy != 0)
		while (++size && (cpy /= base) != 0)
			;
	offset = n < 0 && base == 10 ? 1 : 0;
	size += offset;
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (n < 0 && base == 10)
		str[0] = '-';
	while (size-- > offset)
	{
		str[size] = ft_getdigit((n < 0 ? -1 : 1) * (n % base));
		n /= base;
	}
	return (str);
}
