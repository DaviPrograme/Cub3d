/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:44:52 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:44:55 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned int	num;

	num = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (++num <= size)
			((char *)dst)[num - 1] = ((char *)src)[num - 1];
	}
	else
	{
		num = size;
		while (num-- > 0)
			((char *)dst)[num] = ((char *)src)[num];
	}
	return (dst);
}
