/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:44:27 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:44:30 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int	cont;
	char			*ptr1;
	char			*ptr2;

	cont = 0;
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	if (ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	while (cont < n)
	{
		ptr1[cont] = ptr2[cont];
		++cont;
	}
	return (s1);
}
