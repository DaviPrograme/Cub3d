/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void				atribuir_valor(long long *vetor)
{
	vetor[0] = 1;
	vetor[1] = 0;
	vetor[2] = 0;
}

static int				verificador(unsigned long long resul, long long ver)
{
	if (resul > 9223372036854775807 && (ver == 1))
		return (-1);
	else if (resul > 9223372036854775807 && (ver == -1))
		return (0);
	else
		return (resul * ver);
}

int						ft_atoi(const char *fr)
{
	long long			con;
	unsigned long long	resul;
	long long			var[4];

	con = 0;
	resul = 0;
	atribuir_valor(var);
	while (fr[con] != '\0')
	{
		var[2] = con;
		if (((fr[con] >= 9 && fr[con] <= 13) || fr[con] == 32) && var[1] == 0)
			++con;
		else if (((fr[con] == '-' || (fr[con] == '+')) && var[1] == 0))
			var[0] = 44 - fr[con];
		else if (fr[con] >= '0' && fr[con] <= '9')
			resul = (resul * 10) + (fr[con] - '0');
		else
			break ;
		if (var[2] == con)
		{
			var[1] = 1;
			++con;
		}
	}
	return (verificador(resul, var[0]));
}
