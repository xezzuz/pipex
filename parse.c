/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:15:34 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/22 21:52:37 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_args(t_pipex *pipex)
{
	int			i;

	i = 0;
	while (pipex->cmds_args[i])
	{
		if (access(pipex->cmds_args[i][0], X_OK) == 0)
			pipex->cmds_paths[i] = pipex->cmds_args[i][0];
		else
			pipex->cmds_paths[i] = ft_check_cmd(pipex->cmds_args[i], pipex->paths);
		i++;
	}
	pipex->cmds_paths[i] = NULL;
}

void	ft_open_io_files(t_pipex *pipex)
{
	pipex->infile_fd = open(pipex->infile, O_RDONLY);
	if (pipex->infile_fd == -1)
		(perror("pipex"), ft_exit(pipex, 1));
	pipex->outfile_fd = open(pipex->outfile, O_RDWR | O_CREAT | O_TRUNC , 0644);
	if (pipex->outfile_fd == -1)
		(perror("pipex"), close(pipex->infile_fd), ft_exit(pipex, 1));
}

void	ft_init_pipex(int argc, char **argv, char **env, t_pipex *pipex)
{
	int			i;

	pipex->cmds_nbr = argc - 3;
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	pipex->paths = ft_get_path(env);
	pipex->cmds_paths = NULL;
	pipex->cmds_args = NULL;
	pipex->cmds_paths = malloc((argc - 2) * sizeof(char *));
	if (!pipex->cmds_paths)
		(perror("pipex"), ft_exit(pipex, 1));
	pipex->cmds_args = malloc((argc - 2) * sizeof(char **));
	if (!pipex->cmds_args)
		(perror("pipex"), ft_exit(pipex, 1));
	i = 0;
	while (i < pipex->cmds_nbr)
	{
		pipex->cmds_args[i] = ft_split(argv[i + 2], ' ');
		if (!pipex->cmds_args[i])
			(perror("pipex"), ft_exit(pipex, 1));
		i++;
	}
	pipex->cmds_args[i] = NULL;
	ft_open_io_files(pipex);
}
