/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagem.c                                           :+:      :+:    :+:   */
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
extern t_mmpi g_mmpi;
extern t_texture g_texture;
extern t_center_sprit g_cnt_sprit;
extern t_save_bmp g_bmp;

void		my_mlx_pixel_image(void *img, int x, int y, int color)
{
	char			*dst;
	static int		bpp;
	static int		size_line;
	static int		endian;

	if (!g_mmpi.dst)
	{
		dst = mlx_get_data_addr(img, &bpp, &size_line, &endian);
		g_mmpi.dst = dst;
		g_bmp.addr = g_mmpi.dst;
		g_bmp.bpp = bpp;
		g_bmp.size_line = size_line;
		g_bmp.endian = endian;
	}
	else
		dst = g_mmpi.dst;
	dst += y * size_line + x * (bpp / 8);
	*(unsigned int*)dst = color;
}

void		build_map2d(void)
{
	int		x;
	int		cont;

	if (!g_map2d.img)
		g_map2d.img = mlx_new_image(g_window.mlx, g_window.wdh, g_window.lgh);
	cont = -1;
	while (++cont <= g_map2d.mtx_lgh && !g_cnt_sprit.init)
	{
		x = -1;
		while (++x < g_map2d.mtx_wdh)
		{
			init_player2d(g_map2d.matrix[cont][x], cont, x);
			if (g_map2d.matrix[cont][x] == '2')
				++g_cnt_sprit.nsprits;
		}
	}
	(!g_cnt_sprit.init) ? init_sprit() : 0;
	visibles_sprits();
	raycasting();
	if (g_bmp.status)
	{
		(save_bmp_file()) ? error() : 0;
		(!(memory_free())) ? exit(0) : 0;
	}
	mlx_put_image_to_window(g_window.mlx, g_window.win, g_map2d.img, 0, 0);
}

int			mini_map2d(void)
{
	build_map2d();
	return (0);
}

void		config_init_minimap(void)
{
	g_map2d.map_wdh = MAP_SIZE * g_map2d.mtx_wdh;
	g_map2d.map_lgh = MAP_SIZE * (g_map2d.mtx_lgh + 1);
	g_map2d.mapy = 0;
	g_map2d.mapx = 0;
}
