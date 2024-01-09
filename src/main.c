/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/09 18:50:13 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_game	game;
	t_win	win;

	if (argc == 2)
	{
		init_game(&game);
		read_map(&game, argv[1]);
		game.base_image.win = new_window(game.width * 32, game.height * 32, "so_long");
		win = game.base_image.win;
		// game.mlx = mlx_init();
		// ft_printf("H:%d W:%d\n", game.height, game.width);
		// game.win = mlx_new_window
		// 	(game.mlx, game.width * 32, game.height * 32, "so_long");
		load_image(&game);
		render_image(&game);
		game.texture.collectible_sprite = new_sprite("ball", "assets/collectible-sheet.xpm", &win);
		// put_img_to_img(game.base_image, game.texture.collectible_sprite.sprite_img, 0, 0);
		// mlx_put_image_to_window(win.mlx, win.win_ptr, game.texture.collectible_sprite.sprite_img.img_ptr, 0, 0);
		// t_sprite s1 = game.texture.collectible_sprite;
		// if (!game.texture.collectible_sprite.sprite_img.img_ptr)
		// {
		// 	destory_sprite(game.texture.collectible_sprite);
		// }
		t_sprite_slice	slice1 = (t_sprite_slice){0, 0, 32, 32};
		ft_lstadd_back(&game.texture.collectible_sprite.animations, ft_lstnew(slice_sprite(game.texture.collectible_sprite, slice1, 6, 600, 0)));
		// t_list *list = game.texture.collectible_sprite.animations;
		ft_printf("Sprite %s [%d %d], loaded %d animations\n", game.texture.collectible_sprite.name, game.texture.collectible_sprite.width, game.texture.collectible_sprite.height, ft_lstsize(game.texture.collectible_sprite.animations));
		// ft_printf("check:%p\n", game.texture.collectible_sprite.animations->content);
		// t_list *list = ((t_animation *)game.texture.collectible_sprite.animations->content)->frames;
		// mlx_loop_hook(win.mlx, update, game.texture.collectible_sprite.animations);
		mlx_loop_hook(win.mlx, update, &game);
		mlx_hook(win.win_ptr, 2, 1L << 0, esc_close_win, &game);
		mlx_hook(win.win_ptr, 17, 0, destory_game, &game);
		mlx_key_hook(win.win_ptr, keystroke, &game);
		mlx_loop(game.base_image.win.mlx);
	}
	else
		ft_printf("Error\n");
	exit(EXIT_SUCCESS);
}
