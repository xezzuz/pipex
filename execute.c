/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:59:13 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/18 20:01:59 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_cmd(t_pipex pipex)
{
	execve(pipex.cmds_paths[0], pipex.cmd1, NULL);
	execve(pipex.cmds_paths[1], pipex.cmd2, NULL);
}
