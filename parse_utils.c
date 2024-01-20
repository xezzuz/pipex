/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:15:34 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/20 12:27:44 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(int argc, char **argv, char **env, t_pipex *pipex)
{
	pipex->cmds_nbr = argc - 3;
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
	pipex->paths = ft_get_path(env);
	pipex->cmds_paths = malloc((argc - 2) * sizeof(char *));
	if (!pipex->cmds_paths)
	{
		ft_putstr_fd("Error: Allocation failed\n", 2);
		exit(1);
	}
	pipex->cmds_args = malloc((argc - 2) * sizeof(char **));
	int i = 2;
	int j = 0;
	while (i < argc - 1)
	{
		pipex->cmds_args[j] = ft_split(argv[i], ' ');
		i++;
		j++;
	}
	pipex->cmds_args[j] = NULL;
}

int	ft_check_files(t_pipex pipex)
{
	int		fd1;

	fd1 = open(pipex.infile, O_RDONLY);
	if (fd1 == -1)
	{
		ft_putstr_fd("Error: Cannot open infile\n", 2);
		exit(1);
	}
	close(fd1);
	return (1);
}
