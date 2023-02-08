/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:40:38 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/08 18:13:04 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_map(char **p)
{
    int i;
    int players;
    int doors;
    int coins;
    int k;

    i = -1;
    players = 0;
    doors = 0;
	coins = 0;
    k = 0;

	while (p[++i])
	{
		k = -1;
		while (p[i][++k])
		{
			if (p[i][k] == 'P')
				players++;
			else if (p[i][k] == 'E') 
				doors++;
			else if (p[i][k] == 'C') 
				coins++;
			else if (p[i][k] != 'P' && p[i][k] != '0' && p[i][k] != '1'
				&& p[i][k] != 'C' && p[i][k] != 'E')
				{
					write(1, "error, map invalide, u give me map incorrect\n",45);
				exit(0);
				}
		}
		printf("%s\n", p[i]);
	}
	if (players > 1 || players == 0)
		ft_err_message_player(players);
	if (doors > 1 || doors == 0)
		ft_err_message_door(doors);
	if (coins == 0)
		ft_err_message_coin(coins);
}

// int main(void)
// {

//   int rd_line;
//     char *map;
//   char *line;
//     int width;
//     int height;
//     rd_line = -1;
//     map = "";
//     rd_line = open("../maps/map2.ber", O_RDONLY);

// 	    line = get_next_line(rd_line);
//         width = ft_strlen(line) - 1;
//     height = 0;
//     while(line != '\0')
//     {
//         height++;
//         //line = get_next_line(rd_line);
//         if (map)
//             map = ft_strjoin(map, line);
//         else
//             map = ft_strjoin(ft_strdup(""), line);
//         line = get_next_line(rd_line);

//     }
// 	t_info_map map22;
//     //printf("%s \n", map);
//     //printf("%s\n", line);
//     map22.map = ft_split(map, '\n');
//     check_player( map22.map);
// }
