/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:38:53 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/18 16:20:07 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ini_dst;

	if (dst == src)
		return (dst);
	ini_dst = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (ini_dst);
}
