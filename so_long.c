/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:04:50 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/02 15:02:09 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	key_hook(int keycode,t_info_map *map22)
// {
//     void	*img3;
//     void	*img ;

//     img  = mlx_xpm_file_to_image(map22->mlx, "./textures/bg.xpm", &map22->img_width, &map22->img_height);

//   printf("%c\n",map22->map[map22->info_p.y_player  ][map22->info_player.x_player + 1]);
//   printf("%c\n",map22->map[map22->info_player.x_player + 1][map22->info_player.y_player]);
//     if (keycode == 2 && map22->map[map22->info_player.y_player][map22->info_player.x_player + 1])
//     {
//         printf("start\n");
//         img3 = mlx_xpm_file_to_image(map22->mlx, "./textures/player.xpm", &map22->img_width, &map22->img_height);
//         mlx_put_image_to_window(map22->mlx, map22->mlx_win, img3, (map22->info_player.x_player + 1) * 128, (map22->info_player.y_player ) * 128);
//         // mlx_put_image_to_window(map22->mlx, map22->mlx_win, img , map22->info_player.x_player * 128, map22->info_player.y_player * 128);
//         // printf("move to right: %d\n",keycode);
//         map22->info_player.x_player++;
//         // printf("x_player: %d\n",  map22->info_player.x_player);
//     }
//     // if ((keycode == 13) &&  map22->map[map22->info_player.x_player - 1][map22->info_player.y_player] != '1')
//     // {
//     //     mlx_put_image_to_window(map22->mlx, map22->mlx_win, img , map22->info_player.x_player * 128, map22->info_player.y_player * 128);
//     //     mlx_put_image_to_window(map22->mlx, map22->mlx_win, img3,  (map22->info_player.x_player - 1) * 128,( map22->info_player.y_player) * 128);
//     //     printf("move to up: %d\n",keycode);
//     //     map22->info_player.x_player--;
//     //     printf("move to right: %s\n",map22->map[map22->info_player.y_player]);
//     // }
//     // if ((keycode == 0) &&  map22->map[map22->info_player.x_player][map22->info_player.y_player - 1] != '1')
//     // {
//     //     mlx_put_image_to_window(map22->mlx, map22->mlx_win, img , map22->info_player.x_player * 128, map22->info_player.y_player * 128);
//     //     mlx_put_image_to_window(map22->mlx, map22->mlx_win, img3,  (map22->info_player.x_player)* 128,(map22->info_player.y_player - 1) * 128);
//     //     printf("move to left: %d\n",keycode);
//     //     map22->info_player.y_player--;
//     //     printf("move to right: %s\n",map22->map[map22->info_player.y_player]);
//     // }
//     // if ((keycode == 1) &&  map22->map[map22->info_player.x_player + 1][map22->info_player.y_player] != '1')
//     // {
//     //     mlx_put_image_to_window(map22->mlx, map22->mlx_win, img , map22->info_player.x_player * 128, map22->info_player.y_player * 128);
//     //     mlx_put_image_to_window(map22->mlx, map22->mlx_win, img3, (map22->info_player.x_player + 1)* 128, ( map22->info_player.y_player) * 128);
//     //     printf("move to down: %d\n",keycode);
//     //     map22->info_player.x_player++;
//     //     printf("move to right: %s\n",map22->map[map22->info_player.y_player]);
//     // }
//     return 0;
// }

void ft_read_map()
{
    static char *line;
    int rd_line;
    char *map;
    char *pts;
    char *ptss;
    t_info_map map22;
    int width;
    int height;
    rd_line = -1;
    map = malloc(sizeof(char *));
    map[0] = '\0';
    rd_line = open("maps/map2.ber", O_RDONLY);
    line = get_next_line(rd_line);
    width = ft_strlen(line) - 1;
    height = 0;
    while (line != '\0')
    {
        height++;
        if (map)
        {
            ptss = map;
            pts = line;
            map = ft_strjoin(map, line);
            free(pts);
            free(ptss);
        }
        // else
        // {
        //     map = ft_strjoin(ft_strdup(""), line);
        // }
        line = get_next_line(rd_line);
        //printf("line: %s\n", line);
    }
    void *img;
    void *img1;
    void *img2;
    void *img3;
    void *img4;
    void *img_open_door;
    int x;
    int y = 0;
    map22.map = ft_split(map, '\n');
   // check_player(map22.map);
    map22.mlx = mlx_init();
    map22.mlx_w = mlx_new_window(map22.mlx, sz * width, sz * height, "My Window");
    img = mlx_xpm_file_to_image(map22.mlx, "./textures/bg.xpm", &map22.i_w, &map22.i_h);
    img1 = mlx_xpm_file_to_image(map22.mlx, "./textures/wall.xpm", &map22.i_w, &map22.i_h);
    img2 = mlx_xpm_file_to_image(map22.mlx, "./textures/coin.xpm", &map22.i_w, &map22.i_h);
    img3 = mlx_xpm_file_to_image(map22.mlx, "./textures/p.xpm", &map22.i_w, &map22.i_h);
    img4 = mlx_xpm_file_to_image(map22.mlx, "./textures/dr.xpm", &map22.i_w, &map22.i_h);
    img_open_door = mlx_xpm_file_to_image(map22.mlx, "./textures/door_open.xpm", &map22.i_w, &map22.i_h);

    while (map22.map[y])
    {
        x = 0;
        while (map22.map[y][x] != '\0' && map22.map[y][x] != '\n')
        {
            if (map22.map[y][x] == '1')
                mlx_put_image_to_window(map22.mlx, map22.mlx_w, img1, x * sz, y * sz);
            if (map22.map[y][x] == '0')
                mlx_put_image_to_window(map22.mlx, map22.mlx_w, img, x * sz, y * sz);
            if (map22.map[y][x] == 'P')
            {
                mlx_put_image_to_window(map22.mlx, map22.mlx_w, img3, x * sz, y * sz);
                map22.x_p = x;
                map22.y_p = y;
            }
            if (map22.map[y][x] == 'E')
            {
                mlx_put_image_to_window(map22.mlx, map22.mlx_w, img4, x * sz, y * sz);
                map22.x_e = x;
                map22.y_e = y;
            }
            if (map22.map[y][x] == 'C')
            {
                mlx_put_image_to_window(map22.mlx, map22.mlx_w, img2, x * sz, y * sz);
                map22.c_m++;
            }
            x++;
        }
        y++;
    }
    // map22.coins_map--;
    mlx_hook(map22.mlx_w, 2, 0, &keyhook, &map22);
    mlx_hook(map22.mlx_w, 17, 0, keyexit, &map22);
    mlx_loop(map22.mlx);
}
int main()
{
    ft_read_map();
}