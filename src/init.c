/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:13:22 by llai              #+#    #+#             */
/*   Updated: 2024/01/10 17:24:17 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->steps = 0;
	game->width = 0;
	game->height = 0;
	game->comp.space = 0;
	game->comp.wall = 0;
	game->comp.collectible = 0;
	game->comp.map_exit = 0;
	game->comp.player_start = 0;
	game->player.position = DOWN;
}

t_win	new_window(int w, int h, char *str)
{
	void	*mlx;

	mlx = mlx_init();
	return ((t_win){mlx, mlx_new_window(mlx, w, h, str), w, h});
}
