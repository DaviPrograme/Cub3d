/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_maps.c                                       :+:      :+:    :+:   */
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

int			valid_maps(void)
{
	int		x;

	x = 0;
	(g_map3d.resolut == NULL) ? ++x : 0;
	(g_map3d.txt_no == NULL) ? ++x : 0;
	(g_map3d.txt_so == NULL) ? ++x : 0;
	(g_map3d.txt_we == NULL) ? ++x : 0;
	(g_map3d.txt_ea == NULL) ? ++x : 0;
	(g_map3d.txt_sie == NULL) ? ++x : 0;
	(g_map3d.rgb_flr == NULL) ? ++x : 0;
	(g_map3d.rgb_clg == NULL) ? ++x : 0;
	if (x > 0)
		return (set_error(5, 12, 6));
	if ((valid_map3d()))
		return (1);
	if ((valid_map2d()))
		return (1);
	return (0);
}

int			valid_map3d(void)
{
	char	*ptr;

	ptr = g_map3d.resolut;
	if (ptr[1] != ' ' || (valid_content_map3d(&ptr[2])))
		return (set_error(5, 13, 2));
	ptr = g_map3d.txt_no;
	if (ptr[1] != 'O' || ptr[2] != ' ')
		return (set_error(5, 13, 2));
	if ((valid_content_map3d(&ptr[3])))
		return (set_error(5, 13, 2));
	ptr = g_map3d.txt_so;
	if (ptr[2] != ' ' || (valid_content_map3d(&ptr[3])))
		return (set_error(5, 13, 2));
	ptr = g_map3d.txt_we;
	if (ptr[1] != 'E' || ptr[2] != ' ')
		return (set_error(5, 13, 2));
	if ((valid_content_map3d(&ptr[3])))
		return (set_error(5, 13, 2));
	if ((valid_resolut(g_map3d.resolut)))
		return (set_error(5, 13, 10));
	if ((valid__map3d_part2()))
		return (set_error(5, 13, 2));
	return (0);
}

int			valid__map3d_part2(void)
{
	char	*ptr;

	ptr = g_map3d.txt_ea;
	if (ptr[1] != 'A' || ptr[2] != ' ')
		return (set_error(5, 13, 2));
	if ((valid_content_map3d(&ptr[3])))
		return (set_error(5, 13, 2));
	ptr = g_map3d.txt_sie;
	if (ptr[1] != ' ' || (valid_content_map3d(&ptr[2])))
		return (set_error(5, 13, 2));
	ptr = g_map3d.rgb_flr;
	if (ptr[1] != ' ' || (valid_content_map3d(&ptr[2])))
		return (set_error(5, 13, 2));
	ptr = g_map3d.rgb_clg;
	if (ptr[1] != ' ' || (valid_content_map3d(&ptr[2])))
		return (set_error(5, 13, 2));
	if ((valid_rgb(g_map3d.rgb_flr)) || (valid_rgb(g_map3d.rgb_clg)))
		return (set_error(5, 13, 9));
	g_map3d.color_clg = convert_rgb(g_map3d.rgb_clg);
	g_map3d.color_flr = convert_rgb(g_map3d.rgb_flr);
	return (0);
}

int			valid_content_map3d(char *ptr)
{
	int		cont;

	cont = -1;
	while (ptr[++cont] != '\0')
	{
		if (ptr[cont] != ' ')
			return (0);
	}
	return (1);
}

int			valid_rgb(char *ptr)
{
	int		cont;
	int		x;

	cont = 0;
	x = 1;
	while (ptr[++x])
	{
		if ((ft_isdigit(ptr[x])))
		{
			if ((ft_atoi(&ptr[x])) <= 255)
				++cont;
			else
				cont += 4;
			while ((ft_isdigit(ptr[x + 1])))
				++x;
		}
		else if (ptr[x] != ' ' && ptr[x] != ',')
			cont += 4;
	}
	if (cont != 3)
		return (1);
	return (0);
}
