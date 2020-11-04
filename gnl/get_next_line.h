/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:10:22 by davi              #+#    #+#             */
/*   Updated: 2020/05/07 16:11:41 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct	s_gnl
{
	char		string[BUFFER_SIZE];
	char		*aux_char;
	int			aux_int;
	int			nread;
	int			value;
	char		*status;
	int			ret;
}				t_gnl;

void			initialize_gnl(t_gnl *gnl, int fd);
int				get_next_line(int fd, char **line);
char			*line_pointer(t_gnl *gnl, int fd);
#endif
