/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:59:13 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/20 17:47:31 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	spawn_child(int read_fd, int write_fd, t_pipex pipex, int i)
{
	if (read_fd != 0)
	{
		dup2(read_fd, 0);
		close(read_fd);
	}
	if (write_fd != 1)
	{
		dup2(write_fd, 1);
		close(write_fd);
	}
	execve(pipex.cmds_paths[i], pipex.cmds_args[i], NULL);
}

void	ft_exec_cmd(t_pipex pipex)
{
	int		i;
	int		j;
	// int		id;
	int		ids[pipex.cmds_nbr];
	int		fd[2];

	pipex.in_fd = open(pipex.infile, O_RDONLY);
	i = 0;
	while (i < pipex.cmds_nbr)
	{
		pipe(fd);
		ids[i] = fork();
		if (ids[i] == 0)	//	CHILD
		{
			// close(fd[0]);
			if (i == pipex.cmds_nbr - 1)
			{
				pipex.out_fd = open(pipex.outfile, O_RDWR | O_CREAT | O_TRUNC , 0644);
				spawn_child(pipex.in_fd, pipex.out_fd, pipex, i);
			}
			else
				spawn_child(pipex.in_fd, fd[1], pipex, i);
		}
		else			//	PARENT
		{
			close(fd[1]);
			close(pipex.in_fd);
			pipex.in_fd = fd[0];
			i++;
		}
	}
	// spawn_child(pipex.in_fd, pipex.out_fd, pipex, i);
	j = 0;
	while (j < i)
		waitpid(ids[j++], NULL, 0);
	close(pipex.in_fd);
	//close(pipex.out_fd);
}
