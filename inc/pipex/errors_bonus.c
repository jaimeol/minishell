/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:28:32 by jolivare          #+#    #+#             */
/*   Updated: 2024/08/02 10:38:45 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipe_error(void)
{
	printf("Pipe error\n");
	exit(1);
}

void	args_error(void)
{
	printf("Invalid args: [infile cmd1 cmd2 outfile]\n");
	exit (1);
}

void	here_doc_error(void)
{
	printf("Invalid args: [here_doc limiter cmd... outfile]\n");
}

void	child_error(t_pipe *pipe)
{
	perror("error");
	close(pipe->tube[0]);
	close(pipe->tube[1]);
	close(pipe->infile_fd);
	close(pipe->outfile_fd);
	exit(127);
}
