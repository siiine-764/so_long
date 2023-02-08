/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:58:00 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/08 19:58:55 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keyexit(t_info_map *map)
{
	printf("sexy bitch\n");
	free(map->map);
	exit(0);
}

int	keyhook(int ky, t_info_map *m)
{
	void *img_open_door;
	void	*img_dr;
	
	img_dr = mlx_xpm_file_to_image(m->mlx, "./textures/dr.xpm", &m->i_w, &m->i_h);
	img_open_door = mlx_xpm_file_to_image(m->mlx, "./textures/DO.xpm", &m->i_w, &m->i_h);
	if ((ky == 2 || ky == 124) && m->map[m->yp][m->xp + 1] != '1')
		ft_to_right(m);
	else if ((ky == 0 || ky == 123) && m->map[m->yp][m->xp - 1] != '1')
		ft_to_left(m);
	else if ((ky == 13 || ky == 126) && m->map[m->yp - 1][m->xp] != '1')
		ft_to_up(m);
	else if ((ky == 1 || ky == 125) && m->map[m->yp + 1][m->xp] != '1')
		ft_to_down(m);
	if (m->c_m == 0)
		mlx_put_image_to_window(m->mlx, m->mlx_w, img_open_door, (m->x_e) * sz, (m->y_e) * sz);
	if (ky == 53)
	{
		free(m->map);
		exit(0);
	}
	return (0);
}