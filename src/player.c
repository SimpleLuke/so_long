/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:25:56 by llai              #+#    #+#             */
/*   Updated: 2024/01/08 14:03:40 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player_image(t_game *game);

void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.sprite.img_ptr, game->player.location.x * 32,
		game->player.location.y * 32);
}

void	load_player_image(t_game *game)
{
	game->player.sprite = new_file_img("assets/player_still.xpm", game);
}
