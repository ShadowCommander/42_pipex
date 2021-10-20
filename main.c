/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jtong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:20:45 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 11:15:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// handle invalid file1
// handle no-access file1
// handle cmd1 failure
// handle cmd2 failure
// handle invalid file2
// handle no-access file2

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void	die(int exit_code, char *error_sender)
{
	if (error_sender)
		perror(error_sender);
	exit(exit_code);
}

char	*find_cmd(char *cmd, char **env)
{
	int		index;

	index = 0;
	while (env[index])
	{
		if (ft_strnequ(env[index], "PATH=", 5))
		{
			printf("%s\n", env[index]);
			break;
		}
		index++;
	}
	return (cmd);
}

void	pipex_parent(int *pipefd, char **argv, char **env)
{
	int		infilefd;
	char	**cmd_args;
	char	*cmd;

	close(pipefd[0]);
	infilefd = open(argv[1], O_RDONLY);
	if (infilefd == -1)
		die(EXIT_FAILURE, "open");
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		die(EXIT_FAILURE, "dup2");
	close(pipefd[1]);
	if (dup2(infilefd, STDIN_FILENO) == -1)
		die(EXIT_FAILURE, "dup2");
	cmd_args = ft_strsplit(argv[2], ' ');
	execve(cmd_args[0], cmd_args, env);
	perror("execve");
	close(infilefd);
	close(STDOUT_FILENO);
	wait(NULL);
	die(EXIT_FAILURE, "execve");
}

void	pipex_child(int *pipefd, char **argv, char **env)
{
	int		outfilefd;
	char	**cmd_args;
	char	*cmd;

	close(pipefd[1]);
	outfilefd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (outfilefd == -1)
		die(EXIT_FAILURE, "open");
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		die(EXIT_FAILURE, "dup2");
	close(pipefd[0]);
	if (dup2(outfilefd, STDOUT_FILENO) == -1)
		die(EXIT_FAILURE, "dup2");
	cmd_args = ft_strsplit(argv[3], ' ');
	cmd = find_cmd(cmd_args[0], env);
	execve(cmd_args[0], cmd_args, env);
	perror("execve");
	close(STDOUT_FILENO);
	free(cmd);
	close(outfilefd);
	die(EXIT_FAILURE, "execve");
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	cpid;
	char	buf;
	int		outfilefd;

	if (argc != 5)
	{
		printf("Usage: %s <infile> <cmd1> <cmd2> <outfile>\n", argv[0]);
		return (0);
	}
	if (pipe(pipefd) == -1)
		die(EXIT_FAILURE, "pipe");
	cpid = fork();
	if (cpid == -1)
		die(EXIT_FAILURE, "fork");
	if (cpid != 0)
		pipex_parent(pipefd, argv, env);
	else
		pipex_child(pipefd, argv, env);
}
