/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:40:00 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/22 21:09:10 by nazouz           ###   ########.fr       */
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
