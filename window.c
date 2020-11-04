/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_window	g_window;
extern t_map3d g_map3d;

int		init_window(void)
{
	int	n[3];

	n[0] = -1;
	if (!(g_window.mlx = mlx_init()))
		return (set_error(7, 16, 11));
	while (g_map3d.resolut[++n[0]])
	{
		if ((ft_isdigit(g_map3d.resolut[n[0]])))
		{
			if (!g_window.wdh)
				g_window.wdh = (ft_atoi(&g_map3d.resolut[n[0]]));
			else
				g_window.lgh = (ft_atoi(&g_map3d.resolut[n[0]]));
			while ((ft_isdigit(g_map3d.resolut[n[0] + 1])))
				++n[0];
		}
	}
	mlx_get_screen_size(g_window.mlx, &n[1], &n[2]);
	(g_window.wdh > n[1]) ? g_window.wdh = n[1] : 0;
	(g_window.lgh > n[2]) ? g_window.lgh = n[2] - 50 : 0;
	return (0);
}
