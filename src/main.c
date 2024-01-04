/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/04 19:28:53 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
    t_game  game;

    (void)argv;
    if (argc == 2)
    {
        read_map(&game, argv[1]);
        game.mlx = mlx_init();
        ft_printf("%d %d\n", game.height, game.width);
        game.win = mlx_new_window(game.mlx, game.width * 32, game.height * 32, "so_long");
        ft_printf("MAP: \n%s\n", game.map);
        mlx_hook(game.win, 2, 1L<<0, esc_close_win, &game);
        mlx_hook(game.win, 17, 0, destory_game, &game);
        load_image(&game);
        render_image(&game);
	    mlx_loop(game.mlx);
    }
    else 
        ft_printf("Error\n");
    exit(EXIT_SUCCESS);
    // game.player.img = mlx_new_image(game.mlx, 1920, 1080);
    // game.player.addr = mlx_get_data_addr(game.player.img, &game.player.bits_per_pixel, &game.player.line_length, &game.player.endian);
    // game.player.width = 0;
    // game.player.height = 0;
    // draw_square(&img, 300, 300, 500, 0x55FF0000);
    // draw_grad_square(&img, 800, 800, 100);
    // draw_circle(&img, 150, 150, 50, create_trgb(255, 0, 255, 0));
    // draw_circle(&img, 150, 150, 50, 0xFFFF0000);
    //generate_checked_texture(&img, 500, 500);
    // mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    // game.texture.width = 32;
    // game.texture.height = 32;
    // game.texture.ground = mlx_xpm_file_to_image(game.mlx, "../assets/pokemon_bg.bmp", &game.texture.width, &game.texture.height);
    // ft_printf("HERE:%p\n",game.texture.ground);
    // mlx_put_image_to_window(game.mlx, game.win, &(game.texture.ground), 1, 1);
    //mlx_put_image_to_window(game.mlx, game.win, &img, 0, 0);
}
