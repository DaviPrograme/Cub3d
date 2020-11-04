/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:37:22 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:00:02 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cont_letras(const char *s, char c)
{
	int			cont;

	cont = 0;
	while (s[cont] != c && s[cont] != '\0')
		++cont;
	return (cont);
}

static size_t	cont_palavra(char const *s, char c)
{
	size_t		cont;
	size_t		palavras;
	size_t		ver;
	size_t		start;

	cont = 0;
	palavras = 0;
	ver = 0;
	while (s[cont])
	{
		start = ver;
		if (s[cont] == c)
			ver = 0;
		else
			ver = 1;
		if (start != ver && start == 1)
			++palavras;
		++cont;
	}
	if (ver == 1)
		++palavras;
	return (palavras);
}

char			**ft_split(char const *s, char c)
{
	size_t		palavras;
	char		**result;
	int			cont;

	if (!s)
		return (0);
	palavras = cont_palavra(s, c);
	if (!(result = ft_calloc(palavras + 1, sizeof(char *))))
		return (0);
	cont = -1;
	palavras = 0;
	while (s[++cont])
	{
		if (s[cont] != c && s[cont] != '\0')
		{
			result[palavras] = ft_substr(s, cont, cont_letras(&s[cont], c));
			++palavras;
			cont = cont + cont_letras(&s[cont], c) - 1;
		}
	}
	return (result);
}
