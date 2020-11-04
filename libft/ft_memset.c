/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:45:34 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:45:36 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *frase, int letra, size_t size)
{
	unsigned char	*fra;
	size_t			cont;

	cont = 0;
	fra = frase;
	while (cont < size)
	{
		fra[cont] = letra;
		++cont;
	}
	return (frase);
}
