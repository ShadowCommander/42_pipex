/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:50:17 by jtong             #+#    #+#             */
/*   Updated: 2018/11/14 19:50:54 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_wordcount(const char *str, char c)
{
	int		whitespace;
	size_t	words;

	whitespace = 1;
	words = 0;
	while (*str)
	{
		while (*str && *str == c)
		{
			whitespace = 1;
			str++;
		}
		while (*str && *str != c)
		{
			whitespace = 0;
			str++;
		}
		if (whitespace == 0)
			words++;
	}
	return (words);
}
