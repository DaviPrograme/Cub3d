/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	type_error(int err)
{
	(err == 1) ? ft_putstr_fd("\nerro: allocation memory failure", 2) : 0;
	(err == 2) ? ft_putstr_fd("\nerro: wrong information .cub", 2) : 0;
	(err == 3) ? ft_putstr_fd("\nerro: bad gnl operation", 2) : 0;
	(err == 4) ? ft_putstr_fd("\nerro: map not found in .cub", 2) : 0;
	(err == 5) ? ft_putstr_fd("\nerro: not informed path .cub", 2) : 0;
	(err == 6) ? ft_putstr_fd("\nerro: information not found .cub", 2) : 0;
	(err == 7) ? ft_putstr_fd("\nerro: invalid map", 2) : 0;
	(err == 8) ? ft_putstr_fd("\nerro: invalid file .cub", 2) : 0;
	(err == 9) ? ft_putstr_fd("\nerro: rgb invalid .cub", 2) : 0;
	(err == 10) ? ft_putstr_fd("\nerro: resolution invalid .cub", 2) : 0;
	(err == 11) ? ft_putstr_fd("\nerro: window opening failed", 2) : 0;
	(err == 12) ? ft_putstr_fd("\nerro: file not found", 2) : 0;
	(err == 13) ? ft_putstr_fd("\nerro: texture error", 2) : 0;
	(err == 14) ? ft_putstr_fd("\nerro: failed to generate .bmp", 2) : 0;
	(err == 15) ? ft_putstr_fd("\nerro: flag invalid", 2) : 0;
}
