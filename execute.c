/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:59:13 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/22 21:43:54 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_duplicate(int read_fd, int write_fd, t_pipex pipex, int i)
{
	if (dup2(read_fd, 0) == -1)
		(perror("pipex"), exit(EXIT_FAILURE));
	close(read_fd);
	if (dup2(write_fd, 1) == -1)
		(perror("pipex"), exit(EXIT_FAILURE));
	close(write_fd);
	if (!pipex.cmds_paths[i])
		(ft_printf("pipex: command not found: %s\n", pipex.cmds_args[i][0]), exit(EXIT_FAILURE));
	execve(pipex.cmds_paths[i], pipex.cmds_args[i], NULL);
	perror("pipex");
	exit(EXIT_FAILURE);
}

void	ft_exec_cmd(t_pipex pipex)
{
	int		i;
	int		j;
	int		ids[pipex.cmds_nbr];
	int		fd[2];

	i = 0;
	pipex.in_fd = pipex.infile_fd;
	while (i < pipex.cmds_nbr)
	{
		pipe(fd);
		ids[i] = fork();
		if (ids[i] == 0)	//	CHILD
		{
			close(fd[0]);
			if (i != pipex.cmds_nbr - 1)
				ft_duplicate(pipex.in_fd, fd[1], pipex, i);
			else
				ft_duplicate(pipex.in_fd, pipex.outfile_fd, pipex, i);
		}
		else			//	PARENT
		{
			close(fd[1]);
			close(pipex.in_fd);
			pipex.in_fd = fd[0];
			i++;
		}
	}
	j = 0;
	while (j < i)
		waitpid(ids[j++], NULL, 0);
	close(pipex.in_fd);
	close(pipex.outfile_fd);
}
