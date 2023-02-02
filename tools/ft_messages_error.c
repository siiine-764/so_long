/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_messages_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:45:07 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/02 11:54:34 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	message_error(void)
{
	write(1, "accident de travail", 22);
	exit(1);
}

void	ft_err_message_player(int players)
{
	if (players > 1)
	{
		write(1, "wtf UGiveMeMorePlayerWhatDoUThinkUrselfDoing,", 45);
		write(1, "RespectMyRulesPlay\n", 19);
		exit(1);
	}
	else if (players == 0)
	{
		write(1, "where's player, do u kidding me!!\n", 33);
		exit(1);
	}
}

void	ft_err_message_door(int doors)
{
	if (doors > 1)
	{
		write(1, "wtf u give me more doors do u wanna finished", 44);
		write(1, "this game by many doors respect my rules play\n", 46);
		exit(1);
	}
	else if (doors == 0)
	{
		write(1, "where's door, do u kidding me!!\n", 33);
		exit(1);
	}
}

void	ft_err_message_coin(int coins)
{
	if (coins == 0)
	{
		write(1, "where's coins, do u kidding me!!\n", 35);
		exit(1);
	}
}
