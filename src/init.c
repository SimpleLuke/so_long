/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:13:22 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 14:20:48 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which initialise the game for set up.
 *  	It helps to set up the game structure and the window configuration.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

void	init_game(t_game *game);
t_win	new_window(int w, int h, char *str);

/* **************************************************************************
 * void	init_game(t_game *game)
 *
 * Summary of the function:
 * 
 * 	This function initialises the game structure and set up the random seed.
 *
 * Parameters : A pointer to a t_game type.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	init_game(t_game *game)
{
	srand(time(NULL));
	game->steps = 0;
	game->width = 0;
	game->height = 0;
	game->comp.space = 0;
	game->comp.wall = 0;
	game->comp.collectible = 0;
	game->comp.map_exit = 0;
	game->comp.player_start = 0;
	game->player.position = DOWN;
	game->texture.sprites.animations = NULL;
}

/* **************************************************************************
 * t_win	new_window(int w, int h, char *str)
 *
 * Summary of the function:
 * 
 * 	This function initialises the mlx pointer and the window pointer.
 *
 * Parameters : The width and height of the window and a string for The
 *				window name.
 *
 * Return Value : It returns a t_win struct.
 * **************************************************************************/
t_win	new_window(int w, int h, char *str)
{
	void	*mlx;

	mlx = mlx_init();
	return ((t_win){mlx, mlx_new_window(mlx, w, h, str), w, h});
}
