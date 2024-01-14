/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:26:22 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 15:01:49 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps to render the aniamtions.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

void	check_enetity(t_animation *a, t_game *game, t_img *img);
void	render_enemy_sprite(t_game *game, t_img *img);
void	render_space_sprite(t_game *game);
void	render_collectible_sprite(t_game *game, t_img *img);
void	render_player_sprite(t_game *game, t_img *img);

/* **************************************************************************
 * void	check_enetity(t_animation *a, t_game *game, t_img *img)
 *
 * Summary of the function:
 * 
 * This function checks if the entity type matches the render condition.
 *
 * Parameters : A pointer to t_animation, t_game and t_img.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	check_enetity(t_animation *a, t_game *game, t_img *img)
{
	if (a->entity == COLLECTIBLE)
		render_collectible_sprite(game, img);
	else if (a->entity == PLAYER_DOWN && game->player.position == DOWN)
		render_player_sprite(game, img);
	else if (a->entity == PLAYER_UP && game->player.position == UP)
		render_player_sprite(game, img);
	else if (a->entity == PLAYER_LEFT && game->player.position == LEFT)
		render_player_sprite(game, img);
	else if (a->entity == PLAYER_RIGHT && game->player.position == RIGHT)
		render_player_sprite(game, img);
	else if (a->entity == ENEMY_DOWN)
		render_enemy_sprite(game, img);
}

/* **************************************************************************
 * void	render_collectible_sprite(t_game *game, t_img *img)
 *
 * Summary of the function:
 * 
 * This function updates collectible points and reset map to space 
 * when player steps on collectibles.
 * Then, it renders the collectible sprites based on the map.
 *
 * Parameters : A pointer to t_game and t_img.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_collectible_sprite(t_game *game, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	if (game->map[game->player.location.y][game->player.location.x] == 'C')
	{
		game->end_exit.points += 1;
		game->map[game->player.location.y][game->player.location.x] = '0';
	}
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
			{
				put_img_to_img(game->base_image,
					game->texture.space, j * 32, i * 32);
				put_img_to_img(game->base_image, *img, j * 32, i * 32);
			}
		}
	}
}

/* **************************************************************************
 * void	render_enemy_sprite(t_game *game, t_img *img)
 *
 * Summary of the function:
 * 
 * This function render enemy sprite on the map.
 *
 * Parameters : A pointer to t_game and t_img.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_enemy_sprite(t_game *game, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'M')
			{
				put_img_to_img(game->base_image,
					game->texture.space, j * 32, i * 32);
				put_img_to_img(game->base_image, *img, j * 32, i * 32);
			}
		}
	}
}

/* **************************************************************************
 * void	render_space_sprite(t_game *game)
 *
 * Summary of the function:
 * 
 * This function render space sprite on the map. It won't cover player 
 * current location.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_space_sprite(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == '0' && i != game->player.location.y
				&& j != game->player.location.x)
				put_img_to_img(game->base_image, game->texture.space,
					j * 32, i * 32);
		}
	}
}

/* **************************************************************************
 * void	render_player_sprite(t_game *game, t_img *img)
 *
 * Summary of the function:
 * 
 * This function renders player sprite on current location.
 *
 * Parameters : A pointer to t_game and t_img.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_player_sprite(t_game *game, t_img *img)
{
	int	x;
	int	y;

	x = game->player.location.x;
	y = game->player.location.y;
	put_img_to_img(game->base_image, game->texture.space, x * 32, y * 32);
	put_img_to_img(game->base_image, *img, x * 32, y * 32);
}
