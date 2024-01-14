/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:02:54 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 15:41:27 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps to organise the game utils logic.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

/* **************************************************************************
 * bool	is_end_game(t_game *game)
 *
 * Summary of the function:
 * 
 * This function checks if the player finished the game, which is arriving
 * the exit with all the collectibles.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_end_game(t_game *game)
{
	if (game->player.location.x == game->end_exit.x
		&& game->player.location.y == game->end_exit.y)
		if (game->comp.collectible == game->end_exit.points)
			return (true);
	return (false);
}
