/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:06:56 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:48:34 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(int n, char c)
{
	write(c, &n, 1);
}

static void	ft_negativos_extreme(int nb, int n)
{
	int		numb;
	int		array[20];
	int		i;
	int		cont;

	i = 0;
	ft_putchar('-', n);
	ft_putchar('2', n);
	numb = (nb + 2000000000) * -1;
	while (numb - 1 >= 0)
	{
		cont = numb % 10;
		array[i] = cont;
		numb = numb / 10;
		i = i + 1;
	}
	while (--i >= 0)
	{
		ft_putchar((48 + array[i]), n);
	}
}

static void	ft_negativos(int nb, int n)
{
	int		numb;
	int		array[20];
	int		i;
	int		cont;

	i = 0;
	numb = nb * -1;
	while (numb - 1 >= 0)
	{
		cont = numb % 10;
		array[i] = cont;
		numb = numb / 10;
		i = i + 1;
	}
	ft_putchar('-', n);
	while (--i >= 0)
	{
		ft_putchar((48 + array[i]), n);
	}
}

static void	ft_positivos(int nb, int n)
{
	int		numb;
	int		array[20];
	int		i;
	int		cont;

	i = 0;
	numb = nb;
	while (numb - 1 >= 0)
	{
		cont = numb % 10;
		array[i] = cont;
		numb = numb / 10;
		i = i + 1;
	}
	while (--i >= 0)
	{
		ft_putchar((48 + array[i]), n);
	}
}

void		ft_putnbr_fd(int nb, int n)
{
	if (nb == -2147483648)
	{
		ft_negativos_extreme(nb, n);
	}
	else if (nb == 0)
	{
		ft_putchar('0', n);
	}
	else if (nb > -2147483648 && nb < 0)
	{
		ft_negativos(nb, n);
	}
	else
	{
		ft_positivos(nb, n);
	}
}
