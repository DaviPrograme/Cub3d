/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfill_map.c                                        :+:      :+:    :+:   */
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

int					fill_maps(char *pnt)
{
	int				fd;
	int				ver;
	int				ver2;
	char			*ptr;
	int				cont2;

	fd = open(pnt, O_RDONLY);
	if (fd == -1)
		return (set_error(2, 2, 12));
	ver = 0;
	cont2 = 0;
	ver2 = 0;
	while (((ver = get_next_line(fd, &ptr)) >= 0) && cont2 == 0 && ver2 == 0)
	{
		ver2 = filter_maps(ptr);
		(ver == 0) ? cont2 = 1 : 0;
		free(ptr);
	}
	free(ptr);
	close(fd);
	(ver == -1) ? set_error(2, 2, 3) : 0;
	(!ver && ver2) ? ver = ver2 : 0;
	(!ver) ? ver = fill__map2d() : 0;
	(!ver) ? ver = valid_maps() : 0;
	return (ver);
}

int					filter_maps(char *ptr)
{
	static int		map;
	int				ver;
	int				cont;

	cont = -1;
	ver = 0;
	while (ptr[++cont] != '\0')
	{
		if (ft_isalpha(ptr[cont]) && map == 0)
		{
			ver = fill__map3d(&ptr[cont]);
			break ;
		}
		else if (ft_isdigit(ptr[cont]) || map == 1)
		{
			ver = string_map2d(ptr);
			map = 1;
			break ;
		}
	}
	return (ver);
}

int					fill__map2d(void)
{
	int				columns;
	int				cont;

	if (g_map2d.string == NULL)
		return (set_error(2, 4, 4));
	columns = 0;
	cont = -1;
	while (g_map2d.string[++cont] != '\0')
	{
		if (g_map2d.string[cont] == '\n')
		{
			(columns > g_map2d.mtx_wdh) ? g_map2d.mtx_wdh = columns : 0;
			g_map2d.mtx_lgh += 1;
			columns = 0;
			continue;
		}
		++columns;
	}
	return (build_matrix2d());
}

int					valid_resolut(char *ptr)
{
	int				cont;
	int				x;

	cont = 0;
	x = 1;
	while (ptr[++x])
	{
		if ((ft_isdigit(ptr[x])))
		{
			if ((ft_atoi(&ptr[x])) > 0)
				++cont;
			else
				cont += 4;
			while ((ft_isdigit(ptr[x + 1])))
				++x;
		}
		else if (ptr[x] != ' ')
			cont += 4;
	}
	if (cont != 2)
		return (1);
	return (0);
}
