/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:07:06 by jtong             #+#    #+#             */
/*   Updated: 2021/10/21 11:25:14 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	die_print(int errnum, char *program, char *file)
{
	ft_putstr_fd(program, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (file)
	{
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(strerror(errnum), STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
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
