/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit2.c                                           :+:      :+:    :+:   */
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

void				set_init_sprit(t_unity_sprit *spr, int y, int x)
{
	spr->mtxy = y;
	spr->mtxx = x;
	spr->mapy = (y + 1) * MAP_SIZE - (MAP_SIZE / 2);
	spr->mapx = (x + 1) * MAP_SIZE - (MAP_SIZE / 2);
}

void				set_visibles_sprit(t_unity_sprit *spr)
{
	++g_cnt_sprit.visibles;
	spr->visible = 1;
	spr->distanc2d = sqrt(pow(spr->mapy - (g_play2d.posy + g_play2d.wdh / 2),
				2) + pow(spr->mapx - (g_play2d.posx + g_play2d.wdh / 2), 2));
	spr->distanc2d *= cos(fabs(spr->ang) * PI / 180);
	spr->hgt = MAP_SIZE * ((g_window.wdh / 2) / (tan(VIEW_ANG * PI / 180) / 2))
		/ spr->distanc2d;
	spr->wdh = spr->hgt;
	spr->mid = (tan((spr->ang * -1) * PI / 180)) * ((g_window.wdh / 2) /
			(tan(VIEW_ANG * PI / 180 / 2))) + (g_window.wdh / 2);
	spr->startx = spr->mid - (spr->wdh / 2);
	spr->endx = spr->mid + (spr->wdh / 2);
	spr->ratio = (float)WDH_TEXT / spr->wdh;
}
