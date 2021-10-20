/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:28:00 by jtong             #+#    #+#             */
/*   Updated: 2018/11/09 14:48:57 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;

	n_len = ft_strlen(needle);
	if (!*needle || (!*needle && !*haystack))
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (needle[i] && haystack[i] == needle[i])
				i++;
			if (!needle[i] && i <= len)
				return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (NULL);
}
