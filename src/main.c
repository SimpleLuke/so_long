/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/11 15:47:00 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include <stdlib.h>
#include <time.h>

int	main(int argc, char **argv)
{
	t_game	game;
	t_win	win;

	srand(time(NULL));
	if (argc == 2)
	{
		init_game(&game);
		read_map(&game, argv[1]);
		game.base_image.win = new_window(game.width * 32, game.height * 32, "so_long");
		win = game.base_image.win;
	mlx_string_put(game.base_image.win.mlx, game.base_image.win.win_ptr, (0) * 32, (game.height) * 32, create_trgb(0, 255, 255, 255), "STEPS: 0");
	// mlx_string_put(game.base_image.win.mlx, game.base_image.win.win_ptr, (0) * 32, (game.height) * 32, create_trgb(0, 255, 255, 255), "STEPS: 1");
		load_image(&game);
		render_image(&game);
		t_sprite s1 = new_sprite("ball", "assets/collectible-sheet.xpm", &win);
		t_sprite s2 = new_sprite("player_down", "assets/player_down.xpm", &win);
		t_sprite s3 = new_sprite("player_up", "assets/player_up.xpm", &win);
		t_sprite s4 = new_sprite("player_left", "assets/player_left.xpm", &win);
		t_sprite s5 = new_sprite("player_right", "assets/player_right.xpm", &win);
		t_sprite s6 = new_sprite("enemy_down", "assets/enemy_down.xpm", &win);
		// // if (!game.texture.collectible_sprite.sprite_img.img_ptr)
		// // {
		// // 	destory_sprite(game.texture.collectible_sprite);
		// // }
		t_sprite_slice	slice1 = (t_sprite_slice){0, 0, 32, 32};
		ft_lstadd_back(&game.texture.collectible_sprite.animations, ft_lstnew(slice_sprite(s1, slice1, 6, 0, COLLECTIBLE)));
		ft_lstadd_back(&game.texture.collectible_sprite.animations, ft_lstnew(slice_sprite(s2, slice1, 4, 0, PLAYER_DOWN)));
		ft_lstadd_back(&game.texture.collectible_sprite.animations, ft_lstnew(slice_sprite(s3, slice1, 4, 0, PLAYER_UP)));
		ft_lstadd_back(&game.texture.collectible_sprite.animations, ft_lstnew(slice_sprite(s4, slice1, 2, 0, PLAYER_LEFT)));
		ft_lstadd_back(&game.texture.collectible_sprite.animations, ft_lstnew(slice_sprite(s5, slice1, 2, 0, PLAYER_RIGHT)));
		ft_lstadd_back(&game.texture.collectible_sprite.animations, ft_lstnew(slice_sprite(s6, slice1, 2, 0, ENEMY_DOWN)));
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
