/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:24:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/05 16:18:50 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    render_map(t_game *game);

void    render_image(t_game *game)
{
    render_map(game);
    // game->texture.ground = mlx_xpm_file_to_image(game->mlx, "assets/pokemon_bg.xpm", &game->width, &game->height);
    // if (game->texture.ground == NULL)
    //     ft_printf("FAIL TO LOAD IMAGE\n");
    // for (int i = 0; i < 1080; i += 32)
    // {
    //     for (int j = 0; j < 1920; j += 32)
    //         mlx_put_image_to_window(game->mlx, game->win, game->texture.ground, j, i);
    // }
    // mlx_put_image_to_window(game->mlx, game->win, game->texture.ground, 0, 0);
}

void    load_image(t_game *game)
{
    game->texture.space = mlx_xpm_file_to_image(game->mlx, "assets/pokemon_bg.xpm", &game->texture.width, &game->texture.height);
    if (game->texture.space == NULL)
        ft_printf("FAIL TO LOAD SPACE IMAGE\n");
    game->texture.wall = mlx_xpm_file_to_image(game->mlx, "assets/pokemon_tree.xpm", &game->texture.width, &game->texture.height);
    if (game->texture.wall == NULL)
        ft_printf("FAIL TO LOAD WALL IMAGE\n");
    game->texture.collectible = mlx_xpm_file_to_image(game->mlx, "assets/pokemon_collectible.xpm", &game->texture.width, &game->texture.height);
    if (game->texture.collectible == NULL)
        ft_printf("FAIL TO LOAD COLLECTIBLE IMAGE\n");
    game->texture.map_exit = mlx_xpm_file_to_image(game->mlx, "assets/pokemon_exit.xpm", &game->texture.width, &game->texture.height);
    if (game->texture.map_exit == NULL)
        ft_printf("FAIL TO LOAD EXIT IMAGE\n");
    game->texture.player_start = mlx_xpm_file_to_image(game->mlx, "assets/pokemon_start.xpm", &game->texture.width, &game->texture.height);
    if (game->texture.player_start == NULL)
        ft_printf("FAIL TO LOAD START IMAGE\n");
}

void    render_map(t_game *game)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (game->map[i] != '\0')
    {
        if (game->map[i] == '1')
            mlx_put_image_to_window(game->mlx, game->win, game->texture.wall, j * 32, k * 32);
        if (game->map[i] == '0')
            mlx_put_image_to_window(game->mlx, game->win, game->texture.space, j * 32, k * 32);
        if (game->map[i] == 'C')
            mlx_put_image_to_window(game->mlx, game->win, game->texture.collectible, j * 32, k * 32);
        if (game->map[i] == 'P')
            mlx_put_image_to_window(game->mlx, game->win, game->texture.player_start, j * 32, k * 32);
        if (game->map[i] == 'E')
            mlx_put_image_to_window(game->mlx, game->win, game->texture.map_exit, j * 32, k * 32);
        if ((i + 1) % game->width == 0)
        {
            j = 0;
            k++;
        }
        else
            j++;
        i++;
    }
}
