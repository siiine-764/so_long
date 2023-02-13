/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:51:59 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/13 10:54:36 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put1(t_info_map *m, int x, int y)
{
	size_t	i;

	i = -1;
	m->wll = mlx_xpm_file_to_image(m->mlx, WALL, &m->i_w, &m->i_h);
	if (!m->wll)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	if (m->map[y][x] == '1')
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->wll, x * SZ, y * SZ);
	m->bg = mlx_xpm_file_to_image(m->mlx, BG, &m->i_w, &m->i_h);
	if (!m->bg)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	if (m->map[y][x] == '0')
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->bg, x * SZ, y * SZ);
}

void	ft_put2(t_info_map *m, int x, int y)
{
	size_t	i;

	i = -1;
	m->dr = mlx_xpm_file_to_image(m->mlx, DR, &m->i_w, &m->i_h);
	if (!m->dr)
	{
		while ((m->map)[++i])
			free((m->map)[i]);
		ft_destroy(m);
		exit(1);
	}
	if (m->map[y][x] == 'E')
	{
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->dr, x * SZ, y * SZ);
		m->x_e = x;
		m->y_e = y;
	}
	m->c = mlx_xpm_file_to_image(m->mlx, COIN, &m->i_w, &m->i_h);
	if (!m->c)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	if (m->map[y][x] == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->c, x * SZ, y * SZ);
		m->c_m++;
	}
}

void	ft_put3(t_info_map *m, int x, int y)
{
	size_t	i;

	i = -1;
	m->p = mlx_xpm_file_to_image(m->mlx, PLAY, &m->i_w, &m->i_h);
	if (!m->p)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	if (m->map[y][x] == 'P')
	{
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->p, x * SZ, y * SZ);
		m->xp = x;
		m->yp = y;
	}
}

void	ft_check_opendoor_playerondoor(t_info_map *m)
{
	size_t	i;

	i = -1;
	m->od = mlx_xpm_file_to_image(m->mlx, DO, &m->i_w, &m->i_h);
	if (!m->od)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
	m->pd = mlx_xpm_file_to_image(m->mlx, POND, &m->i_w, &m->i_h);
	if (!m->pd)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(1);
	}
}

void	ft_put_image(t_info_map *m)
{
	int	x;
	int	y;

	y = 0;
	initialize_vars(m);
	ft_check_opendoor_playerondoor(m);
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x] != '\0' && m->map[y][x] != '\n')
		{
			ft_put1(m, x, y);
			ft_put2(m, x, y);
			ft_put3(m, x, y);
			x++;
		}
		y++;
	}
}
