/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/12 16:43:19 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include <stdlib.h>
#include <time.h>

void	sprite_to_list(t_game *game, t_win win)
{
	t_sprite		sprite;
	t_sprite_slice	slice;

	slice = (t_sprite_slice){0, 0, 32, 32};
	sprite = new_sprite("ball", "assets/collectible-sheet.xpm", &win);
	ft_lstadd_back(&game->texture.collectible_sprite.animations,
		ft_lstnew(slice_sprite(sprite, slice, 6, COLLECTIBLE)));
	sprite = new_sprite("player_down", "assets/player_down.xpm", &win);
	ft_lstadd_back(&game->texture.collectible_sprite.animations,
		ft_lstnew(slice_sprite(sprite, slice, 4, PLAYER_DOWN)));
	sprite = new_sprite("player_up", "assets/player_up.xpm", &win);
	ft_lstadd_back(&game->texture.collectible_sprite.animations,
		ft_lstnew(slice_sprite(sprite, slice, 4, PLAYER_UP)));
	sprite = new_sprite("player_left", "assets/player_left.xpm", &win);
	ft_lstadd_back(&game->texture.collectible_sprite.animations,
		ft_lstnew(slice_sprite(sprite, slice, 2, PLAYER_LEFT)));
	sprite = new_sprite("player_right", "assets/player_right.xpm", &win);
	ft_lstadd_back(&game->texture.collectible_sprite.animations,
		ft_lstnew(slice_sprite(sprite, slice, 2, PLAYER_RIGHT)));
	sprite = new_sprite("enemy_down", "assets/enemy_down.xpm", &win);
	ft_lstadd_back(&game->texture.collectible_sprite.animations,
		ft_lstnew(slice_sprite(sprite, slice, 2, ENEMY_DOWN)));
}

void	load_sprites(t_game *game)
{
	t_win	win;

	win = game->base_image.win;
	sprite_to_list(game, win);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_win	win;

	srand(time(NULL));
	if (argc == 2)
	{
		init_game(&game);
		read_map(&game, argv[1]);
		game.base_image.win = new_window(game.width * 32,
				game.height * 32, "so_long");
		win = game.base_image.win;
		load_image(&game);
		render_image(&game);
		load_sprites(&game);
		mlx_hook(win.win_ptr, 2, 1L << 0, esc_close_win, &game);
		mlx_hook(win.win_ptr, 17, 0, destory_game, &game);
		mlx_key_hook(win.win_ptr, keystroke, &game);
		mlx_loop_hook(win.mlx, update, &game);
		mlx_loop(game.base_image.win.mlx);
	}
	else
		ft_printf("Error\n");
	exit(EXIT_SUCCESS);
}
