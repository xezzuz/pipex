/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:59:13 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/22 22:14:26 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_wait_and_close(t_pipex pipex, int *ids)
{
	int			i;

	i = 0;
	while (i < pipex.cmds_nbr)
		waitpid(ids[i++], NULL, 0);
	close(pipex.in_fd);
	close(pipex.outfile_fd);
}

void	ft_duplicate(int read_fd, int write_fd, t_pipex pipex, int i)
{
	if (dup2(read_fd, 0) == -1)
		(perror("pipex"), exit(EXIT_FAILURE));
	close(read_fd);
	if (dup2(write_fd, 1) == -1)
		(perror("pipex"), exit(EXIT_FAILURE));
	close(write_fd);
	if (!pipex.cmds_paths[i])
		(ft_printf("pipex: command not found: %s\n",
				pipex.cmds_args[i][0]), exit(EXIT_FAILURE));
	execve(pipex.cmds_paths[i], pipex.cmds_args[i], NULL);
	perror("pipex");
	exit(EXIT_FAILURE);
}

void	ft_exec_cmd(t_pipex *pipex)
{
	int		i;
	int		*ids;
	int		fd[2];

	i = 0;
	pipex->in_fd = pipex->infile_fd;
	ids = malloc(pipex->cmds_nbr * sizeof(int));
	if (!ids)
		(perror("pipex"), ft_exit(pipex, 1));
	while (i < pipex->cmds_nbr)
	{
		pipe(fd);
		ids[i] = fork();
		if (ids[i] == 0)
		{
			close(fd[0]);
			if (i != pipex->cmds_nbr - 1)
				ft_duplicate(pipex->in_fd, fd[1], *pipex, i);
			else
				ft_duplicate(pipex->in_fd, pipex->outfile_fd, *pipex, i);
		}
		else
			(close(fd[1]), close(pipex->in_fd), pipex->in_fd = fd[0], i++);
	}
	ft_wait_and_close(*pipex, ids);
}
