/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:36:11 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/02 23:26:15 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_parsed(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->parsed[i] != NULL)
	{
		free(mini->parsed[i]->cmd);
		mini->parsed[i]->cmd = NULL;
		free(mini->parsed[i]);
		mini->parsed[i] = NULL;
		i++;
	}
	free(mini->parsed);
	mini->parsed = NULL;
}

void	free_input_words(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->input.words[i] != NULL)
	{
		free(mini->input.words[i]);
		i++;
	}
	free(mini->input.words);
}

void	free_stuff(t_mini *mini)
{
	free_input_words(mini);
	if (mini->cmd_num != 1)
		free_parsed(mini);
}
