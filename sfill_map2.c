/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfill_map2.c                                       :+:      :+:    :+:   */
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

int			build_matrix2d(void)
{
	int		line;
	int		cont;
	int		cont2;
	char	*ptr;
	int		num;

	line = 0;
	cont = 0;
	num = g_map2d.mtx_lgh;
	if (!(g_map2d.matrix = (char **)ft_calloc(sizeof(char *), num + 5)))
		return (set_error(3, 5, 1));
	while (g_map2d.string[cont])
	{
		cont2 = 0;
		if (!(ptr = (char *)ft_calloc(sizeof(char), g_map2d.mtx_wdh + 10)))
			return (set_error(3, 5, 1));
		while (g_map2d.string[cont] != '\n' && g_map2d.string[cont] != '\0')
			ptr[cont2++] = g_map2d.string[cont++];
		while (cont2 < g_map2d.mtx_wdh)
			ptr[cont2++] = ' ';
		g_map2d.matrix[line++] = ptr;
		(g_map2d.string[cont] == '\n') ? ++cont : 0;
	}
	return (0);
}

int			string_map2d(char *ptr)
{
	char	*temp;
	char	*temp2;

	if (ptr == NULL)
		return (0);
	if (g_map2d.string == NULL)
		g_map2d.string = ft_substr(ptr, 0, ft_strlen(ptr));
	else
	{
		if (!(temp = ft_strjoin(g_map2d.string, "\n")))
			return (set_error(3, 3, 1));
		temp2 = g_map2d.string;
		g_map2d.string = temp;
		free(temp2);
		if (!(temp = ft_strjoin(g_map2d.string, ptr)))
			return (set_error(3, 3, 1));
		temp2 = g_map2d.string;
		g_map2d.string = temp;
		free(temp2);
	}
	return (0);
}

int			fill__map3d(char *ptr)
{
	size_t	cont;

	if ((null_ptr_map3d(ptr)) != 1)
		return (set_error(3, 7, 2));
	cont = ft_strlen(ptr);
	if (ptr[0] == 'S' && ptr[1] == 'O')
		g_map3d.txt_so = ft_substr(ptr, 0, cont);
	else if (ptr[0] == 'S')
		g_map3d.txt_sie = ft_substr(ptr, 0, cont);
	else
	{
		(ptr[0] == 'R') ? g_map3d.resolut = ft_substr(ptr, 0, cont) : 0;
		(ptr[0] == 'N') ? g_map3d.txt_no = ft_substr(ptr, 0, cont) : 0;
		(ptr[0] == 'W') ? g_map3d.txt_we = ft_substr(ptr, 0, cont) : 0;
		(ptr[0] == 'E') ? g_map3d.txt_ea = ft_substr(ptr, 0, cont) : 0;
		(ptr[0] == 'F') ? g_map3d.rgb_flr = ft_substr(ptr, 0, cont) : 0;
		(ptr[0] == 'C') ? g_map3d.rgb_clg = ft_substr(ptr, 0, cont) : 0;
	}
	return (0);
}

int			null_ptr_map3d(char *ptr)
{
	int		ver;

	ver = 0;
	if (ptr[0] == 'S' && ptr[1] == 'O' && g_map3d.txt_so == NULL)
		++ver;
	else if (ptr[0] == 'S' && ptr[1] == ' ' && g_map3d.txt_sie == NULL)
		++ver;
	else
	{
		ver += (ptr[0] == 'R' && g_map3d.resolut == NULL) ? 1 : 0;
		ver += (ptr[0] == 'N' && g_map3d.txt_no == NULL) ? 1 : 0;
		ver += (ptr[0] == 'W' && g_map3d.txt_we == NULL) ? 1 : 0;
		ver += (ptr[0] == 'E' && g_map3d.txt_ea == NULL) ? 1 : 0;
		ver += (ptr[0] == 'F' && g_map3d.rgb_flr == NULL) ? 1 : 0;
		ver += (ptr[0] == 'C' && g_map3d.rgb_clg == NULL) ? 1 : 0;
	}
	return (ver);
}

int			convert_rgb(char *ptr)
{
	int		x;
	int		cont;
	int		resul;

	x = -1;
	cont = 0;
	resul = 0;
	while (ptr[++x] && cont < 3)
	{
		if ((ft_isdigit(ptr[x])))
		{
			if (cont == 0)
				resul += (ft_atoi(&ptr[x])) * 256 * 256;
			else if (cont == 1)
				resul += (ft_atoi(&ptr[x])) * 256;
			else if (cont == 2)
				resul += (ft_atoi(&ptr[x]));
			++cont;
			while ((ft_isdigit(ptr[x + 1])))
				++x;
		}
	}
	return (resul);
}
