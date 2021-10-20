/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:38:23 by jtong             #+#    #+#             */
/*   Updated: 2018/11/10 14:21:51 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	f;
	size_t	e;
	char	*str;

	if (!s)
		return (NULL);
	f = 0;
	e = ft_strlen(s);
	while (s[f] && (s[f] == ' ' || s[f] == '\t' || s[f] == '\n'))
		f++;
	if (e > f)
		while (--e > f && (s[e] == ' ' || s[e] == '\t' || s[e] == '\n'))
			;
	if (!(str = ft_strsub(s, f, e - f + 1)))
		return (NULL);
	return (str);
}
