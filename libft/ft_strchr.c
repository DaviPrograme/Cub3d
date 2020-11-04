/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:49:49 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 19:49:52 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char		*ft_strchr(const char *frase, int cr)
{
	const char	*ptr;
	int			cont;

	cont = 0;
	while (frase[cont] != cr && frase[cont] != '\0')
		++cont;
	if (frase[cont] == cr)
	{
		ptr = &frase[cont];
		return (ptr);
	}
	return (0);
}
