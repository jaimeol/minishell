/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:02:20 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/08 11:00:25 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	do_pwd(t_mini *mini)
{
	char	*path;

	mini->status = 0;
	path = getcwd(NULL, 0);
	if (!path)
	{
		printf("Working directory not set\n");
		return ;
	}
	printf("%s\n", path);
	free(path);
	return ;
}
