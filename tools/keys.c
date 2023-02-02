/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:58:00 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/02 15:05:44 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keyexit(t_info_map *map)
{
	printf("sexy bitch\n");
	free(map->map);
	exit(0);
}

int	keyhook(int keycode, t_info_map *map22)
{
	void *img_open_door;

	img_open_door = mlx_xpm_file_to_image(map22->mlx, "./textures/door_open.xpm", &map22->i_w, &map22->i_h);
	if ((keycode == 2 || keycode == 124) && map22->map[map22->y_p][map22->x_p + 1] != '1')
		ft_to_right(map22);
	else if ((keycode == 0 || keycode == 123) && map22->map[map22->y_p][map22->x_p - 1] != '1')
		ft_to_left(map22);
	else if ((keycode == 13 || keycode == 126) && map22->map[map22->y_p - 1][map22->x_p] != '1')
		ft_to_up(map22);
	else if ((keycode == 1 || keycode == 125) && map22->map[map22->y_p + 1][map22->x_p] != '1')
		ft_to_down(map22);
	if (map22->c_m == 0)
		mlx_put_image_to_window(map22->mlx, map22->mlx_w, img_open_door, (map22->x_e) * sz, (map22->y_e) * sz);
	if (keycode == 53)
	{
		free(map22->map);
		exit(0);
	}
	return (0);
}