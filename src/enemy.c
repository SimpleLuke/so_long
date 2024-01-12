/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:30:12 by llai              #+#    #+#             */
/*   Updated: 2024/01/12 14:36:05 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>
#include <stdlib.h>

void	put_enemy(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == '0' && rand() > (RAND_MAX / 100 * 99))
				game->map[i][j] = 'M';
		}
	}
}

bool	valid_enemy_move(char sym)
{
	return (sym != '1' && sym != 'C' && sym != 'E' && sym != 'P');
}

int	set_map(int i, int j, char **map_copy, char type)
{
	map_copy[i][j] = type;
	return (1);
}

enum e_direction	choose_direction(t_game *game,
	int i, int j, char **map_copy)
{
	int		r;
	char	sym;

	r = rand() % 5;
	sym = game->map[i - 1][j];
	if (r == UP && valid_enemy_move(sym) && map_copy[i - 1][j] != 'M'
		&& set_map(i, j, map_copy, '0') && set_map(i - 1, j, map_copy, 'M'))
		return (UP);
	sym = game->map[i + 1][j];
	if (r == DOWN && valid_enemy_move(sym) && map_copy[i + 1][j] != 'M'
		&& set_map(i, j, map_copy, '0') && set_map(i + 1, j, map_copy, 'M'))
		return (DOWN);
	sym = game->map[i][j - 1];
	if (r == LEFT && valid_enemy_move(sym) && map_copy[i][j - 1] != 'M'
		&& set_map(i, j, map_copy, '0') && set_map(i, j - 1, map_copy, 'M'))
		return (LEFT);
	sym = game->map[i][j + 1];
	if (r == RIGHT && valid_enemy_move(sym) && map_copy[i][j + 1] != 'M'
		&& set_map(i, j, map_copy, '0') && set_map(i, j + 1, map_copy, 'M'))
		return (RIGHT);
	if (r == STAY && set_map(i, j, map_copy, 'M'))
		return (STAY);
	return (choose_direction(game, i, j, map_copy));
}

void	map_to_map(char **src, char **dst, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			dst[i][j] = src[i][j];
	}
}

void	free_map_copy(char **map_copy, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->height)
		free(map_copy[i]);
	free(map_copy);
}

void	move_enemy(t_game *game)
{
	int		i;
	int		j;
	char	**map_copy;

	i = -1;
	map_copy = (char **)malloc(game->height * sizeof(char *));
	while (++i < game->height)
		map_copy[i] = (char *)malloc(game->width * sizeof(char));
	map_to_map(game->map, map_copy, game);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'M')
			{
				put_img_to_img(game->base_image,
					game->texture.space, j * 32, i * 32);
				choose_direction(game, i, j, map_copy);
			}
		}
	}
	map_to_map(map_copy, game->map, game);
	free_map_copy(map_copy, game);
}
