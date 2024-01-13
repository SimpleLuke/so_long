/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:24:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 20:38:01 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which renders map, player and sprite into
 *  	mlx images to the window.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

void	render_image(t_game *game);
void	render_map(t_game *game);
void	render_player(t_game *game);
void	render_sprite(t_game *game, char type, int row, int col);

/* **************************************************************************
 * void	render_image(t_game *game)
 *
 * Summary of the function:
 * 
 * This function creates a base image as canvas. Then, it renders the 
 * map and player on the canvas. Finally, it puts the image to 
 * window.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_image(t_game *game)
{
	game->base_image = new_img(game->width * 32,
			game->height * 32, game->base_image.win);
	render_map(game);
	render_player(game);
	mlx_put_image_to_window(game->base_image.win.mlx,
		game->base_image.win.win_ptr, game->base_image.img_ptr, 0, 0);
}

/* **************************************************************************
 * void	render_map(t_game *game)
 *
 * Summary of the function:
 * 
 * This function puts the respective map tiles on the base image.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			put_comp(game, i, j);
	}
}

/* **************************************************************************
 * void	render_player(t_game *game)
 *
 * Summary of the function:
 * 
 * This function puts the player sprite on the base image based on 
 * the map symbol.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_player(t_game *game)
{
	put_img_to_img(game->base_image, game->player.sprite,
		game->player.location.x * 32, game->player.location.y * 32);
}

/* **************************************************************************
 * void	render_sprite(t_game *game, char type, int row, int col)
 *
 * Summary of the function:
 * 
 * This function puts the sprite image based on the type and location
 * to the base image.
 *
 * Parameters : A pointer to t_game, type character and row & col index.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_sprite(t_game *game, char type, int row, int col)
{
	if (type == '1')
		put_img_to_img(game->base_image, game->texture.wall,
			col * 32, row * 32);
	if (type == '0')
		put_img_to_img(game->base_image, game->texture.space,
			col * 32, row * 32);
	if (type == 'C')
		put_img_to_img(game->base_image, game->texture.collectible,
			col * 32, row * 32);
	if (type == 'P')
		put_img_to_img(game->base_image, game->texture.player_start,
			col * 32, row * 32);
	if (type == 'E')
		put_img_to_img(game->base_image, game->texture.map_exit,
			col * 32, row * 32);
	if (type == 'M')
		put_img_to_img(game->base_image, game->texture.space,
			col * 32, row * 32);
}
