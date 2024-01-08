/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/08 21:33:34 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_game(&game);
		read_map(&game, argv[1]);
		game.mlx = mlx_init();
		ft_printf("H:%d W:%d\n", game.height, game.width);
		game.win = mlx_new_window
			(game.mlx, game.width * 32, game.height * 32, "so_long");
		mlx_hook(game.win, 2, 1L << 0, esc_close_win, &game);
		mlx_hook(game.win, 17, 0, destory_game, &game);
		mlx_key_hook(game.win, keystroke, &game);
		load_image(&game);
		game.texture.collectible_sprite = new_sprite("ball", "assets/collectible-sheet.xpm", &game);
		// mlx_put_image_to_window(game.mlx, game.win, game.texture.collectible_sprite.sprite_img.img_ptr, 0, 0);
		// t_sprite s1 = game.texture.collectible_sprite;
		if (!game.texture.collectible_sprite.sprite_img.img_ptr)
		{
			destory_sprite(game.texture.collectible_sprite);
		}
		t_sprite_slice	slice1 = (t_sprite_slice){0, 0, 32, 32};
		ft_lstadd_back(&game.texture.collectible_sprite.animations, ft_lstnew(slice_sprite(game.texture.collectible_sprite, slice1, 6, 600, 0, &game)));
		ft_printf("Sprite %s [%d %d], loaded %d animations\n", game.texture.collectible_sprite.name, game.texture.collectible_sprite.width, game.texture.collectible_sprite.height, ft_lstsize(game.texture.collectible_sprite.animations));
		// t_animation *list = (t_animation *)game.texture.collectible_sprite.animations->content;
		ft_printf("check:%p\n", game.texture.collectible_sprite.animations->content);
		mlx_loop_hook(game.mlx, update, game.texture.collectible_sprite.animations);
		// render_image(&game);
		mlx_loop(game.mlx);
	}
	else
		ft_printf("Error\n");
	exit(EXIT_SUCCESS);
}
