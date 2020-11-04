/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:43:31 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:43:35 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	void			*frase;
	unsigned int	cont;
	char			letra;

	frase = (void *)s1;
	cont = 0;
	letra = c;
	while (cont < n)
	{
		if (((char *)frase)[cont] == letra)
			return (frase + cont);
		++cont;
	}
	return (0);
}
