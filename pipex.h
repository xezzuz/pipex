/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:56:39 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/22 21:52:00 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	int		cmds_nbr;
	char	*infile;
	int		infile_fd;
	char	*outfile;
	int		outfile_fd;
	int		in_fd;
	int		out_fd;
	char	**cmds_paths;
	char	***cmds_args;
	char	**paths;
}	t_pipex;

//	LIBFT
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

//	PRINTF
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_printhex(unsigned int n, char *hex);
int		ft_printu(unsigned int n);
int		ft_print_add(void *ptr);
int		ft_printf(const char *format, ...);

//	HELPERS
void	ft_print_matrix(char **matrix);

//	PIPEX
void	ft_init_pipex(int argc, char **argv, char **env, t_pipex *pipex);
void	ft_check_args(t_pipex *pipex);
void	ft_open_io_files(t_pipex *pipex);
char	**ft_get_path(char **env);
void	ft_exec_cmd(t_pipex pipex);
void	ft_exit(t_pipex *pipex, int status);
char	*ft_check_cmd(char **cmd, char **paths);

#endif