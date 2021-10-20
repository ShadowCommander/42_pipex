/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:53:05 by exam              #+#    #+#             */
/*   Updated: 2018/11/14 19:51:41 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		**cpy_words(const char *str, char c, char **output)
{
	int			whitespace;
	const char	*ptr;
	size_t		index;

	index = 0;
	whitespace = 1;
	while (*str)
	{
		while (*str && *str == c)
		{
			whitespace = 1;
			str++;
		}
		ptr = str;
		while (*str && *str != c)
		{
			whitespace = 0;
			str++;
		}
		if (whitespace == 0)
			if (!(output[index++] = ft_strsub(ptr, 0, str - ptr)))
				return (NULL);
	}
	return (output);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**output;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	if (!(output = (char **)malloc(sizeof(*output) * (words + 1))))
		return (NULL);
	output[words] = NULL;
	cpy_words(s, c, output);
	return (output);
}
