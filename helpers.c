/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:06:40 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/18 17:02:44 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	x(void)
// {
// 	system ("leaks pipex");
// }

// void	ft_print_ll(t_list **lst)
// {
// 	t_list		*current;

// 	current = *lst;
// 	while (current)
// 	{
// 		// printf("[%d]\t", current->index);
// 		printf("[%d]\n", current->content);
// 		// if (current->flag)
// 		// 	printf("[ABOVE MEDIAN]\n");
// 		// else
// 		// 	printf("[BELOW MEDIAN]\n");
// 		current = current->next;
// 	}
// }

void	ft_print_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		printf("matrix[%d] = %s\n", i, matrix[i]);
		i++;
	}
	printf("\n");
}

void	ft_print_int(int *array, int i, int length)
{
	// int		i;

	// i = 0;
	while (i < length)
	{
		printf("[%d]", array[i]);
		i++;
	}
	printf("\n");
}