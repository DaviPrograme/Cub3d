/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_window	g_window;
extern t_play2d g_play2d;
extern t_map2d g_map2d;
extern t_save_bmp g_bmp;

int			events_mlx(char *pt)
{
	if (!g_bmp.status)
		g_window.win = mlx_new_window(g_window.mlx, g_window.wdh,
				g_window.lgh, pt);
	if (!g_bmp.status && g_window.win == NULL)
		return (set_error(9, 18, 11));
	mini_map2d();
	mlx_hook(g_window.win, 2, 1L << 0, key_pressed, NULL);
	mlx_hook(g_window.win, 9, 1L << 21, mini_map2d, NULL);
	mlx_hook(g_window.win, 3, 1L << 1, esc_close, NULL);
	mlx_hook(g_window.win, 17, 1L << 17, x_close, NULL);
	mlx_loop(g_window.mlx);
	return (0);
}

int			key_pressed(int keycode)
{
	double	vars[2];
	int		ret;

	vars[0] = g_play2d.posy;
	vars[1] = g_play2d.posx;
	ret = 0;
	if (keycode == 'w' || keycode == 's')
	{
		ret = (keycode == 'w') ? g_play2d.degres : g_play2d.degres + 180;
		g_play2d.posx += MOVSPED * cos(ret * (double)(PI / 180));
		g_play2d.posy += MOVSPED * sin(ret * (double)(PI / 180));
		ret = ver_posplay2d();
		(ret) ? g_play2d.posy = vars[0] : 0;
		(ret) ? g_play2d.posx = vars[1] : 0;
		ret = (!ret) ? 1 : 0;
	}
	else
		ret = key_pressed2(keycode, vars);
	(ret) ? mini_map2d() : 0;
	return (ret);
}

int			key_pressed2(int keycode, double *vars)
{
	int		add;

	add = 0;
	if (keycode == 'a' || keycode == 'd')
	{
		add = (keycode == 'a') ? g_play2d.degres - 90 : g_play2d.degres + 90;
		g_play2d.posx += MOVSPED * cos(add * (double)(PI / 180));
		g_play2d.posy += MOVSPED * sin(add * (double)(PI / 180));
		add = ver_posplay2d();
		(add) ? g_play2d.posy = vars[0] : 0;
		(add) ? g_play2d.posx = vars[1] : 0;
		add = (!add) ? 1 : 0;
	}
	else if (keycode == 65363 || keycode == 65361)
	{
		g_play2d.degres += (keycode == 65361) ? -ROTSPED : ROTSPED;
		(g_play2d.degres >= 360) ? g_play2d.degres -= 360 : 0;
		(g_play2d.degres < 0) ? g_play2d.degres += 360 : 0;
		add = 1;
	}
	return (add);
}

int			esc_close(int keycode)
{
	if (keycode == 65307)
	{
		memory_free();
		exit(0);
	}
	return (0);
}

int			x_close(void)
{
	memory_free();
	exit(0);
	return (0);
}
