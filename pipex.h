/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:07:37 by jtong             #+#    #+#             */
/*   Updated: 2021/10/21 11:09:01 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"

void	die_print(int errnum, char *program, char *file);
void	die(int exit_code, int errnum, char *program, char *file);
void	pipex_free_vars(char *cmd, char **cmd_args);
#endif
