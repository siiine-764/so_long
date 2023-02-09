/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:21:44 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/08 22:42:25 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_flood_fill(char **f_m, int xp, int yp)
{
	if (f_m[yp][xp] != '1')
	{
		f_m[yp][xp] = '1';
		ft_flood_fill(f_m, xp + 1, yp);
		ft_flood_fill(f_m, xp - 1, yp);
		ft_flood_fill(f_m, xp, yp + 1);
		ft_flood_fill(f_m, xp, yp - 1);
	}
}

void	ft_check_finish(char **f_m)
{
	int	x;
	int	y;

	y = 0;
	while (f_m[y])
	{
		x = 0;
		while (f_m[y][x])
		{
			if (f_m[y][x] == 'C' || f_m[y][x] == 'E')
			{
				write(1, "error in the map\n", 17);
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	ft_position_player(char **f_m)
{
	int	x;
	int	y;
	int	xp;
	int	yp;

	xp = 0;
	yp = 0;
	y = 0;
	while (f_m[y])
	{
		x = 0;
		while (f_m[y][x])
		{
			if (f_m[y][x] == 'P')
			{
				xp = x;
				yp = y;
			}
			x++;
		}
		y++;
	}
	ft_flood_fill(f_m, xp, yp);
}

void	ft_check_path(char **f_m)
{
	int	y;
	int	len;

	len = 0;
	y = 0;
	ft_check_left(f_m);
	ft_check_top(f_m);
	while (f_m[y])
		y++;
	y--;
	ft_check_bottom(y, f_m);
	len = ft_strlen((const char *)f_m[y]);
	ft_check_right(y, len, f_m);
	ft_position_player(f_m);
	ft_check_finish(f_m);
}
