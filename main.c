/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jtong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:20:45 by user42            #+#    #+#             */
/*   Updated: 2021/10/21 11:26:06 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		ft_strdel(&path);
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
		ft_putstr_fd("Wrong number of arguments\n", STDERR_FILENO);
		ft_putstr_fd("Usage: ", STDERR_FILENO);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd("<infile> <cmd1> <cmd2> <outfile>\n", STDERR_FILENO);
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
