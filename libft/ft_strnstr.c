/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:53:52 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:53:54 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *orig, const char *base, size_t size)
{
	unsigned int	con1;
	unsigned int	con2;
	unsigned int	ver;

	con1 = 0;
	con2 = 0;
	while (orig[con1] != '\0' && base[0] != '\0')
	{
		ver = con1;
		while (orig[con1] == base[con2] && base[con2] != '\0' && (con1 < size))
		{
			++con1;
			++con2;
		}
		if (base[con2] == '\0')
			return (&(((char *)orig)[con1 - (con2)]));
		else
			con2 = 0;
		con1 = ver + 1;
	}
	if (base[0] == '\0')
		return ((char *)orig);
	return (0);
}
