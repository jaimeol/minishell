/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:58:41 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/14 15:18:24 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	unclosed_quote_check(t_mini *mini)
{
	if (mini->quoted)
	{
		mini->quoted = 0;
		mini->unclosed_quote = 1;
		printf("Error: comillas sin cerrar\n");
		return (1);
	}
	return (0);
}

void	malloc_error(void)
{
	printf("Error en alocación de memoria\n");
	exit (1);
}

void	exec_error(t_mini *mini)
{
	perror("Error");
	check_here_doc(mini);
	exit(127);
}

void	pipe_error(void)
{
	printf("Pipe error\n");
	exit(1);
}
