/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:24:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 20:48:53 by llai             ###   ########.fr       */
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
	render_map(game);
	render_player(game);
}

void	load_image(t_game *game)
{
	load_map_image(game);
	load_player_image(game);
}

void	load_map_image(t_game *game)
{
	game->texture.space = mlx_xpm_file_to_image
		(game->mlx, "assets/pokemon_bg.xpm",
			&game->texture.width, &game->texture.height);
	if (game->texture.space == NULL)
		ft_printf("FAIL TO LOAD SPACE IMAGE\n");
	game->texture.wall = mlx_xpm_file_to_image
		(game->mlx, "assets/pokemon_tree.xpm",
			&game->texture.width, &game->texture.height);
	if (game->texture.wall == NULL)
		ft_printf("FAIL TO LOAD WALL IMAGE\n");
	game->texture.collectible = mlx_xpm_file_to_image
		(game->mlx, "assets/pokemon_collectible.xpm",
			&game->texture.width, &game->texture.height);
	if (game->texture.collectible == NULL)
		ft_printf("FAIL TO LOAD COLLECTIBLE IMAGE\n");
	game->texture.map_exit = mlx_xpm_file_to_image
		(game->mlx, "assets/pokemon_exit.xpm",
			&game->texture.width, &game->texture.height);
	if (game->texture.map_exit == NULL)
		ft_printf("FAIL TO LOAD EXIT IMAGE\n");
	game->texture.player_start = mlx_xpm_file_to_image
		(game->mlx, "assets/pokemon_start.xpm",
			&game->texture.width, &game->texture.height);
	if (game->texture.player_start == NULL)
		ft_printf("FAIL TO LOAD START IMAGE\n");
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
				render_sprite(game, 'C', i, j);
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
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.wall, col * 32, row * 32);
	if (type == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.space, col * 32, row * 32);
	if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.collectible, col * 32, row * 32);
	if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.player_start, col * 32, row * 32);
	if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.map_exit, col * 32, row * 32);
}
