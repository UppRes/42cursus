/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExpandDollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:59:22 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 21:59:22 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_dollar(char **dst, char **src)
{
	char	*ptr;

	ptr = *(src) + 1;
	if (*ptr == *DOLLAR)
		double_dollar(dst, src);
	else if (*ptr == *QUSTION_MARK)
		question_mark(dst, src);
	else if (*ptr == ' ' || !*ptr || *ptr == *DOUBLE_QUOTE
		|| *ptr == *SINGLE_QUOTE)
		single_dollar(dst);
	else
		expand_dollar_value(dst, src);
}

void	single_dollar(char **dst)
{
	str_addchar(dst, *DOLLAR);
}

void	double_dollar(char **dst, char **src)
{
	char	*line;

	line = ft_itoa(g_core.main_pid);
	own_strjoin(dst, line);
	free(line);
	(*src)++;
}

void	question_mark(char **dst, char **src)
{
	char	*line;

	line = ft_itoa(g_core.old_exec_output);
	own_strjoin(dst, line);
	free(line);
	(*src)++;
}

void	expand_dollar_value(char **dst, char **src)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = (*src) + 1;
	while (*ptr != ' ' && *(ptr) && *ptr != *DOUBLE_QUOTE
		&& *ptr != *SINGLE_QUOTE && *ptr != '$')
	{
		count++;
		ptr++;
	}
	ptr = ft_strpcpy(NULL, (*src) + 1, count);
	expand_envs(dst, ptr);
	free(ptr);
	*src += count;
}
