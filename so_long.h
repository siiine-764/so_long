/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:24:21 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/02 16:13:25 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./get_next_line/get_next_line.h"
#include "./ft_printf/ft_printf.h"
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

#define sz 128

typedef struct info_map
{
	char **map;
	void *mlx;
	void *mlx_w;
	int i_w;
	int i_h;
	int x_p;
	int y_p;
	int window_width;
	int window_height;
	int x_e;
	int y_e;
	int movement;
	int c_m;
} t_info_map;

char *ft_strjoin(char const *s1, char const *s2);
void check_player(char **p);

// movement//
void	ft_read_map();
void	ft_to_right(t_info_map *map);
void	ft_to_left(t_info_map *map);
void	ft_to_down(t_info_map *map);
void	ft_to_up(t_info_map *map);
int		keyexit(t_info_map *map);
int		keyhook(int keycode, t_info_map *map22);
// message error//
void message_error();
void ft_err_message_player(int players);
void ft_err_message_door(int doors);
void ft_err_message_coin(int coins);
#endif
