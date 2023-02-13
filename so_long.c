/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:04:50 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/13 10:49:28 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_vars(t_info_map *m)
{
	m->xp = 0;
	m->yp = 0;
	m->x_e = 0;
	m->y_e = 0;
	m->c_m = 0;
	m->movement = 0;
	m->p = NULL;
	m->bg = NULL;
	m->wll = NULL;
	m->dr = NULL;
	m->c = NULL;
	m->od = NULL;
	m->pd = NULL;
}

void	ft_check_file(char *file)
{
	char	type_file[5] = ".ber";
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(file) - 4;
	while (i <= 4)
	{
		if (type_file[i] != file[len + i])
		{
			write(2, "\033[1;31m🛑ERROR file doesnt exit\n\033[0m", 39);
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	file;

	if (ac <= 1)
	{
		write(2, "\033[1;31m🛑accident de travail\n\033[0m", 38);
		exit(1);
	}
	(void)av;
	ft_check_file(av[1]);
	file = ft_read_id(av[1]);
	if (file < 0)
	{
		write(2, "\033[1;31m🛑ERROR file doesnt exit\n\033[0m", 39);
		exit(1);
	}
	ft_read_map(av[1]);
	return (0);
}
