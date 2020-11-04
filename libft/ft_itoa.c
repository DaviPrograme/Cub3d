/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:10:59 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/07 18:23:14 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alocador(int n, int cont)
{
	int		vetor[2];
	char	*ptr;

	vetor[0] = n;
	vetor[1] = n;
	if (!(ptr = (char *)ft_calloc(cont + 1, sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		while (--cont)
		{
			vetor[0] = vetor[1] / 10;
			ptr[cont] = 48 + (-vetor[1] + (vetor[0] * 10));
			vetor[1] = vetor[1] / 10;
		}
		return (ptr);
	}
	while (--cont >= 0)
	{
		vetor[0] = vetor[1] / 10;
		ptr[cont] = 48 + (vetor[1] - (vetor[0] * 10));
		vetor[1] = vetor[1] / 10;
	}
	return (ptr);
}

char		*ft_itoa(int n)
{
	int		cont;
	int		numb;
	char	*ptr;

	numb = n;
	cont = 0;
	if (n == 0)
	{
		ptr = (char *)ft_calloc(2, sizeof(char));
		ptr[0] = 48;
		return (ptr);
	}
	while (numb != 0 && ++cont)
		numb = numb / 10;
	if (n < 0)
		++cont;
	ptr = alocador(n, cont);
	return (ptr);
}
