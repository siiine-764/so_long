/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:31:10 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/14 11:15:14 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_player_on_door(t_info_map *m)
{
	size_t	i;

	i = 0;
	m->bg = mlx_xpm_file_to_image(m->mlx, BG, &m->i_w, &m->i_h);
	if (!m->bg)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	mlx_put_image_to_window(m->mlx, m->mlx_w, m->bg, m->xp * SZ, m->yp * SZ);
	m->dr = mlx_xpm_file_to_image(m->mlx, DR, &m->i_w, &m->i_h);
	if (!m->dr)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	if (m->map[m->yp][m->xp] == 'E')
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->dr,
			m->x_e * SZ, m->y_e * SZ);
}

void	ft_put_door_x(t_info_map *m, int x_p)
{
	size_t	i;

	i = 0;
	m->pd = mlx_xpm_file_to_image(m->mlx, POND, &m->i_w, &m->i_h);
	if (!m->pd)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	if (m->map[m->yp][x_p] == 'E')
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->pd, x_p * SZ, m->yp * SZ);
	if (m->c_m == 0 && m->map[m->yp][x_p] == 'E')
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(0);
	}
}

void	ft_put_door_y(t_info_map *m, int y_p)
{
	size_t	i;

	i = 0;
	m->pd = mlx_xpm_file_to_image(m->mlx, POND, &m->i_w, &m->i_h);
	if (!m->pd)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	if (m->map[y_p][m->xp] == 'E')
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->pd, m->xp * SZ, y_p * SZ);
	if (m->c_m == 0 && m->map[y_p][m->xp] == 'E')
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(0);
	}
}
