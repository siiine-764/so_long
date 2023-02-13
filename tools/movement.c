/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:54:51 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/12 22:49:24 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_to_right(t_info_map *m)
{
	int		m_xp;
	size_t	i;

	i = 0;
	m->p = mlx_xpm_file_to_image(m->mlx, PLAY, &m->i_w, &m->i_h);
	if (!m->p)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
	}
	if (m->map[m->yp][m->xp + 1] == 'C')
	{
		m->c_m--;
		m->map[m->yp][m->xp + 1] = '0';
	}
	m_xp = m->xp + 1;
	ft_put_door_x(m, m_xp);
	ft_put_player_on_door(m);
	if (m->map[m->yp][m->xp + 1] == '0' || m->map[m->yp][m->xp + 1] == 'P')
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->p, m_xp * SZ, m->yp * SZ);
	m->movement++;
	m->xp++;
	ft_printf("->move: %d\n", m->movement);
}

void	ft_to_left(t_info_map *m)
{
	int		m_xp;
	size_t	i;

	i = 0;
	m->p = mlx_xpm_file_to_image(m->mlx, PLAY, &m->i_w, &m->i_h);
	if (!m->p)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(0);
	}
	if (m->map[m->yp][m->xp - 1] == 'C')
	{
		m->c_m--;
		m->map[m->yp][m->xp - 1] = '0';
	}
	m_xp = m->xp - 1;
	ft_put_door_x(m, m_xp);
	ft_put_player_on_door(m);
	if (m->map[m->yp][m->xp - 1] == '0' || m->map[m->yp][m->xp - 1] == 'P')
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->p, m_xp * SZ, m->yp * SZ);
	m->movement++;
	m->xp--;
	ft_printf("->move: %d\n", m->movement);
}

void	ft_to_up(t_info_map *m)
{
	int		m_yp;
	size_t	i;

	i = 0;
	m->p = mlx_xpm_file_to_image(m->mlx, PLAY, &m->i_w, &m->i_h);
	if (!m->p)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(0);
	}
	if (m->map[m->yp - 1][m->xp] == 'C')
	{
		m->c_m--;
		m->map[m->yp - 1][m->xp] = '0';
	}
	m_yp = m->yp - 1;
	ft_put_door_y(m, m_yp);
	ft_put_player_on_door(m);
	if (m->map[m->yp - 1][m->xp] == '0' || m->map[m->yp - 1][m->xp] == 'P')
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->p, m->xp * SZ, m_yp * SZ);
	m->movement++;
	m->yp--;
	ft_printf("->move: %d\n", m->movement);
}

void	ft_to_down(t_info_map *m)
{
	int		m_yp;
	size_t	i;

	i = 0;
	m->p = mlx_xpm_file_to_image(m->mlx, PLAY, &m->i_w, &m->i_h);
	if (!m->p)
	{
		ft_destroy(m);
		while ((m->map)[++i])
			free((m->map)[i]);
		exit(0);
	}
	if (m->map[m->yp + 1][m->xp] == 'C')
	{
		m->map[m->yp + 1][m->xp] = '0';
		m->c_m--;
	}
	m_yp = m->yp + 1;
	ft_put_door_y(m, m_yp);
	ft_put_player_on_door(m);
	if (m->map[m->yp + 1][m->xp] == '0' || m->map[m->yp + 1][m->xp] == 'P')
		mlx_put_image_to_window(m->mlx, m->mlx_w, m->p, m->xp * SZ, m_yp * SZ);
	m->movement++;
	m->yp++;
	ft_printf("->move: %d\n", m->movement);
}
