/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:55:50 by llai              #+#    #+#             */
/*   Updated: 2024/01/08 15:38:25 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>

int		keystroke(int keycode, t_game *game);
void	move_player(t_game *game, enum e_direction dir);
bool	is_wall(t_game *game, enum e_direction dir);
void	replace_ground(t_game *game);

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

int	keystroke(int keycode, t_game *game)
{
	if (keycode == 119 && !is_wall(game, UP))
		move_player(game, UP);
	else if (keycode == 115 && !is_wall(game, DOWN))
		move_player(game, DOWN);
	else if (keycode == 97 && !is_wall(game, LEFT))
		move_player(game, LEFT);
	else if (keycode == 100 && !is_wall(game, RIGHT))
		move_player(game, RIGHT);
	return (0);
}

void	replace_ground(t_game *game)
{
	char	current;

	current = game->map[game->player.location.y][game->player.location.x];
	if (current == 'P')
		render_sprite(game, 'P', game->player.location.y, game->player.location.x);
		// mlx_put_image_to_window(game->mlx, game->win,
		// 	game->texture.player_start.img_ptr, game->player.location.x * 32,
		// 	game->player.location.y * 32);
	else if (current == 'E')
		render_sprite(game, 'E', game->player.location.y, game->player.location.x);
		// mlx_put_image_to_window(game->mlx, game->win,
		// 	game->texture.map_exit.img_ptr, game->player.location.x * 32,
		// 	game->player.location.y * 32);
	else
		render_sprite(game, '0', game->player.location.y, game->player.location.x);
		// mlx_put_image_to_window(game->mlx, game->win,
		// 	game->texture.space.img_ptr, game->player.location.x * 32,
		// 	game->player.location.y * 32);
}

void	move_player(t_game *game, enum e_direction dir)
{
	if (dir == UP)
	{
		replace_ground(game);
		move_up(game);
	}
	else if (dir == DOWN)
	{
		replace_ground(game);
		move_down(game);
	}
	else if (dir == LEFT)
	{
		replace_ground(game);
		move_left(game);
	}
	else if (dir == RIGHT)
	{
		replace_ground(game);
		move_right(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->base_image.img_ptr, 0, 0);
}
