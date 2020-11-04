/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project3d_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_map2d g_map2d;
extern t_texture g_texture;

char	*point_supleft(int x, int y, int width, int height)
{
	int	cont;

	cont = 0;
	(g_map2d.matrix[y / height][(x + width - 1) / width] == '1') ? ++cont : 0;
	(g_map2d.matrix[y / height][(x - width + 1) / width] == '1') ? ++cont : 0;
	if (cont == 2)
		return (g_texture.so);
	cont = 0;
	(g_map2d.matrix[(y + height - 1) / height][x / width] == '1') ? ++cont : 0;
	(g_map2d.matrix[(y - height + 1) / height][x / width] == '1') ? ++cont : 0;
	if (cont == 2)
		return (g_texture.ea);
	return (g_texture.so);
}

char	*point_supright(int x, int y, int width, int height)
{
	int cont;

	cont = 0;
	(g_map2d.matrix[y / height][(x + width - 1) / width] == '1') ? ++cont : 0;
	(g_map2d.matrix[y / height][(x - width + 1) / width] == '1') ? ++cont : 0;
	if (cont == 2)
		return (g_texture.so);
	cont = 0;
	(g_map2d.matrix[(y + height - 1) / height][x / width] == '1') ? ++cont : 0;
	(g_map2d.matrix[(y - height + 1) / height][x / width] == '1') ? ++cont : 0;
	if (cont == 2)
		return (g_texture.we);
	return (g_texture.so);
}

char	*point_lessleft(int x, int y, int width, int height)
{
	int cont;

	cont = 0;
	(g_map2d.matrix[y / height][(x + width - 1) / width] == '1') ? ++cont : 0;
	(g_map2d.matrix[y / height][(x - width + 1) / width] == '1') ? ++cont : 0;
	if (cont == 2)
		return (g_texture.no);
	cont = 0;
	(g_map2d.matrix[(y + height - 1) / height][x / width] == '1') ? ++cont : 0;
	(g_map2d.matrix[(y - height + 1) / height][x / width] == '1') ? ++cont : 0;
	if (cont == 2)
		return (g_texture.ea);
	return (g_texture.no);
}

char	*point_lessright(int x, int y, int width, int height)
{
	int cont;

	cont = 0;
	(g_map2d.matrix[y / height][(x + width - 1) / width] == '1') ? ++cont : 0;
	(g_map2d.matrix[y / height][(x - width + 1) / width] == '1') ? ++cont : 0;
	if (cont == 2)
		return (g_texture.no);
	cont = 0;
	(g_map2d.matrix[(y + height - 1) / height][x / width] == '1') ? ++cont : 0;
	(g_map2d.matrix[(y - height + 1) / height][x / width] == '1') ? ++cont : 0;
	if (cont == 2)
		return (g_texture.we);
	return (g_texture.no);
}
