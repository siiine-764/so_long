/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:43:28 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/14 11:33:42 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_bottom(int y, char **f_m, t_info_map *m)
{
	int		x;
	size_t	i;

	i = -1;
	x = 0;
	while (f_m[y][x])
	{
		if (f_m[y][x] != '1')
		{
			write(1, "error in bottom wall\n", 21);
			while ((m->mapfake)[++i])
				free((m->mapfake)[i]);
			exit(1);
		}
		x++;
	}
}

void	ft_check_right(int y, int len, char **f_m, t_info_map *m)
{
	size_t	i;

	i = -1;
	while (y--)
	{
		if (f_m[y][len - 1] != '1')
		{
			write(1, "error in right wall\n", 20);
			while ((m->mapfake)[++i])
				free((m->mapfake)[i]);
			exit(1);
		}
	}
}

void	ft_check_left(char **f_m, t_info_map *m)
{
	int		y;
	size_t	i;

	i = -1;
	y = 0;
	while (f_m[y])
	{
		if (f_m[y][0] != '1')
		{
			write(1, "error in left wall\n", 19);
			while ((m->mapfake)[++i])
				free((m->mapfake)[i]);
			exit(1);
		}
		y++;
	}
}

void	ft_check_top(char **f_m, t_info_map *m)
{
	int		x;
	size_t	i;

	i = -1;
	x = 0;
	while (f_m[0][x])
	{
		if (f_m[0][x] != '1')
		{
			write(1, "error in top wall\n", 18);
			while ((m->mapfake)[++i])
				free((m->mapfake)[i]);
			exit(1);
		}
		x++;
	}
}
