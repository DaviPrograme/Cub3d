/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:51:54 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:51:57 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *orig, size_t size)
{
	size_t	cont;
	size_t	cont2;

	cont = 0;
	cont2 = 0;
	if (!dest && !orig)
		return (0);
	while (orig[cont] != '\0')
		++cont;
	while ((cont2 < (size - 1)) && size && orig[cont2])
	{
		dest[cont2] = orig[cont2];
		++cont2;
	}
	if (size)
		dest[cont2] = '\0';
	return (cont);
}
