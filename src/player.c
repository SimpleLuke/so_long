/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:25:56 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 21:01:31 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player_image(t_game *game);

void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.sprite, game->player.location.x * 32,
		game->player.location.y * 32);
}

void	load_player_image(t_game *game)
{
	game->player.sprite = mlx_xpm_file_to_image
		(game->mlx, "assets/pokemon_p.xpm",
			&game->texture.width, &game->texture.height);
	if (game->player.sprite == NULL)
		ft_printf("FAIL TO LOAD PLAYER IMAGE\n");
}
