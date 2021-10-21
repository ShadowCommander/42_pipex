/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:53:05 by exam              #+#    #+#             */
/*   Updated: 2021/10/21 11:43:19 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**cpy_words(const char *str, char c, char **output)
{
	int			whitespace;
	const char	*ptr;
	size_t		index;

	index = 0;
	whitespace = 1;
	while (*str)
	{
		if (*str && *str == c)
			whitespace = 1;
		while (*str && *str == c)
			str++;
		ptr = str;
		if (*str && *str != c)
			whitespace = 0;
		while (*str && *str != c)
			str++;
		if (whitespace != 0)
			continue ;
		output[index] = ft_strsub(ptr, 0, str - ptr);
		if (!output[index++])
			return (NULL);
	}
	return (output);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**output;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	output = (char **)malloc(sizeof(*output) * (words + 1));
	if (!output)
		return (NULL);
	output[words] = NULL;
	cpy_words(s, c, output);
	return (output);
}
