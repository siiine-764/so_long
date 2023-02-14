/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:12:03 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/14 12:12:24 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_calculer_height(char *map)
{
	static char	*line;
	int			rd_id;
	int			height;

	height = 0;
	rd_id = ft_read_id(map);
	line = get_next_line(rd_id);
	free(line);
	while (line != '\0')
	{
		height++;
		line = get_next_line(rd_id);
		free(line);
	}
	return (height);
}

void	ft_check_width(char *map)
{
	int			rd_id;
	static char	*line;
	int			w;
	int			width;
	int			h;

	w = 0;
	h = ft_calculer_height(map);
	rd_id = ft_read_id(map);
	line = get_next_line(rd_id);
	width = ft_strlen(line) - 1;
	free(line);
	while (line != '\0' && h > 2)
	{
		line = get_next_line(rd_id);
		w = ft_strlen(line) - 1;
		if (w != width)
		{
			ft_printf("error 💀\n");
			exit(0);
		}
		h--;
		free(line);
	}
}
