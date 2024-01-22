/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:54:31 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/22 22:01:37 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **array)
{
	int		i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
}

void	ft_exit(t_pipex *pipex, int status)
{
	int			i;

	ft_free_array(pipex->paths);
	i = 0;
	while (i < pipex->cmds_nbr)
		free(pipex->cmds_paths[i++]);
	free(pipex->cmds_paths);
	i = 0;
	if (pipex->cmds_args)
	{
		while (pipex->cmds_args[i])
			ft_free_array(pipex->cmds_args[i++]);
		free(pipex->cmds_args);
	}
	exit(status);
}
