/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:32:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 13:33:55 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

bool    check_map(t_game *game);
bool    check_rec(t_game *game);
bool    check_comp(t_game *game);
bool    check_wall(t_game *game);
void	convert_map(t_game *game, char *map_line);

char    *read_map(t_game *game, char *map_path)
{
    int     fd;
    char    *line;
	char	*map_line;

    fd = open(map_path, O_RDONLY);
    line = "";
    map_line = "";
    game->height = 0;
    while (line != NULL)
    {
        line = get_next_line(fd);
        if (line != NULL)
        {
            game->width = ft_strlen(line) - 1;
            map_line = ft_strjoin(map_line, ft_strtrim(line, "\n"));
            game->height += 1;
        }
    }
    ft_printf("%s\n", map_line);
	convert_map(game, map_line);
    if (!check_map(game))
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    free(line);
    close(fd);
    return (line);
}

void	convert_map(t_game *game, char *map_line)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	game->map = (char **)malloc(game->height * sizeof(char *));
	while (i < game->height)
		game->map[i++] = (char *)malloc(game->width * sizeof(char));
	i = 0;
	while (map_line[i] != '\0')
	{
		game->map[j][k] = map_line[i];
		i++;
		k++;
		if (k % game->width == 0)
		{
			j++;
			k = 0;
		}
	}
}

bool	check_map(t_game *game)
{
	if (!check_rec(game) || !check_comp(game) || !check_wall(game) || !check_path(game))
		return (false);
	return (true);
}

bool	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{
			if ((i == 0 && game->map[i][j] != '1') || (i == game->height - 1 && game->map[i][j] != '1'))
				return (false);
			if ((j == 0 && game->map[i][j] != '1') || (j == game->width - 1 && game->map[i][j] != '1'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_comp(t_game *game)
{
	int i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				game->comp.wall++;
			else if (game->map[i][j] == '0')
				game->comp.space++;
			else if (game->map[i][j] == 'C')
				game->comp.collectible++;
			else if (game->map[i][j] == 'P')
				game->comp.player_start++;
			else if (game->map[i][j] == 'E')
				game->comp.map_exit++;
			else
				return (false);
			j++;
		}
		i++;
	}
	if (!game->comp.wall || !game->comp.space || !game->comp.collectible || game->comp.map_exit != 1 || game->comp.player_start != 1)
		return (false);
	return (true);
}

bool	check_rec(t_game *game) 
{
	int	i;
	i = 0;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != game->width || game->height < 2)
			return (false);
		i++;
	}
    return (true);
}
