/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:24:21 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/13 10:59:25 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define SZ 40
# define PLAY "./textures/p.xpm"
# define COIN "./textures/coin.xpm"
# define DR "./textures/dr.xpm"
# define BG "./textures/bg.xpm"
# define WALL "./textures/wall.xpm"
# define DO "./textures/DO.xpm"
# define POND "./textures/PonD.xpm"

typedef struct info_map
{
	char	**map;
	char	**mapfake;
	void	*mlx;
	void	*mlx_w;
	int		i_w;
	int		i_h;
	int		xp;
	int		yp;
	int		w_w;
	int		w_h;
	int		x_e;
	int		y_e;
	int		movement;
	int		c_m;
	void	*p;
	void	*bg;
	void	*wll;
	void	*dr;
	void	*c;
	void	*od;
	void	*pd;
}	t_info_map;

int		ft_calculer_height(char *map);
// functions to check map and check valid map and valid file 
void	ft_check_opendoor_playerondoor(t_info_map *m);
void	check_map(char **p, t_info_map *m);
void	ft_check_width(char *map);
void	ft_check_player(char **p, t_info_map *m);
void	ft_check_door(char **p, t_info_map *m);
void	ft_check_coins(char **p, t_info_map *m);
void	ft_check_path(char **f_m, t_info_map *m);
void	ft_check_bottom(int y, char **f_m, t_info_map *m);
void	ft_check_right(int y, int len, char **f_m, t_info_map *m);
void	ft_check_left(char **f_m, t_info_map *m);
void	ft_check_top(char **f_m, t_info_map *m);
void	ft_position_player(char **f_m);
void	ft_flood_fill(char **f_m, int xp, int yp);
void	ft_check_finish(char **f_m);
// functions to read map //
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_read_map(char *map);
char	**rd_map(char *map);
int		ft_read_id(char *map);
// void	ft_img(t_info_img i_img, t_info_map *m);
void	initialize_vars(t_info_map *m);
// functions to put img//
void	ft_put_image(t_info_map *map22);
void	ft_put1(t_info_map *m, int x, int y);
void	ft_put2(t_info_map *m, int x, int y);
void	ft_put3(t_info_map *m, int x, int y);
// functions to movement//
void	ft_to_right(t_info_map *map);
void	ft_to_left(t_info_map *map);
void	ft_to_down(t_info_map *map);
void	ft_to_up(t_info_map *map);
int		keyexit(t_info_map *map);
int		keyhook(int keycode, t_info_map *map22);
void	ft_put_player_on_door(t_info_map *m);
void	ft_put_door_x(t_info_map *m, int x_p);
void	ft_put_door_y(t_info_map *m, int y_p);
// messages error//
void	message_error(t_info_map *m);
void	ft_err_message_player(int players, t_info_map *m);
void	ft_err_message_door(int doors, t_info_map *m);
void	ft_err_message_coin(int coins, t_info_map *m);
void	ft_err_message_map(t_info_map *m);
//function destroy//
void	ft_destroy(t_info_map *m);
#endif
