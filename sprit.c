/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_center_sprit g_cnt_sprit;
extern t_unity_sprit *g_uny_sprit;
extern t_unity_sprit **g_visibles;
extern t_map2d g_map2d;
extern t_play2d g_play2d;
extern t_window g_window;

void				init_sprit(void)
{
	int				x;
	int				y;
	int				cont;

	y = -1;
	cont = -1;
	if (!g_uny_sprit && g_cnt_sprit.nsprits > 0)
	{
		if (!(g_uny_sprit = (t_unity_sprit *)ft_calloc(g_cnt_sprit.nsprits + 1,
						sizeof(t_unity_sprit))))
			set_error(10, 19, 1);
		if (!(g_visibles = (t_unity_sprit **)ft_calloc(g_cnt_sprit.nsprits + 1,
						sizeof(t_unity_sprit *))))
			set_error(10, 19, 1);
	}
	while (++y <= g_map2d.mtx_lgh && cont + 1 < g_cnt_sprit.nsprits)
	{
		x = -1;
		while (++x < g_map2d.mtx_wdh && cont < g_cnt_sprit.nsprits)
		{
			if (g_map2d.matrix[y][x] == '2')
				set_init_sprit(&g_uny_sprit[++cont], y, x);
		}
	}
	g_cnt_sprit.init = 1;
}

void				visibles_sprits(void)
{
	int				i;

	i = -1;
	g_cnt_sprit.visibles = 0;
	while (++i < g_cnt_sprit.nsprits)
	{
		g_uny_sprit[i].ang = atan2(g_uny_sprit[i].mapy - (g_play2d.posy +
					g_play2d.wdh / 2), g_uny_sprit[i].mapx - (g_play2d.posx +
					g_play2d.wdh / 2)) * 180 / PI;
		g_uny_sprit[i].ang = g_play2d.degres - g_uny_sprit[i].ang;
		if (g_uny_sprit[i].ang > 180)
			g_uny_sprit[i].ang -= 360;
		else if (g_uny_sprit[i].ang < -180)
			g_uny_sprit[i].ang += 360;
		if ((fabs(g_uny_sprit[i].ang)) <= (VIEW_ANG / 2))
			set_visibles_sprit(&g_uny_sprit[i]);
		else
			g_uny_sprit[i].visible = 0;
	}
	insert_sprits_visibles();
}

void				insert_sprits_visibles(void)
{
	int				i;
	int				j;
	int				cont;

	i = -1;
	j = -1;
	cont = 0;
	while (++i < g_cnt_sprit.nsprits)
		g_visibles[i] = NULL;
	i = -1;
	while (++j < g_cnt_sprit.nsprits)
	{
		if (g_uny_sprit[j].visible == 1 && (++cont))
			g_visibles[++i] = &g_uny_sprit[j];
	}
	if (cont > 0)
		bubblesort_sprits_visibles(cont);
}

void				bubblesort_sprits_visibles(int cont)
{
	int				i;
	int				j;
	t_unity_sprit	*aux;

	i = -1;
	while (++i < cont)
	{
		j = -1;
		while (++j < cont - 1)
		{
			if (g_visibles[j]->distanc2d < g_visibles[j + 1]->distanc2d)
			{
				aux = g_visibles[j];
				g_visibles[j] = g_visibles[j + 1];
				g_visibles[j + 1] = aux;
			}
		}
	}
}

void				sprit_3d(int num, t_unity_sprit *spr)
{
	int				starty;
	int				cont;
	unsigned int	clr;

	starty = ((g_window.lgh - spr->hgt) / 2) + spr->hgt * 0.25;
	(starty < 0) ? starty = 0 : 0;
	cont = starty;
	while (++cont <= starty + spr->hgt && cont < g_window.lgh)
	{
		if (!(clr = get_color(g_cnt_sprit.txt_sprit, (cont - starty)
						* spr->ratio, (num - spr->startx) * spr->ratio)))
			continue;
		my_mlx_pixel_image(g_map2d.img, num, cont, clr);
	}
}
