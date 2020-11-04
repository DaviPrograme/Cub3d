/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_window	g_window;
extern t_map3d	g_map3d;
extern t_texture g_texture;
extern t_center_sprit g_cnt_sprit;

char			*image_texture(char *ptr, int x)
{
	void		*ret;
	char		*ptr2;
	char		*img;

	x = 2;
	ptr2 = ptr;
	while (ptr2[x] == ' ')
		++x;
	ret = mlx_xpm_file_to_image(g_window.mlx, &ptr2[x], &x,
			&g_texture.size_line);
	if (x != WDH_TEXT || g_texture.size_line != WDH_TEXT || !ret)
	{
		free(ret);
		return (NULL);
	}
	ptr2 = mlx_get_data_addr(ret, &g_texture.bpp,
			&g_texture.size_line, &x);
	(ptr2) ? img = (char *)ft_calloc(WDH_TEXT * g_texture.size_line +
			(WDH_TEXT / 2 * 10), sizeof(char)) : 0;
	x = -1;
	while ((img != NULL && ptr2 != NULL) && ++x < WDH_TEXT *
			g_texture.size_line + (WDH_TEXT / 2 * 10))
		img[x] = ptr2[x];
	mlx_destroy_image(g_window.mlx, ret);
	return (img);
}

int				init_texture(void)
{
	if ((g_texture.so = image_texture(g_map3d.txt_no, 0)) == NULL)
		return (set_error(8, 17, 13));
	if ((g_texture.no = image_texture(g_map3d.txt_so, 0)) == NULL)
		return (set_error(8, 17, 13));
	if ((g_texture.ea = image_texture(g_map3d.txt_we, 0)) == NULL)
		return (set_error(8, 17, 13));
	if ((g_texture.we = image_texture(g_map3d.txt_ea, 0)) == NULL)
		return (set_error(8, 17, 13));
	if ((g_cnt_sprit.txt_sprit = image_texture(g_map3d.txt_sie, 0)) == NULL)
		return (set_error(8, 17, 13));
	g_texture.qtt_wdh = WDH_TEXT / MAP_SIZE;
	return (0);
}

unsigned int	get_color(char *texture, int y, int x)
{
	char		*ptr;

	ptr = texture;
	ptr += y * g_texture.size_line + x * (g_texture.bpp / 8);
	return (*(unsigned int *)ptr);
}
