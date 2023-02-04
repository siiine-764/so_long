/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:24:21 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/04 15:48:38 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./get_next_line/get_next_line.h"
#include "./ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define sz 40

typedef struct info_map
{
	char **map;
	void *mlx;
	void *mlx_w;
	int i_w;
	int i_h;
	int xp;
	int yp;
	int w_w;
	int w_h;
	int x_e;
	int y_e;
	int movement;
	int c_m;
} t_info_map;

typedef struct info_img
{
	void	*img;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img_OD;
} t_info_img;

char *ft_strjoin(char const *s1, char const *s2);
void check_player(char **p);

// movement//
void	ft_check_file(char *file);
void	ft_read_map(char *map);
char	**rd_map(char *map);
int		ft_read_id(char *map);
// void	ft_img(t_info_img i_img, t_info_map *m);
void	initialize_vars(t_info_map *m);
void	ft_put_image(t_info_map *map22);
void	ft_put1(t_info_map *m, int x, int y);
void	ft_put2(t_info_map *m, int x, int y);
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
