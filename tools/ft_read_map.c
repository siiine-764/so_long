/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:13:56 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/10 19:14:59 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_read_id(char *map)
{
	int	rd_line;

	rd_line = open(map, O_RDONLY);
	if (rd_line < 0)
		return (-1);
	return (rd_line);
}

char	**rd_map(char *map11)
{
	static char	*line;
	int			rd_line;
	char		*map;
	char		*pts;
	char		*ptss;

	rd_line = -1;
	map = malloc(sizeof(char *));
	//map[0] = '\0';
	rd_line = open(map11, O_RDONLY);
	line = get_next_line(rd_line);
	while (line != '\0')
	{
		if (map)
		{
			ptss = map;
			pts = line;
			map = ft_strjoin(map, line);
			free(pts);
			free(ptss);
		}
		line = get_next_line(rd_line);
	}
	return (ft_split(map, '\n'));
}

void	ft_read_map(char *map)
{
	static char	*line;
	int			rd_id;
	t_info_map	m;
	int			w;
	int			h;

	rd_id = ft_read_id(map);
	line = get_next_line(rd_id);
	w = ft_strlen(line) - 1;
	ft_check_width(map);
	h = ft_calculer_height(map);
	m.map = rd_map(map);
	m.mapfake = rd_map(map);
	check_map(m.map);
	ft_check_path(m.mapfake);
	m.mlx = mlx_init();
	m.mlx_w = mlx_new_window(m.mlx, sz * w, sz * h, "My Game");
	ft_put_image(&m);
	mlx_hook(m.mlx_w, 2, 0, &keyhook, &m);
	mlx_hook(m.mlx_w, 17, 0, keyexit, &m);
	mlx_loop(m.mlx);
}
