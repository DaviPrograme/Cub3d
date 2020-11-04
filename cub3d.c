/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map2d	g_map2d;
t_map3d g_map3d;
t_error g_error;
t_window g_window;
t_play2d g_play2d;
t_mmpi g_mmpi;
t_texture g_texture;
t_center_sprit g_cnt_sprit;
t_unity_sprit *g_uny_sprit;
t_unity_sprit **g_visibles;
t_save_bmp g_bmp;

void	cub3d(char *pnt)
{
	((fill_maps(pnt))) ? error() : 0;
	((init_window())) ? error() : 0;
	((init_texture())) ? error() : 0;
	config_init_minimap();
	(events_mlx("CUB3D")) ? error() : 0;
	memory_free();
}
