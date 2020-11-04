/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_map2d g_map2d;
extern t_window g_window;
extern t_play2d g_play2d;

int			init_player2d(char let, int posy, int posx)
{
	int		width;
	int		height;

	if (g_play2d.ini_ply)
		return (0);
	(let == 'N') ? g_play2d.ini_ply = let : 0;
	(let == 'S') ? g_play2d.ini_ply = let : 0;
	(let == 'E') ? g_play2d.ini_ply = let : 0;
	(let == 'W') ? g_play2d.ini_ply = let : 0;
	if (!g_play2d.ini_ply)
		return (0);
	width = g_map2d.map_wdh / g_map2d.mtx_wdh;
	height = round(((double)g_map2d.map_lgh / (g_map2d.mtx_lgh + 1)));
	g_play2d.wdh = (double)(g_map2d.map_wdh / g_map2d.mtx_wdh) * 0.30;
	g_play2d.posy = (height * posy + g_map2d.mapy) +
	(height / 2) + (g_play2d.wdh / 2);
	g_play2d.posx = (width * posx + g_map2d.mapx) +
	(width / 2) - (g_play2d.wdh / 2);
	(let == 'N') ? g_play2d.degres = 270 : 0;
	(let == 'S') ? g_play2d.degres = 90 : 0;
	(let == 'E') ? g_play2d.degres = 0 : 0;
	(let == 'W') ? g_play2d.degres = 180 : 0;
	return (1);
}

int			ver_posplay2d(void)
{
	int		x[2];
	int		y[2];
	int		width;
	int		height;

	x[0] = g_play2d.posx;
	y[0] = g_play2d.posy;
	width = g_map2d.map_wdh / g_map2d.mtx_wdh;
	height = round(((double)g_map2d.map_lgh / (g_map2d.mtx_lgh + 1)));
	while (++x[0] <= g_play2d.posx + g_play2d.wdh + 1)
	{
		y[1] = floor((y[0] - g_map2d.mapy) / height);
		x[1] = floor((x[0] - g_map2d.mapx - 1) / width);
		if (g_map2d.matrix[y[1]][x[1]] == '1')
			return (1);
	}
	while (++y[0] <= g_play2d.posy + g_play2d.wdh + 1)
	{
		y[1] = floor((y[0] - g_map2d.mapy - 1) / height);
		if (g_map2d.matrix[y[1]][x[1]] == '1')
			return (1);
	}
	return ((posplay2d_part2(y, x, width, height)));
}

int			posplay2d_part2(int *y, int *x, int width, int height)
{
	while (--x[0] >= g_play2d.posx)
	{
		x[1] = floor((x[0] - g_map2d.mapx) / width);
		if (g_map2d.matrix[y[1]][x[1]] == '1')
			return (1);
	}
	while (--y[0] > g_play2d.posy)
	{
		y[1] = floor((y[0] - g_map2d.mapy) / height);
		if (g_map2d.matrix[y[1]][x[1]] == '1')
			return (1);
	}
	return (0);
}
