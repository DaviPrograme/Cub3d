/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:02:10 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:02:16 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *frase, size_t size)
{
	unsigned char	*ptr;
	unsigned int	cont;

	cont = 0;
	ptr = frase;
	while (cont < size)
	{
		ptr[cont] = 0;
		++cont;
	}
}
