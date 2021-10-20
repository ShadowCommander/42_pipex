/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putull_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:58:55 by jtong             #+#    #+#             */
/*   Updated: 2019/05/02 18:54:56 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putull_fd(unsigned long long n, int fd)
{
	ssize_t	size;

	size = 0;
	if (n >= 10 || n <= -10)
		size = ft_putull_fd(n / 10, fd);
	else if (n < 0)
		size += ft_putchar_fd('-', fd);
	if (n < 0)
		size += ft_putchar_fd(-(n % 10) + '0', fd);
	else
		size += ft_putchar_fd((n % 10) + '0', fd);
	return (size);
}
