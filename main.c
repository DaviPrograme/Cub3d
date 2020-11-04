/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
extern t_save_bmp g_bmp;

int		main(int argc, char **argv)
{
	if (argc == 1 || argc > 3)
	{
		set_error(4, 11, 5);
		error();
	}
	if ((ver_extension_file(&argv[1][0], ".cub")))
		error();
	if (argc == 3 && (ver_flag_save(&argv[2][0], "--save")))
		error();
	cub3d(&argv[1][0]);
	return (0);
}

int		ver_extension_file(char *ptr, char *ext)
{
	int	cont;
	int	ver;

	cont = ft_strlen(ptr);
	ver = 0;
	ver += (ptr[cont - 1] == ext[3]) ? 1 : 0;
	ver += (ptr[cont - 2] == ext[2]) ? 1 : 0;
	ver += (ptr[cont - 3] == ext[1]) ? 1 : 0;
	ver += (ptr[cont - 4] == ext[0]) ? 1 : 0;
	if (ver != 4)
		return (set_error(4, 11, 8));
	return (0);
}

int		ver_flag_save(char *ptr, char *ext)
{
	int	cont;
	int	ver;

	cont = ft_strlen(ptr);
	if (cont != 6)
		return (set_error(4, 11, 15));
	ver = 0;
	ver += (ptr[cont - 1] == ext[5]) ? 1 : 0;
	ver += (ptr[cont - 2] == ext[4]) ? 1 : 0;
	ver += (ptr[cont - 3] == ext[3]) ? 1 : 0;
	ver += (ptr[cont - 4] == ext[2]) ? 1 : 0;
	ver += (ptr[cont - 5] == ext[1]) ? 1 : 0;
	ver += (ptr[cont - 6] == ext[0]) ? 1 : 0;
	if (ver != 6)
		return (set_error(4, 11, 15));
	g_bmp.status = 1;
	return (0);
}
