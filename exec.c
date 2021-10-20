/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jtong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 03:40:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 03:55:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "libft.h"


void	die(char *e)
{
	fprintf(stderr, "%s\n", e);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	int		link[2];
	pid_t	pid;
	char	foo[4096];

	if (argc < 2)
	{
		printf("Usage %s <cmd>\n", argv[0]);
		die("");
	}

	if (pipe(link) == -1)
		die("pipe");

	if ((pid = fork()) == -1)
		die("fork");

	if (pid == 0)
	{
		dup2(link[1], STDOUT_FILENO);
		close(link[0]);
		char	**cmd_args = ft_strsplit(argv[1], ' ');
		printf("filename: '%s', command: '%s'\n", cmd_args[0], argv[1]);
		if (execve(cmd_args[0], cmd_args, __environ) == -1)
		{
			printf("execve err: %s\n", strerror(errno));
			die("execve");
		}
		//close(link[1]);
		die("child finish");
	}
	else
	{
		close(link[1]);
		int		nbytes = read(link[0], foo, sizeof(foo));
		printf("Output: (%.*s)\n", nbytes, foo);
		wait(NULL);
	}
	return (0);
}
