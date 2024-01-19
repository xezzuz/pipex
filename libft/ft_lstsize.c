/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:53 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/14 16:54:34 by nazouz           ###   ########.fr       */
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
	ft_get_flag(first, i);
	return (i);
}
