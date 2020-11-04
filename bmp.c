/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_save_bmp g_bmp;
extern t_window g_window;

static void			little_endian_int(unsigned char *adr, unsigned int vl)
{
	adr[0] = (unsigned char)(vl);
	adr[1] = (unsigned char)(vl >> 8);
	adr[2] = (unsigned char)(vl >> 16);
	adr[3] = (unsigned char)(vl >> 24);
}

static int			store_color(int x, int y)
{
	unsigned int	color;
	unsigned char	addr_color[4];

	color = *(unsigned int *)(g_bmp.addr + g_window.wdh *
			(g_window.lgh - y - 1) * 4 + x * 4);
	little_endian_int(&addr_color[0], color);
	return (*(unsigned int*)(addr_color));
}

static void			bmp_header(int fd)
{
	unsigned char	file[54];
	int				filesize;

	ft_bzero(&file, 54);
	filesize = 54 + g_window.lgh * g_window.wdh * g_bmp.bpp / 8;
	file[0] = (unsigned char)('B');
	file[1] = (unsigned char)('M');
	little_endian_int(&file[2], filesize);
	file[10] = (unsigned char)(54);
	file[14] = (unsigned char)(40);
	little_endian_int(&file[18], g_window.wdh);
	little_endian_int(&file[22], g_window.lgh);
	file[26] = (unsigned char)(1);
	file[28] = (unsigned char)(32);
	write(fd, &file, 54);
}

int					save_bmp_file(void)
{
	int				fd;
	int				bmp[g_window.lgh][g_window.wdh];
	int				x;
	int				y;

	if ((fd = open("photo.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR |
					S_IRGRP | S_IROTH, 777)) < 0)
		return (set_error(11, 20, 14));
	bmp_header(fd);
	y = 0;
	while (y < g_window.lgh)
	{
		x = 0;
		while (x < g_window.wdh)
		{
			bmp[y][x] = store_color(x, y);
			write(fd, &bmp[y][x], 4);
			x++;
		}
		y++;
	}
	close(fd);
	return (0);
}
