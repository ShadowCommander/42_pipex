/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jtong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 07:55:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 07:56:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int	die(int e, int pf)
{
	return (e);
}

int	main(int argc, char **argv)
{
	char	**cmd_args;
	int		infile;
	int		newfd;
	int		i;

	if (argc != 3)
		die(EXIT_FAILURE, printf("Usage: %s <file> <cmd>\n", argv[0]));
	infile = open(argv[1], O_RDONLY);
	newfd = dup2(infile, STDIN_FILENO);
	if (newfd != 0)
		die(EXIT_FAILURE, printf("fd dup failed\n"));
	close(infile);
	cmd_args = ft_strsplit(argv[2], ' ');
	execve(cmd_args[0], cmd_args, __environ);
	i = 0;
	while (cmd_args[i])
	{
		free(cmd_args[i]);
		i++;
	}
	free(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}
