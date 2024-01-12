/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:06:40 by llai              #+#    #+#             */
/*   Updated: 2024/01/12 17:25:50 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	put_comp(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		render_sprite(game, '1', i, j);
	else if (game->map[i][j] == '0')
		render_sprite(game, '0', i, j);
	else if (game->map[i][j] == 'C')
		render_sprite(game, '0', i, j);
	else if (game->map[i][j] == 'P')
	{
		render_sprite(game, 'P', i, j);
		game->player.location.x = j;
		game->player.location.y = i;
	}
	else if (game->map[i][j] == 'E')
		render_sprite(game, 'E', i, j);
	else if (game->map[i][j] == 'M')
		render_sprite(game, 'M', i, j);
}
