/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:42:00 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:42:04 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned char	letra;
	unsigned int	cont;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	letra = c;
	cont = 0;
	while ((cont < n) && (n > 0))
	{
		ptr1[cont] = ptr2[cont];
		if (ptr1[cont] == letra)
			return (s1 + cont + 1);
		++cont;
	}
	return (0);
}
