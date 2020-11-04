/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:46:26 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/09 21:09:42 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	num;

	ptr = 0;
	num = count * size;
	if (!(ptr = malloc(num)))
		return (NULL);
	while (num--)
		((char *)ptr)[num] = '\0';
	return (ptr);
}
