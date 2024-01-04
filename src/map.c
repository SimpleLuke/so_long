/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:32:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/04 19:30:15 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

bool check_map(t_game *game, char *map);

char    *read_map(t_game *game, char *map)
{
    int     fd;
    char    *line;

    if (!check_map(game, map))
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    fd = open(map, O_RDONLY);
    line = "";
    game->map = "";
    while (line != NULL)
    {
        line = get_next_line(fd);
        if (line != NULL)
            game->map = ft_strjoin(game->map, line);
        else
            game->map = ft_strjoin(game->map, "\0");
    }
    free(line);
    close(fd);
    return (line);
}

bool check_map(t_game *game, char *map)
{
    int     fd;
    size_t  len;
    size_t  height;
    char    *line;

    len = 0;
    height = 0;
    fd = open(map, O_RDONLY);
    line = get_next_line(fd);
    len = ft_strlen(line);
    while (line != NULL)
    {
        line = get_next_line(fd);
        if (line != NULL && len != ft_strlen(line))
            return (false);
        height++;
    }
    free(line);
    close(fd);
    game->width = len - 1;
    game->height = height;
    return (true);
}
