/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:52:58 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 14:26:33 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps to move player to a new positon.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

/* **************************************************************************
 * void	move_up(t_game *game)
 *
 * Summary of the function:
 * 
 * This function moves the player 1 tile up and updates the facing to up.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	move_up(t_game *game)
{
	game->player.location.y -= 1;
	game->player.position = UP;
}

/* **************************************************************************
 * void	move_down(t_game *game)
 *
 * Summary of the function:
 * 
 * This function moves the player 1 tile down and updates the facing to down.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	move_down(t_game *game)
{
	game->player.location.y += 1;
	game->player.position = DOWN;
}

/* **************************************************************************
 * void	move_left(t_game *game)
 *
 * Summary of the function:
 * 
 * This function moves the player 1 tile left and updates the facing to left.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	move_left(t_game *game)
{
	game->player.location.x -= 1;
	game->player.position = LEFT;
}

/* **************************************************************************
 * void	move_right(t_game *game)
 *
 * Summary of the function:
 * 
 * This function moves the player 1 tile right and updates the facing to right.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	move_right(t_game *game)
{
	game->player.location.x += 1;
	game->player.position = RIGHT;
}
