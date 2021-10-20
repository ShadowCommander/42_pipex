/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:34:05 by jtong             #+#    #+#             */
/*   Updated: 2018/11/09 16:16:17 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(*str) * (len + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + len, s2);
	return (str);
}
