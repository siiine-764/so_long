/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:45:07 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/13 10:54:05 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	message_error(t_info_map *m)
{
	size_t	i;

	i = -1;
	write(1, "accident de travail", 22);
	while ((m->map)[++i])
		free((m->map)[i]);
	exit(1);
}

void	ft_err_message_player(int players, t_info_map *m)
{
	size_t	i;

	i = -1;
	if (players > 1)
	{
		write(1, "wtf UGiveMeMorePlayerWhatDoUThinkUrselfDoing,", 45);
		write(1, "RespectMyRulesPlay\n", 19);

		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	else if (players == 0)
	{
		write(1, "where's player, do u kidding me!!\n", 33);

		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
}

void	ft_err_message_door(int doors, t_info_map *m)
{
	size_t	i;

	i = -1;
	if (doors > 1)
	{
		write(1, "wtf u give me more doors do u wanna finished", 44);
		write(1, "this game by many doors respect my rules play\n", 46);

		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	else if (doors == 0)
	{
		write(1, "where's door, do u kidding me!!\n", 33);

		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
}

void	ft_err_message_coin(int coins, t_info_map *m)
{
	size_t	i;

	i = -1;
	if (coins == 0)
	{
		write(1, "where's coins, do u kidding me!!\n", 34);

		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
}

void	ft_err_message_map(t_info_map *m)
{
	size_t	i;

	i = -1;
	write(1, "error, map invalide, u give me map incorrect!!\n", 47);
	while ((m->map)[++i])
		free((m->map)[i]);
	exit(0);
}
