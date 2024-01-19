/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:40:00 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/18 19:55:33 by nazouz           ###   ########.fr       */
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
	if (access(*pipex->cmd1, X_OK) == 0)
		pipex->cmds_paths[0] = *pipex->cmd1;
	else
	{
		pipex->cmds_paths[0] = ft_check_cmd(pipex->cmd1, pipex->paths); //free
		if (!pipex->cmds_paths[0])
		{
			ft_putstr_fd("pipex: command not found: cmd1\n", 2);
			exit(1);
		}
	}
	if (access(*pipex->cmd2, X_OK) == 0)
		pipex->cmds_paths[1] = *pipex->cmd2;
	else
	{
		pipex->cmds_paths[1] = ft_check_cmd(pipex->cmd2, pipex->paths);
		if (!pipex->cmds_paths[1])
		{
			ft_putstr_fd("pipex: command not found: cmd2\n", 2);
			exit(1);
		}
	}
	pipex->cmds_paths[2] = NULL;
	// ft_print_matrix(pipex->cmd1);
	// ft_print_matrix(pipex->cmd2);
	// ft_print_matrix(pipex->cmds_paths);
}
