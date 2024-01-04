/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:55:50 by llai              #+#    #+#             */
/*   Updated: 2024/01/04 17:25:59 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void    move_player(t_game *game, int width, int height)
// {
//     t_player    player;
//
//      draw_square(&player, 1, 1, 100, 0x00FF0000);
//      mlx_put_image_to_window(game->mlx, game->win, player.img, width, height);
// }
//
// int render_next_frame(t_game *game)
// {
//     t_player    player;
//
//     player = game->player;
//     (void)player;
//     move_player(game, player.width, player.height);
//     return (0);
// }
//
// void move_top(t_game *game, int width, int height)
// {
//     t_player    player;
//
//     player = game->player;
//     player.height += height;
//     player.width += width;
//     move_player(game, player.width, player.height);
// }
//
// void    update_player_position(t_game *game, int keycode)
// {
// 	if (keycode == 115)
// 		move_top(game, 50, 50);
	// else if (key == 119 && game->map[j - 1][i] != '1')
	// 	move_down(game, i, j);
	// else if (key == 97 && game->map[j][i - 1] != '1')
	// 	move_left(game, i, j);
	// else if (key == 100 && game->map[j][i + 1] != '1')
	// 	move_right(game, i, j);
// }
//
// int	key_hook(int keycode, t_game *game)
// {
// 	if (keycode == 119 || keycode == 115
// 	|| keycode == 100 || keycode == 97)
// 		update_player_position(game, keycode);
// 	return (0);
// }
