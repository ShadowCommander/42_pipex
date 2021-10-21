/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jtong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:28:05 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 09:31:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		printf("Usage: %s <file> [line1] [line2] [line3...]", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	printf("%d\n", fd);
//	fd = open(argv[1], O_WRONLY | O_CREAT);
//	for (int i = 2; i < argc; i++)
//	{
//		dprintf(fd, "%s\n", argv[i]);
//	}
}
