/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:32:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 14:26:52 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

bool	check_map(t_game *game);
char	*read_map(t_game *game, char *map_path);

char	*read_map(t_game *game, char *map_path)
{
	int		fd;
	char	*line;
	char	*map_line;

	fd = open(map_path, O_RDONLY);
	line = "";
	map_line = "";
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
	if (!convert_map(game, map_line) && !check_map(game))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	free(line);
	close(fd);
	return (line);
}

bool	check_map(t_game *game)
{
	if (!check_rec(game) || !check_comp(game)
		|| !check_wall(game) || !check_path(game))
		return (false);
	return (true);
}
