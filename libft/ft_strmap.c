/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:12:10 by jtong             #+#    #+#             */
/*   Updated: 2018/11/26 15:40:20 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (!s || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = (*f)(s[i]);
	return (str);
}
