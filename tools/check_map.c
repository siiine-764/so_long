/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:40:38 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/14 11:24:01 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_player(char **p, t_info_map *m)
{
	int	players;
	int	i;
	int	k;

	players = 0;
	i = -1;
	k = 0;
	while (p[++i])
	{
		k = -1;
		while (p[i][++k])
			if (p[i][k] == 'P')
				players++;
	}
	if (players > 1 || players == 0)
		ft_err_message_player(players, m);
}

void	ft_check_door(char **p, t_info_map *m)
{
	int	i;
	int	k;
	int	doors;

	doors = 0;
	i = -1;
	k = 0;
	while (p[++i])
	{
		k = -1;
		while (p[i][++k])
			if (p[i][k] == 'E')
				doors++;
	}
	if (doors > 1 || doors == 0)
		ft_err_message_door(doors, m);
}

void	ft_check_coins(char **p, t_info_map *m)
{
	int	i;
	int	k;
	int	coins;

	coins = 0;
	i = -1;
	k = 0;
	while (p[++i])
	{
		k = -1;
		while (p[i][++k])
			if (p[i][k] == 'C')
				coins++;
	}
	if (coins == 0)
		ft_err_message_coin(coins, m);
}

void	check_map(char **p, t_info_map	*m)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (p[++i])
	{
		k = -1;
		while (p[i][++k])
		{
			if (p[i][k] != 'P' && p[i][k] != '0' && p[i][k] != '1'
				&& p[i][k] != 'C' && p[i][k] != 'E')
				ft_err_message_map(m);
		}
	}
	ft_check_player(p, m);
	ft_check_door(p, m);
	ft_check_coins(p, m);
}
