/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 21:01:14 by llai             ###   ########.fr       */
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
		render_image(&game);
		mlx_loop(game.mlx);
	}
	else
		ft_printf("Error\n");
	exit(EXIT_SUCCESS);
}
