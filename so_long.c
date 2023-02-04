/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:04:50 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/04 15:52:40 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	initialize_vars(t_info_map *m)
{
	m->xp = 0;
	m->yp = 0;
	m->x_e = 0;
	m->y_e = 0;
	m->c_m = 0;
	m->movement = 0;
}

int	ft_read_id(char *map)
{
	int	rd_line;

	rd_line = open(map, O_RDONLY);
	if (rd_line < 0)
		return (-1);
	return (rd_line);
}

void	ft_read_map(char *map)
{
	static char	*line;
	int			rd_id;
	t_info_map	m;
	int			width;
	int			height;

	rd_id = ft_read_id(map);
	if (!rd_id)
		write(1, "error", 5);
	line = get_next_line(rd_id);
	width = ft_strlen(line) - 1;
	height = 0;
	while (line != '\0')
	{
		height++;
		line = get_next_line(rd_id);
	}
	m.map = rd_map(map);
	check_player(m.map);
	m.mlx = mlx_init();
	m.mlx_w = mlx_new_window(m.mlx, sz * width, sz * height, "My Window");
	ft_put_image(&m);
	mlx_hook(m.mlx_w, 2, 0, &keyhook, &m);
	mlx_hook(m.mlx_w, 17, 0, keyexit, &m);
	mlx_loop(m.mlx);
}

// void	ft_check_file(char *file)
// {
// 	int	i;

// 	i = 0;
// 	while (file[i])
// 	{
// 		if (file[i] == '.')
// 			if (find(file, ".ber"))
// 				write (1, "this file is correct\n", 21);
// 		i++;
// 	}
// 	write (1, "what do you want to me??\n", 25);
// 	exit(1);
// }
int	main(int ac, char **av)
{
	if (ac <= 1)
	{
		write(1, "\033[1;31m🛑ERROR \033[0m", 22);
		exit(1);
	}
	//ft_check_file(av[1]);
	ft_read_map(av[1]);
	return (0);
}
