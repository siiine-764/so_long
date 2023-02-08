/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:51:59 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/08 19:58:39 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put1(t_info_map *m, int x, int y)
{
	void	*img;
	void	*img1;

	img = mlx_xpm_file_to_image(m->mlx, "./textures/bg.xpm", &m->i_w, &m->i_h);
	img1 = mlx_xpm_file_to_image(m->mlx, "./textures/wall.xpm", &m->i_w, &m->i_h);
	if (m->map[y][x] == '1')
		mlx_put_image_to_window(m->mlx, m->mlx_w, img1, x * sz, y * sz);
	if (m->map[y][x] == '0')
		mlx_put_image_to_window(m->mlx, m->mlx_w, img, x * sz, y * sz);
}

void	ft_put2(t_info_map *m, int x, int y)
{
	void	*img4;
	void	*img2;

	img4 = mlx_xpm_file_to_image(m->mlx, "./textures/dr.xpm", &m->i_w, &m->i_h);
	img2 = mlx_xpm_file_to_image(m->mlx, "./textures/coin.xpm", &m->i_w, &m->i_h);
	if (m->map[y][x] == 'E')
	{
		mlx_put_image_to_window(m->mlx, m->mlx_w, img4, x * sz, y * sz);
		m->x_e = x;
		m->y_e = y;
	}
	if (m->map[y][x] == 'C')
	{
		mlx_put_image_to_window(m->mlx, m->mlx_w, img2, x * sz, y * sz);
		m->c_m++;
	}
}

void	ft_put3(t_info_map *m, int x, int y)
{
	void	*img3;

	img3 = mlx_xpm_file_to_image(m->mlx, "./textures/p.xpm", &m->i_w, &m->i_h);
	if (m->map[y][x] == 'P')
	{
		mlx_put_image_to_window(m->mlx, m->mlx_w, img3, x * sz, y * sz);
		m->xp = x;
		m->yp = y;
	}
}

void	ft_put_image(t_info_map *m)
{
	int	x;
	int	y;

	y = 0;
	initialize_vars(m);
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
