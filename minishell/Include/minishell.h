/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:55:57 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 21:56:00 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include "macros.h"
# include "tables.h"
# include "utilits.h"
# include "lexer.h"
# include "expander.h"
# include "parser.h"
# include "executer.h"

t_core	g_core;

//	MAIN
void	init_core(char **env);

void	free_for_loop(void);
void	free_core(void);

void	update_loop(void);
void	update_history(char *cmd);
void	update_exec_output(void);

void	sig_handler(int signum);
int		signal_in_reading(void);
int		signal_while_cmd_works(void);
void	exit_signal_check(void);

#endif
