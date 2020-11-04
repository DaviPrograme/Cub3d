/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_error	g_error;

void	error(void)
{
	ft_putstr_fd("Erro\n", 2);
	file_error(g_error.file);
	func_error(g_error.func);
	type_error(g_error.err);
	memory_free();
	exit(1);
}

int		set_error(int file, int func, int err)
{
	g_error.file = file;
	g_error.func = func;
	g_error.err = err;
	return (err);
}
