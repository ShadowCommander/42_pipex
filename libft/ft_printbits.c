/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:30:18 by jtong             #+#    #+#             */
/*   Updated: 2018/11/14 20:15:36 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printbits(unsigned char octet)
{
	unsigned char	z;
	int				i;
	char			buff[9];

	z = 0x80;
	buff[8] = '\0';
	i = 0;
	while (z != 0)
	{
		if (octet & z)
			buff[i] = '1';
		else
			buff[i] = '0';
		z >>= 1;
		i++;
	}
	write(1, buff, 8);
}
