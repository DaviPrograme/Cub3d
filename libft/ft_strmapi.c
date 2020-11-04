/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:51:50 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/09 15:21:38 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	cont;
	char			*ptr;

	cont = 0;
	if (!s || !(ptr = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return (NULL);
	while (s[cont])
	{
		ptr[cont] = f(cont, s[cont]);
		++cont;
	}
	return (ptr);
}
