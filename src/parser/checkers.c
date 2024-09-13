/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:24:25 by rpisoner          #+#    #+#             */
/*   Updated: 2024/09/05 21:26:01 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	quote_check(t_mini *mini, int i)
{
	if (mini->input.raw_info[i] == '\''
		|| mini->input.raw_info[i] == '\"')
	{
		if (mini->quoted == 0)
		{
			mini->quoted = 1;
			mini->t_quote = mini->input.raw_info[i];
		}
		else if (mini->input.raw_info[i] == mini->t_quote)
			mini->quoted = 0;
	}
}

void	pipe_check(t_mini *mini, int *i, int *j, int *k)
{
	char	*token;

	if (mini->input.raw_info[*i] == '|' && mini->quoted == 0)
	{
		store_word(mini, j, k);
		token = (char *)malloc(sizeof(char) * 2);
		if (!token)
			malloc_error();
		token[0] = '|';
		token[1] = '\0';
		mini->input.words[(*k)++] = token;
		mini->ign_char = 1;
	}
}

void	expander_check(t_mini *mini, int *i, int *j)
{
	char	*variable_name;
	char	*var_content;

	variable_name = NULL;
	var_content = NULL;
	if ((mini->input.raw_info[*i] == '$' && !(mini->quoted))
		|| (mini->input.raw_info[*i] == '$' && mini->quoted
			&& mini->t_quote == '\"'))
	{
		variable_name = var_name(mini, *(i));
		var_content = search_var(mini, variable_name);
		(*i) += ft_strlen(variable_name);
		free(variable_name);
		mini->ign_char = 1;
		if (!var_content)
			return ;
		annex_content(mini, var_content, j);
	}
}

void	checkers(t_mini *mini, int *i, int *j, int *k)
{
	quote_check(mini, *i);
	pipe_check(mini, i, j, k);
	expander_check(mini, i, j);
}