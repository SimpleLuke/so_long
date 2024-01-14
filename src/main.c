/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 13:35:07 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This program contains code which generate a game from a map files.
 *  	The game requires the player to dogde enemies and gather
 *  	collectibles. The player wins by arriving the exit safely with
 *  	all the collectibles. The player loses when they are attacked
 *  	by the enemies.
 *  	The use of steps will be displayed.
 *  	Any error will be displayed and program will exit.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_win	win;

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
		mlx_hook(win.win_ptr, 17, 0, destroy_game, &game);
		mlx_key_hook(win.win_ptr, keystroke, &game);
		mlx_loop_hook(win.mlx, update, &game);
		mlx_loop(game.base_image.win.mlx);
	}
	else
		print_error("Error\nPlease run the program with one map file.");
	exit(EXIT_SUCCESS);
}
