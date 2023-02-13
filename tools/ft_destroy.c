/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:31:26 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/12 20:12:38 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_destroy(t_info_map *m)
{
	if (m->p)
	{
		printf("\na1\n");			
		mlx_destroy_image(m->mlx, m->p);
	}
	if (m->bg)
	{
		printf("\na2\n");			
		mlx_destroy_image(m->mlx, m->bg);
	}
	if (m->wll)
	{
		printf("\na3\n");			
		mlx_destroy_image(m->mlx, m->wll);
	}
	if (m->dr)
	{
		printf("\na4\n");			
		mlx_destroy_image(m->mlx, m->dr);
	}
	if (m->c)
	{
		printf("\na5\n");			
		mlx_destroy_image(m->mlx, m->c);
	}
	if (m->OD)
	{
		printf("\na6\n");			
		mlx_destroy_image(m->mlx, m->OD);
	}
	if (m->pd)
	{
		printf("\na7\n");			
		mlx_destroy_image(m->mlx, m->pd);
	}
	mlx_destroy_window(m->mlx,  m->mlx_w);
}