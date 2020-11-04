/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_error(int file)
{
	(file == 1) ? ft_putstr_fd("\nfile: cub3d.c", 2) : 0;
	(file == 2) ? ft_putstr_fd("\nfile: sfill_map.c", 2) : 0;
	(file == 3) ? ft_putstr_fd("\nfile: sfill_map2.c", 2) : 0;
	(file == 4) ? ft_putstr_fd("\nfile: main.c", 2) : 0;
	(file == 5) ? ft_putstr_fd("\nfile: valid_maps.c", 2) : 0;
	(file == 6) ? ft_putstr_fd("\nfile: valid_maps2.c", 2) : 0;
	(file == 7) ? ft_putstr_fd("\nfile: window.c", 2) : 0;
	(file == 8) ? ft_putstr_fd("\nfile: texture.c", 2) : 0;
	(file == 9) ? ft_putstr_fd("\nfile: events.c", 2) : 0;
	(file == 10) ? ft_putstr_fd("\nfile: mapmage.c", 2) : 0;
	(file == 11) ? ft_putstr_fd("\nfile: bmp.c", 2) : 0;
}
