/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:55:50 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 14:16:59 by llai             ###   ########.fr       */
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
#include <stdbool.h>

int		keystroke(int keycode, t_game *game);
void	move_player(t_game *game, enum e_direction dir);
void	put_player(t_game *game, enum e_direction dir);
bool	is_wall(t_game *game, enum e_direction dir);
void	replace_ground(t_game *game);

/* **************************************************************************
 * int	keystroke(int keycode, t_game *game)
 *
 * Summary of the function:
 * 
 * This function moves the player depends on the keycode.
 * This function is retricted to run under FPS.
 *
 * Parameters : A keycode and pointer to t_game.
 *
 * Return Value : It returns 0 exit code.
 * **************************************************************************/
int	keystroke(int keycode, t_game *game)
{
	static uint64_t	updated_at = 0;

	if ((timestamp_in_ms() - updated_at) < (uint64_t)(1000 / FPS))
		return (0);
	updated_at = timestamp_in_ms();
	if (game->end_exit.is_end)
		return (0);
	if (keycode == 119 && !is_wall(game, UP))
		move_player(game, UP);
	else if (keycode == 115 && !is_wall(game, DOWN))
		move_player(game, DOWN);
	else if (keycode == 97 && !is_wall(game, LEFT))
		move_player(game, LEFT);
	else if (keycode == 100 && !is_wall(game, RIGHT))
		move_player(game, RIGHT);
	if (is_end_game(game))
	{
		ft_printf("YOU WIN!");
		game->end_exit.is_end = true;
	}
	return (0);
}

/* **************************************************************************
 * void	move_player(t_game *game, enum e_direction dir)
 *
 * Summary of the function:
 * 
 * This function runs servals steps when moving the player.
 * The steps is logged. Player image will be updated on the map.
 * If player ran into enemy, the game ends. Otherwise, enemies move.
 *
 * Parameters : A pointer to t_game and e_direction.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	move_player(t_game *game, enum e_direction dir)
{
	t_plocation	*plocation;

	plocation = &game->player.location;
	ft_printf("YOU HAVE MOVED %d STEPS\n", ++game->steps);
	put_player(game, dir);
	if (game->map[plocation->y][plocation->x] == 'M' && !game->end_exit.is_end)
	{
		mlx_put_image_to_window(game->base_image.win.mlx,
			game->base_image.win.win_ptr, game->base_image.img_ptr, 0, 0);
		return ;
	}
	move_enemy(game);
	mlx_put_image_to_window(game->base_image.win.mlx,
		game->base_image.win.win_ptr, game->base_image.img_ptr, 0, 0);
}

/* **************************************************************************
 * bool	is_wall(t_game *game, enum e_direction dir)
 *
 * Summary of the function:
 * 
 * This function checks if the direction is a wall on the map.
 *
 * Parameters : A pointer to t_game and e_direction.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_wall(t_game *game, enum e_direction dir)
{
	if (dir == UP && game->map
		[game->player.location.y - 1][game->player.location.x] == '1')
		return (true);
	else if (dir == DOWN && game->map
		[game->player.location.y + 1][game->player.location.x] == '1')
		return (true);
	else if (dir == LEFT && game->map
		[game->player.location.y][game->player.location.x - 1] == '1')
		return (true);
	else if (dir == RIGHT && game->map
		[game->player.location.y][game->player.location.x + 1] == '1')
		return (true);
	return (false);
}

/* **************************************************************************
 * void	put_player(t_game *game, enum e_direction dir)
 *
 * Summary of the function:
 * 
 * This function replaces the player current location sprite with a
 * sprite. Then it moves the player to a direction.
 *
 * Parameters : A pointer to t_game and e_direction.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	put_player(t_game *game, enum e_direction dir)
{
	replace_ground(game);
	if (dir == UP)
		move_up(game);
	else if (dir == DOWN)
		move_down(game);
	else if (dir == LEFT)
		move_left(game);
	else if (dir == RIGHT)
		move_right(game);
}

/* **************************************************************************
 * void	replace_ground(t_game *game)
 *
 * Summary of the function:
 * 
 * This function renders player current location with a sprite
 * depends on what was on the map.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	replace_ground(t_game *game)
{
	char		current;
	t_plocation	*plocation;

	plocation = &game->player.location;
	current = game->map[plocation->y][plocation->x];
	if (current == 'P')
		render_sprite(game, 'P', plocation->y, plocation->x);
	else if (current == 'E')
		render_sprite(game, 'E', plocation->y, plocation->x);
	else if (current == 'C')
		render_sprite(game, '0', plocation->y, plocation->x);
	else
		render_sprite(game, '0', plocation->y, plocation->x);
}
