/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:02:54 by llai              #+#    #+#             */
/*   Updated: 2024/01/12 17:03:19 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_end_game(t_game *game)
{
	if (game->player.location.x == game->end_exit.x
		&& game->player.location.y == game->end_exit.y)
		if (game->comp.collectible == game->end_exit.points)
			return (true);
	return (false);
}
