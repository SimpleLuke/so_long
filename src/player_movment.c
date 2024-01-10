/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:55:50 by llai              #+#    #+#             */
/*   Updated: 2024/01/10 19:43:39 by llai             ###   ########.fr       */
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

bool	is_end_game(t_game *game)
{
	ft_printf("X: %d, %d\n", game->player.location.x, game->end_exit.x);
	ft_printf("Y: %d, %d\n", game->player.location.y, game->end_exit.y);
	ft_printf("P: %d, %d\n", game->comp.collectible, game->end_exit.points);
	if (game->player.location.x == game->end_exit.x && game->player.location.y == game->end_exit.y)
		if (game->comp.collectible == game->end_exit.points)
			return (true);
	return (false);
}

int	keystroke(int keycode, t_game *game)
{
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
	else if (current == 'C')
		render_sprite(game, '0', game->player.location.y, game->player.location.x);
	else
		render_sprite(game, '0', game->player.location.y, game->player.location.x);
		// mlx_put_image_to_window(game->mlx, game->win,
		// 	game->texture.space.img_ptr, game->player.location.x * 32,
		// 	game->player.location.y * 32);
}

void	move_player(t_game *game, enum e_direction dir)
{
	ft_printf("YOU HAVE MOVED %d STEPS\n", ++game->steps);
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
	move_enemy(game);
	mlx_put_image_to_window(game->base_image.win.mlx, game->base_image.win.win_ptr, game->base_image.img_ptr, 0, 0);
}
