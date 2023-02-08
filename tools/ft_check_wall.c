/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:43:28 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/07 12:43:48 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_bottom(int y, char **f_m)
{
	int	x;

	x = 0;
	while (f_m[y][x])
	{
		if (f_m[y][x] != '1')
		{
			write(1, "error in bottom wall\n", 21);
			exit(0);
		}
		x++;
	}
}

void	ft_check_right(int y, int len, char **f_m)
{
	while (y--)
	{
		if (f_m[y][len - 1] != '1')
		{
			write(1, "error in right wall\n", 20);
			exit(0);
		}
	}
}

void	ft_check_left(char **f_m)
{
	int y;

	y = 0;
	while (f_m[y])
	{
		if (f_m[y][0] != '1')
		{
			write(1, "error in left wall\n", 19);
			exit(0);
		}
		y++;
	}
}

void	ft_check_top(char **f_m)
{
	int x;

	x = 0;
	while (f_m[0][x])
	{
		if (f_m[0][x] != '1')
		{
			write(1, "error in top wall\n", 18);
			exit(0);
		}
		x++;
	}
}
