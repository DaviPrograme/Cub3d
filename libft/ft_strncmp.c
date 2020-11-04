/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:53:25 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:53:28 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *orig, const char *base, size_t size)
{
	size_t cont;

	cont = 0;
	while (orig[cont] == base[cont] && (cont < size) && base[cont] && size)
	{
		if (orig[cont] != '\0' && base[cont] != '\0')
			++cont;
		else
			break ;
	}
	if (cont == size)
		--cont;
	if (size <= 0)
		return (0);
	return (((unsigned char *)orig)[cont] - ((unsigned char *)base)[cont]);
}
