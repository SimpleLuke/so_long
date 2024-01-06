/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:13:22 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 13:15:16 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->comp.space = 0;
	game->comp.wall = 0;
	game->comp.collectible = 0;
	game->comp.map_exit = 0;
	game->comp.player_start = 0;
}
