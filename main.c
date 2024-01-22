/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:56:24 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/22 22:13:31 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	aa(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **env)
{
	t_pipex		pipex;

	if (argc != 5)
		return (ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2), 1);
	ft_init_pipex(argc, argv, env, &pipex);
	ft_check_args(&pipex);
	ft_exec_cmd(&pipex);
	atexit(aa);
	ft_exit(&pipex, 0);
}
