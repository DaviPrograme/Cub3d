/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_maps2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_map2d	g_map2d;
extern t_map3d	g_map3d;

int			valid_map2d(void)
{
	if ((let_matrix_map2d()))
		return (1);
	return (verifica_map2d());
}

int			let_matrix_map2d(void)
{
	int		cont;
	int		chr;
	char	*ptr;

	cont = -1;
	chr = 0;
	ptr = g_map2d.string;
	while (ptr[++cont])
	{
		if (ptr[cont] == '0' || ptr[cont] == '1' || ptr[cont] == '2')
			continue;
		else if ((ptr[cont] == 'N' || ptr[cont] == 'S') && !chr)
			++chr;
		else if ((ptr[cont] == 'E' || ptr[cont] == 'W') && !chr)
			++chr;
		else if (ptr[cont] != ' ' && ptr[cont] != '\n')
			return (set_error(6, 14, 7));
	}
	if (chr == 0)
		return (set_error(6, 14, 7));
	return (0);
}

int			verifica_map2d(void)
{
	int		cont[3];

	cont[0] = -1;
	cont[2] = 0;
	while (++cont[0] <= g_map2d.mtx_lgh)
	{
		cont[1] = -1;
		while (++cont[1] < g_map2d.mtx_wdh)
		{
			(g_map2d.matrix[cont[0]][cont[1]] == '1') ? cont[2] = 0 : 0;
			if (g_map2d.matrix[cont[0]][cont[1]] == '1')
				continue;
			else if (g_map2d.matrix[cont[0]][cont[1]] == ' ')
				continue;
			if (!cont[2])
			{
				if ((horizontal_map2d(cont[0], cont[1])))
					return (set_error(6, 15, 7));
				cont[2] = 1;
			}
			if ((vertical_map2d(cont[0], cont[1])))
				return (set_error(6, 15, 7));
		}
	}
	return (0);
}

int			horizontal_map2d(int lgh, int wdh)
{
	int		x;
	int		ver;

	x = wdh;
	ver = 0;
	while (x > 0 && ver < 2 && g_map2d.matrix[lgh][x] != ' ')
	{
		if (x >= wdh && x < g_map2d.mtx_wdh && ver == 0)
			++x;
		else if (((x == g_map2d.mtx_wdh || x > wdh) && ver == 1) && wdh)
			x = wdh - 1;
		else if (g_map2d.matrix[lgh][x] == '\0')
			return (1);
		else if (x < wdh && ((x - 1) >= 0))
			--x;
		(g_map2d.matrix[lgh][x] == '1') ? ++ver : 0;
	}
	if (ver != 2)
		return (1);
	return (0);
}

int			vertical_map2d(int lgh, int wdh)
{
	int		y;
	int		ver;

	y = lgh;
	ver = 0;
	while (y > 0 && ver < 2 && g_map2d.matrix[y][wdh] != ' ')
	{
		if (y >= lgh && y < g_map2d.mtx_lgh && ver == 0)
			++y;
		else if (((y == g_map2d.mtx_lgh || y > lgh) && ver == 1) && lgh)
			y = lgh - 1;
		else if (y < lgh && (y - 1 >= 0))
			--y;
		else
			return (1);
		(g_map2d.matrix[y][wdh] == '1') ? ++ver : 0;
	}
	if (ver != 2)
		return (1);
	return (0);
}
