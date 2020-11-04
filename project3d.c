/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_map2d g_map2d;
extern t_map3d g_map3d;
extern t_window g_window;
extern t_play2d g_play2d;
extern t_texture g_texture;
extern t_center_sprit g_cnt_sprit;
extern t_unity_sprit *g_uny_sprit;
extern t_unity_sprit **g_visibles;

void		project3d(double *x, double *y, float n, int num)
{
	float	distanc2d;
	float	distanc3d;
	int		height2d;
	int		height3d;
	int		cont;

	cont = -1;
	height2d = g_map2d.map_lgh / (g_map2d.mtx_lgh + 1);
	distanc2d = sqrt((pow((y[1] - y[0]), 2)) + (pow((x[1] - x[0]), 2)));
	distanc2d *= cos(n * PI / 180);
	(distanc2d < 0) ? distanc2d *= -1 : 0;
	distanc3d = (g_window.wdh / 2) / (tan((VIEW_ANG * PI / 180) / 2));
	height3d = (height2d / distanc2d) * distanc3d;
	wall_3d(height3d, num, (int)x[1], (int)y[1]);
	if (g_cnt_sprit.nsprits > 0)
	{
		while (g_visibles[++cont] != NULL)
		{
			if (g_visibles[cont]->distanc2d < distanc2d &&
			num >= g_visibles[cont]->startx && num <= g_visibles[cont]->endx)
				sprit_3d(num, g_visibles[cont]);
		}
	}
	if (++num >= g_window.wdh)
		num = 0;
}

void		wall_3d(int height, int num, int x, int y)
{
	int		starty;
	int		cont;
	char	*clr;
	int		yyy;
	int		userx;

	cont = 0;
	starty = ((g_window.lgh - height) / 2);
	(starty < 0) ? starty = 0 : 0;
	clr = texture_wall(x - g_map2d.mapx, y - g_map2d.mapy);
	userx = (x % MAP_SIZE == 0 || (x + 1) % MAP_SIZE == 0) ? y : x;
	while (++cont < g_window.lgh)
	{
		yyy = cont + (height / 2) - (g_window.lgh / 2);
		(yyy < 0) ? yyy = 0 : 0;
		if (cont < starty)
			my_mlx_pixel_image(g_map2d.img, num, cont, g_map3d.color_clg);
		else if (cont >= starty && cont <= starty + height)
			my_mlx_pixel_image(g_map2d.img, num, cont, get_color(clr,
						yyy * ((float)WDH_TEXT / height),
						(userx % MAP_SIZE) * g_texture.qtt_wdh));
		else
			my_mlx_pixel_image(g_map2d.img, num, cont, g_map3d.color_flr);
	}
}

char		*texture_wall(int x, int y)
{
	int		width;
	int		height;
	char	*textu;
	int		ver;

	ver = 0;
	width = g_map2d.map_wdh / g_map2d.mtx_wdh;
	height = round(((double)g_map2d.map_lgh / (g_map2d.mtx_lgh + 1)));
	textu = 0;
	(y % height == 0 && (textu = g_texture.so)) ? ver += 1 : 0;
	((y + 1) % height == 0 && (textu = g_texture.no)) ? ver += 1 : 0;
	(x % width == 0 && (textu = g_texture.ea)) ? ver += 1 : 0;
	((x + 1) % width == 0 && (textu = g_texture.we)) ? ver += 1 : 0;
	(ver > 1) ? textu = div_wall(x, y, width, height) : 0;
	if (textu == g_texture.no &&
			g_map2d.matrix[y / height + 1][x / width] == ' ')
		textu = g_texture.so;
	else if (textu == g_texture.so &&
			g_map2d.matrix[y / height - 1][x / width] == ' ')
		textu = g_texture.no;
	return (textu);
}

char		*div_wall(int x, int y, int width, int height)
{
	if (y % height == 0 && x % width == 0)
		return ((point_supleft(x, y, width, height)));
	else if (y % height == 0 && (x + 1) % width == 0)
		return ((point_supright(x, y, width, height)));
	else if ((y + 1) % height == 0 && x % width == 0)
		return ((point_lessleft(x, y, width, height)));
	else if ((y + 1) % height == 0 && (x + 1) % width == 0)
		return ((point_lessright(x, y, width, height)));
	return (NULL);
}
