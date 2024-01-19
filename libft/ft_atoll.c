/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:08:37 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/14 16:54:24 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long long	ft_atoll(const char *str)
{
	int				sign;
	long long		result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str < 14 && *str > 8))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
		result = result * 10 + (*str++ - 48);
	return (result * sign);
}
