/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:54:51 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/02 16:15:17 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_to_right(t_info_map *m)
{
	void	*i3;
	void	*i4;
	void	*i;

	i = mlx_xpm_file_to_image(m->mlx, "./textures/bg.xpm", &m->i_w, &m->i_h);
	i3 = mlx_xpm_file_to_image(m->mlx, "./textures/p.xpm", &m->i_w, &m->i_h);
	i4 = mlx_xpm_file_to_image(m->mlx, "./textures/dr.xpm", &m->i_w, &m->i_h);
	if (m->map[m->y_p][m->x_p + 1] == 'C')
	{
		m->c_m--;
		m->map[m->y_p][m->x_p + 1] = '0';
	}
	if (m->c_m == 0 && m->map[m->y_p][m->x_p + 1] == 'E')
	{
		free(m->map);
		exit(0);
	}
	printf("->\n%d", m->c_m);
	mlx_put_image_to_window(m->mlx, m->mlx_w, i, m->x_p * sz, m->y_p * sz);
	mlx_put_image_to_window(m->mlx, m->mlx_w, i3, (m->x_p + 1) * sz, m->y_p * sz);
	if (m->map[m->y_p][m->x_p] == 'E')
		mlx_put_image_to_window(m->mlx, m->mlx_w, i4, m->x_e * sz, m->y_e * sz);
	m->movement++;
	ft_printf("->move: %d\n", m->movement);
	m->x_p++;
}

void	ft_to_left(t_info_map *m)
{
	void	*i3;
	void	*i4;
	void	*i;

	i = mlx_xpm_file_to_image(m->mlx, "./textures/bg.xpm", &m->i_w, &m->i_h);
	i3 = mlx_xpm_file_to_image(m->mlx, "./textures/p.xpm", &m->i_w, &m->i_h);
	i4 = mlx_xpm_file_to_image(m->mlx, "./textures/dr.xpm", &m->i_w, &m->i_h);
	if (m->map[m->y_p][m->x_p - 1] == 'C')
	{
		m->c_m--;
		m->map[m->y_p][m->x_p - 1] = '0';
	}	
	if (m->c_m == 0 && m->map[m->y_p][m->x_p - 1] == 'E')
	{
		free(m->map);
		exit(0);
	}
	ft_printf("-->%d\n", m->c_m);
	mlx_put_image_to_window(m->mlx, m->mlx_w, i, m->x_p * sz, m->y_p * sz);
	mlx_put_image_to_window(m->mlx, m->mlx_w, i3, (m->x_p - 1) * sz, m->y_p * sz);
	if (m->map[m->y_p][m->x_p] == 'E')
		mlx_put_image_to_window(m->mlx, m->mlx_w, i4, m->x_e * sz, m->y_e * sz);
	m->movement++;
	ft_printf("->move: %d\n", m->movement);
	m->x_p--;
}

void	ft_to_up(t_info_map *m)
{
	void	*i3;
	void	*i4;
	void	*i;

	i = mlx_xpm_file_to_image(m->mlx, "./textures/bg.xpm", &m->i_w, &m->i_h);
	i3 = mlx_xpm_file_to_image(m->mlx, "./textures/p.xpm", &m->i_w, &m->i_h);
	i4 = mlx_xpm_file_to_image(m->mlx, "./textures/dr.xpm", &m->i_w, &m->i_h);
	if (m->map[m->y_p - 1][m->x_p] == 'C')
	{
		m->c_m--;
		m->map[m->y_p - 1][m->x_p] = '0';
	}
	if (m->c_m == 0 && m->map[m->y_p - 1][m->x_p] == 'E')
	{
		free(m->map);
		exit(0);
	}
	ft_printf("-->%d\n", m->c_m);
	mlx_put_image_to_window(m->mlx, m->mlx_w, i, m->x_p * sz, m->y_p * sz);
	mlx_put_image_to_window(m->mlx, m->mlx_w, i3, m->x_p * sz, (m->y_p - 1) * sz);
	if (m->map[m->y_p][m->x_p] == 'E')
		mlx_put_image_to_window(m->mlx, m->mlx_w, i4, m->x_e * sz, m->y_e * sz);
	m->movement++;
	ft_printf("->move: %d\n", m->movement);
	m->y_p--;
}

void	ft_to_down(t_info_map *m)
{
	void	*i3;
	void	*i4;
	void	*i;

	i = mlx_xpm_file_to_image(m->mlx, "./textures/bg.xpm", &m->i_w, &m->i_h);
	i3 = mlx_xpm_file_to_image(m->mlx, "./textures/p.xpm", &m->i_w, &m->i_h);
	i4 = mlx_xpm_file_to_image(m->mlx, "./textures/dr.xpm", &m->i_w, &m->i_h);
	if (m->map[m->y_p + 1][m->x_p] == 'C')
	{
		m->map[m->y_p + 1][m->x_p] = '0';
		m->c_m--;
	}
	if (m->c_m == 0 && m->map[m->y_p + 1][m->x_p] == 'E')
	{
		free(m->map);
		exit(0);
	}
	ft_printf("-->%d\n", m->c_m);
	mlx_put_image_to_window(m->mlx, m->mlx_w, i, m->x_p * sz, m->y_p * sz);
	mlx_put_image_to_window(m->mlx, m->mlx_w, i3, m->x_p * sz, (m->y_p + 1) * sz);
	if (m->map[m->y_p][m->x_p] == 'E')
		mlx_put_image_to_window(m->mlx, m->mlx_w, i4, m->x_e * sz, m->y_e * sz);
	m->movement++;
	ft_printf("->move: %d\n", m->movement);
	m->y_p++;
}
