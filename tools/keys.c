/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:58:00 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/14 11:44:03 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keyexit(t_info_map *map)
{
	size_t	i;

	i = -1;
	ft_printf("game exit :\\\n");
	ft_destroy(map);
	while ((map->map)[++i])
		free((map->map)[i]);
	exit(0);
}

int	keyhook(int ky, t_info_map *m)
{
	size_t	i;

	i = -1;
	m->od = mlx_xpm_file_to_image(m->mlx, DO, &m->i_w, &m->i_h);
	if ((ky == 2 || ky == 124) && m->map[m->yp][m->xp + 1] != '1')
		ft_to_right(m);
	else if ((ky == 0 || ky == 123) && m->map[m->yp][m->xp - 1] != '1')
		ft_to_left(m);
	else if ((ky == 13 || ky == 126) && m->map[m->yp - 1][m->xp] != '1')
		ft_to_up(m);
	else if ((ky == 1 || ky == 125) && m->map[m->yp + 1][m->xp] != '1')
		ft_to_down(m);
	if (m->c_m == 0)
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->od,
			m->x_e * SZ, m->y_e * SZ);
	if (ky == 53)
	{
		ft_printf("game exit :\\\n");
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(0);
	}
	return (0);
}
