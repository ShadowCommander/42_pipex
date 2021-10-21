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
#include <errno.h>

void	die_print(int errnum, char *program, char *file)
{
	char	*err;

	write(STDERR_FILENO, program, ft_strlen(program));
	write(STDERR_FILENO, ": ", 2);
	if (file)
	{
		write(STDERR_FILENO, file, ft_strlen(file));
		write(STDERR_FILENO, ": ", 2);
	}
	err = strerror(errnum);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
}

void	die(int exit_code, int errnum, char *program, char *file)
{
	die_print(errnum, program, file);
	exit(exit_code);
}

void	pipex_free_vars(char *cmd, char **cmd_args)
{
	int		i;

	free(cmd);
	i = 0;
	while (cmd_args[i])
	{
		free(cmd_args[i]);
		i++;
	}
	free(cmd_args);
}

char	*find_cmd(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*tmp_cmd;
	char	*path;

	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (env[i] && !ft_strnequ(env[i], "PATH=", 5))
		i++;
	paths = ft_strsplit(env[i] + 5, ':');
	tmp_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], tmp_cmd);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	pipex_free_vars(tmp_cmd, paths);
	if (path == NULL)
		path = ft_strdup(cmd);
	return (path);
}

void	pipex_parent(int child_pid, int *pipefd, char **argv, char **env)
{
	int		outfilefd;
	char	**cmd_args;
	char	*cmd;
	int		w;
	int		wstatus;

	close(pipefd[1]);
	outfilefd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (outfilefd == -1)
		die(EXIT_FAILURE, errno, argv[0], argv[4]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		die(EXIT_FAILURE, errno, argv[0], "dup2 failed to dup STDIN_FILENO");
	close(pipefd[0]);
	if (dup2(outfilefd, STDOUT_FILENO) == -1)
		die(EXIT_FAILURE, errno, argv[0], "dup2 failed to dup STDOUT_FILENO");
	w = waitpid(child_pid, &wstatus, 0);
//	dprintf(fd, "waitpid: %d %d %s\n", w, wstatus, strerror(errno));
	cmd_args = ft_strsplit(argv[3], ' ');
	cmd = find_cmd(cmd_args[0], env);
	execve(cmd, cmd_args, env);
	close(outfilefd);
	pipex_free_vars(cmd, cmd_args);
	exit(EXIT_FAILURE);
}

void	pipex_child(int *pipefd, char **argv, char **env)
{
	int		infilefd;
	char	**cmd_args;
	char	*cmd;

	close(pipefd[0]);
	infilefd = open(argv[1], O_RDONLY);
	if (infilefd == -1)
		die(EXIT_FAILURE, errno, argv[0], argv[1]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		die(EXIT_FAILURE, errno, argv[0], "dup2 failed to dup STDOUT_FILENO");
	close(pipefd[1]);
	if (dup2(infilefd, STDIN_FILENO) == -1)
		die(EXIT_FAILURE, errno, argv[0], "dup2 failed to dup STDIN_FILENO");
	cmd_args = ft_strsplit(argv[2], ' ');
	cmd = find_cmd(cmd_args[0], env);
	int		fd = open("error.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
	dprintf(fd, "# new run\n");
	dprintf(fd, "%s: infilefd: %d, \n", cmd, infilefd);
	execve(cmd, cmd_args, env);
	die_print(errno, argv[0], argv[1]);
	close(infilefd);
	close(STDOUT_FILENO);
	pipex_free_vars(cmd, cmd_args);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	cpid;
	char	buf;
	int		outfilefd;

	if (argc != 5)
	{
		printf("Wrong number of arguments\n");
		printf("Usage: %s <infile> <cmd1> <cmd2> <outfile>\n", argv[0]);
		return (0);
	}
	if (pipe(pipefd) == -1)
		die(EXIT_FAILURE, errno, argv[0], "pipe");
	cpid = fork();
	if (cpid == -1)
		die(EXIT_FAILURE, errno, argv[0], "fork");
	if (cpid != 0)
		pipex_parent(cpid, pipefd, argv, env);
	else
		pipex_child(pipefd, argv, env);
}
