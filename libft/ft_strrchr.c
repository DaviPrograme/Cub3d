/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:54:28 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:54:31 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char		*ft_strrchr(const char *frase, int cr)
{
	const char	*ptr;
	int			cont;

	cont = 0;
	ptr = 0;
	while (frase[cont] != '\0')
	{
		if (frase[cont] == cr)
			ptr = &frase[cont];
		++cont;
	}
	if (cr == '\0')
		return (&frase[cont]);
	return (ptr);
}
