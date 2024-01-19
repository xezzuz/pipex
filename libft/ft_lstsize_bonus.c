/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:15:03 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/14 19:16:17 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	size_t		i;
	t_list		*first;

	i = 0;
	first = lst;
	while (lst != NULL)
	{
		lst->index = i;
		lst = lst->next;
		i++;
	}
	return (i);
}
