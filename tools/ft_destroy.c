/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:31:26 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/14 11:42:14 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_destroy(t_info_map *m)
{
	if (m->p)
		mlx_destroy_image(m->mlx, m->p);
	if (m->bg)
		mlx_destroy_image(m->mlx, m->bg);
	if (m->wll)
		mlx_destroy_image(m->mlx, m->wll);
	if (m->dr)
		mlx_destroy_image(m->mlx, m->dr);
	if (m->c)
		mlx_destroy_image(m->mlx, m->c);
	if (m->od)
		mlx_destroy_image(m->mlx, m->od);
	if (m->pd)
		mlx_destroy_image(m->mlx, m->pd);
	mlx_destroy_window(m->mlx, m->mlx_w);
}
