/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:15:34 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/18 19:51:26 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(char **argv, char **env, t_pipex *pipex)
{
	pipex->infile = argv[1];
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->outfile = argv[4];
	pipex->paths = ft_get_path(env);
	pipex->cmds_paths = malloc(3 * sizeof(char *));
	if (!pipex->cmds_paths)
	{
		ft_putstr_fd("Error: Allocation failed\n", 2);
		exit(1);
	}
}

int	ft_check_files(t_pipex pipex)
{
	int		fd1;
	int		fd2;

	fd1 = open(pipex.infile, O_RDONLY);
	if (fd1 == -1)
	{
		ft_putstr_fd("Error: Cannot open infile\n", 2);
		exit(1);
	}
	close(fd1);
	fd2 = open(pipex.outfile, O_WRONLY | O_CREAT, S_IWUSR);
	close(fd2);
	return (1);
}
