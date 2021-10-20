/* execve.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int		main(int argc, char *argv[])
{
	char	**cmd_args;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	cmd_args = ft_strsplit(argv[1], ' ');

	execve(cmd_args[0], cmd_args, __environ);
	perror("execve");	/* execve() returns only on error */
	exit(EXIT_FAILURE);
}
