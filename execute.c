/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:59:13 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/19 18:23:52 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_cmd(t_pipex pipex)
{
	int		id;
	int		fd[2];

	pipe(fd);		// PROTECTION
	id = fork();	// PROTECTION
	if (id == 0)
	{
		int fd1 = open(pipex.infile, O_RDONLY);		// PROTECTION
		dup2(fd1, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		execve(pipex.cmds_paths[0], pipex.cmd1, NULL);
		close(fd[1]);
		close(fd1);
	}
	else
	{
		int fd2 = open(pipex.outfile, O_RDWR | O_CREAT | O_TRUNC , 0644);	// PROTECTION
		dup2(fd[0], 0);
		dup2(fd2, 1);
		close(fd[1]);
		execve(pipex.cmds_paths[1], pipex.cmd2, NULL);
		close(fd[0]);
		close(fd2);
		wait(NULL);
	}
}
