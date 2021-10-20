/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:24:07 by jtong             #+#    #+#             */
/*   Updated: 2018/11/05 15:20:24 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*n;
	const char	*s;

	if (!*needle)
		return ((char *)haystack);
	n = needle;
	s = haystack;
	while (*haystack)
	{
		if (*haystack == *n)
		{
			s = haystack;
			while (*s == *n && *++n && *++s)
				;
			if (!*n && n[-1] == *s)
				return ((char *)haystack);
			n = needle;
		}
		haystack++;
	}
	return (NULL);
}
