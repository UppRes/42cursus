/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunCommand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcayir <bcayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:58:49 by bcayir            #+#    #+#             */
/*   Updated: 2023/01/07 21:58:49 by bcayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_multiple_command(t_cmdlist *cmd_list)
{
	int			*fd;

	fd = create_pipe();
	while (cmd_list)
	{
		switch_pipe(&fd);
		pipe(&fd[2]);
		cmd_list->pid = fork();
		if (cmd_list->pid <= 0)
			run_process(cmd_list, fd, 2);
		cmd_list = cmd_list->next;
		if (fd[4] && fd[5])
		{
			close(fd[4]);
			close(fd[5]);
			fd[4] = 0;
			fd[5] = 0;
		}
	}
	clear_pipe(fd);
	wait_all();
}

void	run_single_command(t_cmdlist *cmd_list, int *fd)
{
	if (cmd_list->infile != SSTDERR && cmd_list->outfile != SSTDERR)
		exec_command(cmd_list, fd, -1);
}
