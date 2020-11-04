/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
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
extern t_window	g_window;
extern t_mmpi g_mmpi;
extern t_texture g_texture;
extern t_center_sprit g_cnt_sprit;
extern t_save_bmp g_bmp;
extern t_unity_sprit *g_uny_sprit;
extern t_unity_sprit **g_visibles;

int		memory_free(void)
{
	free_gmap23ds();
	(g_map2d.img) ? mlx_destroy_image(g_window.mlx, g_map2d.img) : 0;
	return (0);
}

void	free_gmap23ds(void)
{
	int	num;

	num = -1;
	(g_map3d.resolut != NULL) ? free(g_map3d.resolut) : 0;
	(g_map3d.txt_no != NULL) ? free(g_map3d.txt_no) : 0;
	(g_map3d.txt_so != NULL) ? free(g_map3d.txt_so) : 0;
	(g_map3d.txt_we != NULL) ? free(g_map3d.txt_we) : 0;
	(g_map3d.txt_ea != NULL) ? free(g_map3d.txt_ea) : 0;
	(g_map3d.rgb_flr != NULL) ? free(g_map3d.rgb_flr) : 0;
	(g_map3d.rgb_clg != NULL) ? free(g_map3d.rgb_clg) : 0;
	while (g_map2d.matrix && ++num < g_map2d.mtx_lgh + 1)
		free(&g_map2d.matrix[num][0]);
	(g_map2d.matrix != NULL) ? free(g_map2d.matrix) : 0;
	(g_map2d.string != NULL) ? free(g_map2d.string) : 0;
	(g_uny_sprit != NULL) ? free(g_uny_sprit) : 0;
	(g_visibles != NULL) ? free(g_visibles) : 0;
	(g_texture.no != NULL) ? free(g_texture.no) : 0;
	(g_texture.so != NULL) ? free(g_texture.so) : 0;
	(g_texture.we != NULL) ? free(g_texture.we) : 0;
	(g_texture.ea != NULL) ? free(g_texture.ea) : 0;
	(g_cnt_sprit.txt_sprit != NULL) ? free(g_cnt_sprit.txt_sprit) : 0;
}
