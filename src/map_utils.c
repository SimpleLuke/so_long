/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:18:56 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 15:34:32 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

bool	check_rec(t_game *game, char *map_line);
bool	check_comp(t_game *game);
int		count_comp(t_game *game, int row, int col);
bool	check_wall(t_game *game);
int		convert_map(t_game *game, char *map_line);

int	convert_map(t_game *game, char *map_line)
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
	return (0);
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
			if ((i == 0 && game->map[i][j] != '1')
				|| (i == game->height - 1 && game->map[i][j] != '1'))
				return (false);
			if ((j == 0 && game->map[i][j] != '1')
				|| (j == game->width - 1 && game->map[i][j] != '1'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	count_comp(t_game *game, int row, int col)
{
	if (game->map[row][col] == '1')
		game->comp.wall++;
	else if (game->map[row][col] == '0')
		game->comp.space++;
	else if (game->map[row][col] == 'C')
		game->comp.collectible++;
	else if (game->map[row][col] == 'P')
		game->comp.player_start++;
	else if (game->map[row][col] == 'E')
		game->comp.map_exit++;
	else
		return (1);
	return (0);
}

bool	check_comp(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (count_comp(game, i, j))
				return (false);
		}
	}
	if (!game->comp.wall || !game->comp.space || !game->comp.collectible
		|| game->comp.map_exit != 1 || game->comp.player_start != 1)
	{
		ft_printf("Error: Invalid map componments\n");
		return (false);
	}
	return (true);
}

bool	check_rec(t_game *game, char *map_line)
{
	if (ft_strlen(map_line) % game->width || game->height < 2)
		return (false);
	return (true);
}
