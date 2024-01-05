/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:32:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/05 20:36:09 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

bool    check_map(t_game *game);
bool    check_rec(t_game *game);
bool    check_comp(t_game *game);
bool    check_wall(t_game *game);

char    *read_map(t_game *game, char *map)
{
    int     fd;
    char    *line;

    fd = open(map, O_RDONLY);
    line = "";
    game->map = "";
    game->height = 0;
    while (line != NULL)
    {
        line = get_next_line(fd);
        if (line != NULL)
        {
            game->width = ft_strlen(line) - 1;
            game->map = ft_strjoin(game->map, ft_strtrim(line, "\n"));
            game->height += 1;
        }
    }
    ft_printf("%s\n", game->map);
    if (!check_map(game))
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    free(line);
    close(fd);
    return (line);
}

bool    check_map(t_game *game)
{
    if (!check_rec(game) || !check_comp(game) || !check_wall(game) || !check_path(game))
        return (false);
    return (true);
}

bool    check_wall(t_game *game)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(game->map);
    while (i < game->width)
    {
        if (game->map[i] != '1')
            return (false);
        i++;
    }
    i = len - 1;
    while (i > len - game->width - 1)
    {
        if (game->map[i] != '1')
            return (false);
        i--;
    }
    i = 0;
    while (i < len)
    {
        if (game->map[i] != '1')
            return (false);
        i += game->width;
    }
    i = game->width - 1;
    while (i < len + 1)
    {
        if (game->map[i] != '1')
            return (false);
        i += game->width;
    }
    return (true);
}

bool    check_comp(t_game *game)
{
    int i;

    i = 0;
    game->comp.wall = 0;
    game->comp.space = 0;
    game->comp.collectible = 0;
    game->comp.map_exit = 0;
    game->comp.player_start = 0;
    while (game->map[i] != '\0')
    {
        if (game->map[i] == '1')
            game->comp.wall++;
        else if (game->map[i] == '0')
            game->comp.space++;
        else if (game->map[i] == 'C')
            game->comp.collectible++;
        else if (game->map[i] == 'E')
            game->comp.map_exit++;
        else if (game->map[i] == 'P')
            game->comp.player_start++;
        else
            return (false);
        i++;
    }
    if (!game->comp.wall || !game->comp.space || !game->comp.collectible || game->comp.map_exit != 1 || game->comp.player_start != 1)
        return (false);
    return (true);
}

bool    check_rec(t_game *game) 
{
    if (ft_strlen(game->map) % game->width || game->height < 2)
        return (false);
    return (true);
}
