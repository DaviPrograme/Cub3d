/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:43:59 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:44:02 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*ptr1;
	unsigned char		*ptr2;
	size_t				con;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	con = 0;
	while (con < n)
	{
		if (ptr1[con] == ptr2[con])
			++con;
		else
			return ((ptr1[con]) - (ptr2[con]));
	}
	return (0);
}
