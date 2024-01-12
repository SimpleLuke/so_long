/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:25:56 by llai              #+#    #+#             */
/*   Updated: 2024/01/12 17:00:45 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player_image(t_game *game);

void	render_player(t_game *game)
{
	put_img_to_img(game->base_image, game->player.sprite,
		game->player.location.x * 32, game->player.location.y * 32);
}

void	load_player_image(t_game *game)
{
	game->player.sprite = new_file_img("assets/player_still.xpm",
			game->base_image.win);
}
