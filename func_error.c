/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		func_error(int func)
{
	int	rt;

	rt = 0;
	(func == 1) ? rt = ft_putstr_fd("\nfunc: cub3d", 2) : 0;
	(func == 2) ? rt = ft_putstr_fd("\nfunc: fill_maps", 2) : 0;
	(func == 3) ? rt = ft_putstr_fd("\nfunc: string_map2d", 2) : 0;
	(func == 4) ? rt = ft_putstr_fd("\nfunc: fill_map2d", 2) : 0;
	(func == 5) ? rt = ft_putstr_fd("\nfunc: build_matrix", 2) : 0;
	(func == 6) ? rt = ft_putstr_fd("\nfunc: filter_maps", 2) : 0;
	(func == 7) ? rt = ft_putstr_fd("\nfunc: fill_map3d", 2) : 0;
	(func == 8) ? rt = ft_putstr_fd("\nfunc: null_ptr_map3d", 2) : 0;
	(func == 9) ? rt = ft_putstr_fd("\nfunc: error", 2) : 0;
	(func == 10) ? rt = ft_putstr_fd("\nfunc: file_error", 2) : 0;
	(func == 11) ? rt = ft_putstr_fd("\nfunc: main", 2) : 0;
	(func == 12) ? rt = ft_putstr_fd("\nfunc: valid_maps", 2) : 0;
	(func == 13) ? rt = ft_putstr_fd("\nfunc: valid_map3d", 2) : 0;
	(func == 14) ? rt = ft_putstr_fd("\nfunc: let_matrix_map2d", 2) : 0;
	(func == 15) ? rt = ft_putstr_fd("\nfunc: verifica_map2d", 2) : 0;
	(func == 16) ? rt = ft_putstr_fd("\nfunc: init_window", 2) : 0;
	(func == 17) ? rt = ft_putstr_fd("\nfunc: init_texture", 2) : 0;
	(func == 18) ? rt = ft_putstr_fd("\nfunc: events_mlx", 2) : 0;
	(func == 19) ? rt = ft_putstr_fd("\nfunc: build_map2d", 2) : 0;
	(func == 20) ? rt = ft_putstr_fd("\nfunc: save_bmp_file", 2) : 0;
}
