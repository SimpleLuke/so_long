/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:09:08 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 15:46:58 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps rendering.
 *
 * ************************************************************************** */

#include "../includes/so_long.h"

void	load_image(t_game *game);
void	load_map_image(t_game *game);
void	load_player_image(t_game *game);
void	put_comp(t_game *game, int i, int j);

/* **************************************************************************
 * void	load_image(t_game *game)
 *
 * Summary of the function:
 * 
 * This function loads the map and player images.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	load_image(t_game *game)
{
	load_map_image(game);
	load_player_image(game);
}

/* **************************************************************************
 * void	load_map_image(t_game *game)
 *
 * Summary of the function:
 * 
 * This function loads the map tiles assets as image and store it in the 
 * game structure.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	load_map_image(t_game *game)
{
	game->texture.space = new_file_img("assets/space.xpm",
			game->base_image.win);
	game->texture.wall = new_file_img("assets/wall.xpm",
			game->base_image.win);
	game->texture.collectible = new_file_img("assets/collectible.xpm",
			game->base_image.win);
	game->texture.map_exit = new_file_img("assets/exit.xpm",
			game->base_image.win);
	game->texture.player_start = new_file_img("assets/start.xpm",
			game->base_image.win);
}

/* **************************************************************************
 * void	load_player_image(t_game *game)
 *
 * Summary of the function:
 * 
 * This function loads the player sprite assets as image and store it in the 
 * game structure.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	load_player_image(t_game *game)
{
	game->player.sprite = new_file_img("assets/player_still.xpm",
			game->base_image.win);
}

/* **************************************************************************
 * void	put_comp(t_game *game, int i, int j)
 *
 * Summary of the function:
 * 
 * This function renders sprite according the to map symbol.
 *
 * Parameters : A pointer to t_game and the x and y axis.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
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
