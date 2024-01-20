/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:40:00 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/20 11:11:00 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **env)
{
	int			i;
	int			found;
	char		**paths;

	i = 0;
	found = 0;
	while (*env)
	{
		if (!ft_strncmp("PATH", *env, 4))
		{
			found = 1;
			break ;
		}
		env++;
	}
	if (!found)
		return (NULL);
	paths = ft_split((*env) + 5, ':');
	return (paths);
}

char	*ft_check_cmd(char **cmd, char **paths)
{
	int			i;
	char		*temp;
	char		*result;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		result = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(result, X_OK) == 0)
			return (result);
		free(result);
		i++;
	}
	return (NULL);
}

void	ft_check_args(t_pipex *pipex)
{
	ft_check_files(*pipex);
	int i = 0;
	while (pipex->cmds_args[i])
	{
		if (access(pipex->cmds_args[i][0], X_OK) == 0)
			pipex->cmds_paths[i] = pipex->cmds_args[i][0];
		else
		{
			pipex->cmds_paths[i] = ft_check_cmd(pipex->cmds_args[i], pipex->paths); //free
			if (!pipex->cmds_paths[i])
			{
				ft_putstr_fd("pipex: command not found: cmd\n", 2);
				exit(1);
			}
		}
		i++;
	}
	pipex->cmds_paths[i] = NULL;
}
