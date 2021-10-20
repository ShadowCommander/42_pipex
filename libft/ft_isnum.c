/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jtong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:41:15 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 11:47:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isnum(const char *str, int ignore_whitespace)
{
	if (ignore_whitespace)
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
				*str == '\f' || *str == '\r')
			str++;
	if (*str == '-' || *str == '+')
		if (str[1] >= '0' && str[1] <= '9')
			str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (ignore_whitespace)
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
				*str == '\f' || *str == '\r')
			str++;
	if (*str == '\0')
		return (1);
	return (0);
}
