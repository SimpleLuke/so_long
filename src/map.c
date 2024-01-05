/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:32:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/05 14:59:29 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

bool    check_map(t_game *game);
bool    check_rec(t_game *game);

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
    game->height = 5;
    game->width = 13;
    free(line);
    close(fd);
    return (line);
}

bool    check_map(t_game *game)
{
    if (!check_rec(game))
        return (false);
    return (true);
}

bool    check_rec(t_game *game) 
{
    ft_printf("H: %d,W: %d\n", game->height, game->width);
    if (ft_strlen(game->map) % game->width || game->height == 0)
        return (false);
    return (true);
}
