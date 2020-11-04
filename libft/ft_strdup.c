/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:55:09 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/04 13:11:33 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	cont;
	size_t	cont2;
	char	*ptr1;

	cont = 0;
	cont2 = 0;
	while (s1[cont] != '\0')
		++cont;
	if (!(ptr1 = (char *)malloc((cont * sizeof(unsigned char) + 1))))
		return (0);
	while (cont2 <= (cont * sizeof(char)))
	{
		ptr1[cont2] = ((char *)s1)[cont2];
		++cont2;
	}
	return (ptr1);
}
