/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:10:30 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 15:46:40 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps to destroy the window and 
 *  	free crucial memory allocations.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

int		destroy_game(t_game *game);
int		esc_close_win(int keycode, t_game *vars);
int		cross_close_win(t_game *vars);
void	free_images(t_game *game);
void	free_gamemap(t_game *game);

/* **************************************************************************
 * int	destroy_game(t_game *game)
 *
 * Summary of the function:
 * 
 * This function frees up crucial memory allocations and exit successfully.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns 0 exit code.
 * **************************************************************************/
int	destroy_game(t_game *game)
{
	free_images(game);
	free_gamemap(game);
	mlx_destroy_window(game->base_image.win.mlx, game->base_image.win.win_ptr);
	free(game->base_image.win.mlx);
	exit(EXIT_SUCCESS);
}

/* **************************************************************************
 * int	esc_close_win(int keycode, t_game *game)
 *
 * Summary of the function:
 * 
 * This function calls destroy game and exit successfully when ESC_KEY
 * is clicked.
 *
 * Parameters : A keycode and pointer to t_game.
 *
 * Return Value : It returns 0 exit code.
 * **************************************************************************/
int	esc_close_win(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		destroy_game(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/* **************************************************************************
 * int	cross_close_win(t_game *game)
 *
 * Summary of the function:
 * 
 * This function calls destroy game and exit successfully when the cross 
 * is clicked.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns 0 exit code.
 * **************************************************************************/
int	cross_close_win(t_game *game)
{
	destroy_game(game);
	exit(EXIT_SUCCESS);
}

/* **************************************************************************
 * void	free_images(t_game *game)
 *
 * Summary of the function:
 * 
 * This function frees images used in the program.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	free_images(t_game *game)
{
	mlx_destroy_image(game->base_image.win.mlx, game->texture.space.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->texture.wall.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx,
		game->texture.collectible.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx,
		game->texture.player_start.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->texture.map_exit.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->player.sprite.img_ptr);
}

/* **************************************************************************
 * void	free_gamemap(t_game *game)
 *
 * Summary of the function:
 * 
 * This function frees the 2D char game map.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	free_gamemap(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->height)
		free(game->map[i]);
	free(game->map);
}
