/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:30:12 by llai              #+#    #+#             */
/*   Updated: 2024/01/11 12:42:28 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
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
			if (game->map[i][j] == '0' && rand() > (RAND_MAX / 100 * 80))
				game->map[i][j] = 'M';
		}
	}
}

enum e_direction	choose_direction(t_game *game, int i, int j, char **map_copy)
{
	int	r;

	r = rand() % 5;
	// ft_printf("HEY: %d %d\n", j, i);
	// ft_printf("P: %d %d\n", game->player.location.x, game->player.location.y);
	if (r == UP && game->map[i - 1][j] != '1' && game->map[i - 1][j] != 'C'
		&& game->map[i - 1][j] != 'E' && game->map[i - 1][j] != 'P' && map_copy[i - 1][j] != 'M')
	{
		// ft_printf("UP\n");
		map_copy[i][j] = '0';
		map_copy[i - 1][j] = 'M';
		return (UP);
	}
	if (r == DOWN && game->map[i + 1][j] != '1' && game->map[i + 1][j] != 'C' && game->map[i + 1][j] != 'E' && game->map[i + 1][j] != 'P' && map_copy[i + 1][j] != 'M')
	{
		// ft_printf("DOWN\n");
		map_copy[i][j] = '0';
		map_copy[i + 1][j] = 'M';
		return (DOWN);
	}
	if (r == LEFT && game->map[i][j - 1] != '1' && game->map[i][j - 1] != 'C' && game->map[i][j - 1] != 'E' && game->map[i][j - 1] != 'P' && map_copy[i][j - 1] != 'M')
	{
		// ft_printf("LEFT\n");
		map_copy[i][j] = '0';
		map_copy[i][j - 1] = 'M';
		return (LEFT);
	}
	if (r == RIGHT && game->map[i][j + 1] != '1' && game->map[i][j + 1] != 'C' && game->map[i][j + 1] != 'E' && game->map[i][j + 1] != 'P' && map_copy[i][j + 1] != 'M')
	{
		// ft_printf("RIGHT\n");
		map_copy[i][j] = '0';
		map_copy[i][j + 1] = 'M';
		return (RIGHT);
	}
	if (r == STAY)
	{
		map_copy[i][j] = 'M';
		return (STAY);
	}
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

void	move_enemy(t_game *game)
{
	int	i;
	int	j;
	enum e_direction	dir;
	char	**map_copy;

	(void)dir;
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
				put_img_to_img(game->base_image, game->texture.space, j * 32, i * 32);
				choose_direction(game, i , j, map_copy);
			}
		}
	}
	map_to_map(map_copy, game->map, game);
	i = -1;
				for (int i = 0; i < game->height; i++)
				{
					for (int j = 0; j < game->width; j++) {
						ft_printf("%c", map_copy[i][j]);
					}
					ft_printf("\n");
				}
	while (++i < game->height)
	{
		j = -1;
		free(map_copy[i]);
	}

	free(map_copy);
}
