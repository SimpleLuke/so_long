/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:32:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/10 14:59:42 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

bool	check_map(t_game *game, char *map_line);
char	*read_map(t_game *game, char *map_path);
void	free_lines(char *line, char *map_line, char *trim);
void	map_to_line(t_game *game, int fd, char **line, char **map_line);

void	map_to_line(t_game *game, int fd, char **line, char **map_line)
{
	char	*trim;

	*line = "";
	*map_line = ft_strdup("");
	while (*line != NULL)
	{
		*line = get_next_line(fd);
		if (*line != NULL)
		{
			game->width = ft_strlen(*line) - 1;
			trim = ft_strtrim(*line, "\n");
			*map_line = ft_strjoin_gnl(*map_line, trim, game->width);
			game->height += 1;
			free_lines(*line, 0, trim);
		}
	}
}

char	*read_map(t_game *game, char *map_path)
{
	int		fd;
	char	*line;
	char	*map_line;

	fd = open(map_path, O_RDONLY);
	map_to_line(game, fd, &line, &map_line);
	if (!convert_map(game, map_line) && !check_map(game, map_line))
	{
		free_lines(line, map_line, 0);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	free_lines(line, map_line, 0);
	close(fd);
	return (line);
}

bool	check_map(t_game *game, char *map_line)
{
	if (!check_rec(game, map_line) || !check_comp(game)
		|| !check_wall(game) || !check_path(game))
		return (false);
	put_enemy(game);
	return (true);
}

void	free_lines(char *line, char *map_line, char *trim)
{
	free(line);
	free(map_line);
	free(trim);
}
