/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:52:58 by llai              #+#    #+#             */
/*   Updated: 2024/01/10 12:08:02 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	game->player.location.y -= 1;
	game->player.position = UP;
	// put_img_to_img(game->base_image, game->player.sprite, game->player.location.x * 32, game->player.location.y * 32);
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->player.sprite.img_ptr, game->player.location.x * 32,
	// 	game->player.location.y * 32);
}

void	move_down(t_game *game)
{
	game->player.location.y += 1;
	game->player.position = DOWN;
	// put_img_to_img(game->base_image, game->player.sprite, game->player.location.x * 32, game->player.location.y * 32);
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->player.sprite.img_ptr, game->player.location.x * 32,
	// 	game->player.location.y * 32);
}

void	move_left(t_game *game)
{
	game->player.location.x -= 1;
	game->player.position = LEFT;
	// put_img_to_img(game->base_image, game->player.sprite, game->player.location.x * 32, game->player.location.y * 32);
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->player.sprite.img_ptr, game->player.location.x * 32,
	// 	game->player.location.y * 32);
}

void	move_right(t_game *game)
{
	game->player.location.x += 1;
	game->player.position = RIGHT;
	// put_img_to_img(game->base_image, game->player.sprite, game->player.location.x * 32, game->player.location.y * 32);
	// mlx_put_image_to_window(game->mlx, game->win,
	// 	game->player.sprite.img_ptr, game->player.location.x * 32,
	// 	game->player.location.y * 32);
}
