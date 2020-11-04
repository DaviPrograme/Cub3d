/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:59:33 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:07:25 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	atribuir_valor(int *vetor, const char *s1)
{
	vetor[0] = 0;
	vetor[1] = ft_strlen(s1) - 1;
}

static int	verificar_caracter(char const s1, char const *set)
{
	int		cont;

	cont = 0;
	while (set[cont] != '\0')
	{
		if (s1 == set[cont])
			return (1);
		++cont;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		marcador[2];
	int		cont;

	if (!s1 || !set)
		return (0);
	atribuir_valor(marcador, s1);
	while (s1[marcador[0]] != '\0')
	{
		if ((verificar_caracter(s1[marcador[0]], set)))
			marcador[0] = marcador[0] + 1;
		else
			break ;
	}
	while ((&s1[marcador[0]] != &s1[marcador[1]]) && s1[marcador[0]] != '\0')
	{
		if ((verificar_caracter(s1[marcador[1]], set)))
			marcador[1] = marcador[1] - 1;
		else
			break ;
	}
	cont = marcador[0] > marcador[1] ? 0 : marcador[1] - marcador[0] + 1;
	return (ft_substr(s1, marcador[0], cont));
}
