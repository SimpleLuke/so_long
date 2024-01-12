/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:52:58 by llai              #+#    #+#             */
/*   Updated: 2024/01/12 12:04:01 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	game->player.location.y -= 1;
	game->player.position = UP;
}

void	move_down(t_game *game)
{
	game->player.location.y += 1;
	game->player.position = DOWN;
}

void	move_left(t_game *game)
{
	game->player.location.x -= 1;
	game->player.position = LEFT;
}

void	move_right(t_game *game)
{
	game->player.location.x += 1;
	game->player.position = RIGHT;
}
