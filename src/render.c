/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:24:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/09 12:10:45 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_map(t_game *game);
void	load_map_image(t_game *game);
void	render_map(t_game *game);
void	render_sprite(t_game *game, char type, int row, int col);
void	load_image(t_game *game);

void	render_image(t_game *game)
{
	game->base_image = new_img(game->width * 32, game->height * 32, game->base_image.win);
	render_map(game);
	render_player(game);
	mlx_put_image_to_window(game->base_image.win.mlx, game->base_image.win.win_ptr, game->base_image.img_ptr, 0, 0);
}

void	load_image(t_game *game)
{
	load_map_image(game);
	load_player_image(game);
}

void	load_map_image(t_game *game)
{
	game->texture.space = new_file_img("assets/space.xpm", game->base_image.win);
	game->texture.wall = new_file_img("assets/wall.xpm", game->base_image.win);
	game->texture.collectible = new_file_img("assets/collectible.xpm", game->base_image.win);
	game->texture.map_exit = new_file_img("assets/exit.xpm", game->base_image.win);
	game->texture.player_start = new_file_img("assets/start.xpm", game->base_image.win);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == '1')
				render_sprite(game, '1', i, j);
			else if (game->map[i][j] == '0')
				render_sprite(game, '0', i, j);
			else if (game->map[i][j] == 'C')
				render_sprite(game, '0', i, j);
			else if (game->map[i][j] == 'P')
			{
				render_sprite(game, 'P', i, j);
				game->player.location.x = j;
				game->player.location.y = i;
			}
			else if (game->map[i][j] == 'E')
				render_sprite(game, 'E', i, j);
		}
	}
}

void	render_sprite(t_game *game, char type, int row, int col)
{
	if (type == '1')
		put_img_to_img(game->base_image, game->texture.wall, col * 32, row * 32);
	if (type == '0')
		put_img_to_img(game->base_image, game->texture.space, col * 32, row * 32);
	if (type == 'C')
		put_img_to_img(game->base_image, game->texture.collectible, col * 32, row * 32);
	if (type == 'P')
		put_img_to_img(game->base_image, game->texture.player_start, col * 32, row * 32);
	if (type == 'E')
		put_img_to_img(game->base_image, game->texture.map_exit, col * 32, row * 32);
}
