/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:26:22 by llai              #+#    #+#             */
/*   Updated: 2024/01/12 17:34:25 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
