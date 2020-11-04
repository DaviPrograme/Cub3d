/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
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

void		raycasting(void)
{
	double	x[2];
	double	y[2];
	double	cont;
	int		num;

	num = -1;
	cont = (((double)VIEW_ANG / 2) + ((double)VIEW_ANG / g_window.wdh)) * -1;
	x[0] = g_play2d.posx + (g_play2d.wdh / 2);
	y[0] = g_play2d.posy + (g_play2d.wdh / 2);
	while ((cont += (double)VIEW_ANG / g_window.wdh) <= ((double)VIEW_ANG / 2))
	{
		x[1] = x[0];
		y[1] = y[0];
		while (1)
		{
			x[1] += 1 * cos((g_play2d.degres + cont) * (double)(PI / 180));
			y[1] += 1 * sin((g_play2d.degres + cont) * (double)(PI / 180));
			if ((ver_point2d(y, x)))
				break ;
		}
		(++num < g_window.wdh) ? project3d(x, y, cont, num) : 0;
	}
}

int			ver_point2d(double *y, double *x)
{
	int		very;
	int		verx;
	int		width;
	int		height;

	width = g_map2d.map_wdh / g_map2d.mtx_wdh;
	height = round(((double)g_map2d.map_lgh / (g_map2d.mtx_lgh + 1)));
	very = (y[1] - g_map2d.mapy) / height;
	verx = (x[1] - g_map2d.mapx) / width;
	if (g_map2d.matrix[very][verx] == '1' || g_map2d.matrix[very][verx] == ' ')
		return (1);
	return (0);
}
