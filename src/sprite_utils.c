/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:44:13 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 13:06:41 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps loading the sprites to the 
 *  	program.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

void	load_sprites(t_game *game);
void	sprite_to_list(t_game *game, t_win win);
void	player_sprite_to_list(t_game *game, t_win win);
void	destroy_sprite(t_sprite *sprite, t_game *game);

/* **************************************************************************
 * void	load_sprites(t_game *game)
 *
 * Summary of the function:
 * 
 * This function loads the player and other sprites into the program.
 *
 * Parameters : A pointer to a t_game type.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	load_sprites(t_game *game)
{
	t_win	win;

	win = game->base_image.win;
	player_sprite_to_list(game, win);
	sprite_to_list(game, win);
}

/* **************************************************************************
 * void	sprite_to_list(t_game *game, t_win win)
 *
 * Summary of the function:
 * 
 * This function loads collectible and enemy sprites from xpm files.
 * And it adds them into the animations list.
 *
 * Parameters : A pointer to a t_game type and t_win type.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	sprite_to_list(t_game *game, t_win win)
{
	t_sprite		sprite;
	t_sprite_slice	slice;

	slice = (t_sprite_slice){0, 0, 32, 32};
	sprite = new_sprite("ball", "assets/collectible-sheet.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 6, COLLECTIBLE)));
	destroy_sprite(&sprite, game);
	sprite = new_sprite("enemy_down", "assets/enemy_down.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 2, ENEMY_DOWN)));
	destroy_sprite(&sprite, game);
}

/* **************************************************************************
 * void	player_sprite_to_list(t_game *game, t_win win)
 *
 * Summary of the function:
 * 
 * This function loads the player sprites from xpm files.
 * And it adds them into the animations list.
 *
 * Parameters : A pointer to a t_game type and t_win type.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	player_sprite_to_list(t_game *game, t_win win)
{
	t_sprite		sprite;
	t_sprite_slice	slice;

	slice = (t_sprite_slice){0, 0, 32, 32};
	sprite = new_sprite("player_down", "assets/player_down.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 4, PLAYER_DOWN)));
	destroy_sprite(&sprite, game);
	sprite = new_sprite("player_up", "assets/player_up.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 4, PLAYER_UP)));
	destroy_sprite(&sprite, game);
	sprite = new_sprite("player_left", "assets/player_left.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 2, PLAYER_LEFT)));
	destroy_sprite(&sprite, game);
	sprite = new_sprite("player_right", "assets/player_right.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 2, PLAYER_RIGHT)));
	destroy_sprite(&sprite, game);
}

/* **************************************************************************
 * void	destroy_sprite(t_sprite *sprite, t_game *game)
 *
 * Summary of the function:
 * 
 * This function frees and destorys the memory allocation of a sprite.
 *
 * Parameters : A pointer to a t_sprite and a t_game type.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	destroy_sprite(t_sprite *sprite, t_game *game)
{
	free(sprite->name);
	free(sprite->file_path);
	mlx_destroy_image(game->base_image.win.mlx, sprite->sprite_img.img_ptr);
}
