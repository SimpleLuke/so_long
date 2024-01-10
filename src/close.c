/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:10:30 by llai              #+#    #+#             */
/*   Updated: 2024/01/10 12:33:39 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_game *game);
int		destory_game(t_game *game);
int		esc_close_win(int keycode, t_game *vars);
int		cross_close_win(t_game *vars);

void	free_images(t_game *game)
{
	mlx_destroy_image(game->base_image.win.mlx, game->texture.space.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->texture.wall.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->texture.collectible.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->texture.player_start.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->texture.map_exit.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->player.sprite.img_ptr);
}

int	destory_game(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->base_image.win.mlx, game->base_image.win.win_ptr);
	free(game->base_image.win.mlx);
	exit(EXIT_SUCCESS);
}

int	esc_close_win(int keycode, t_game *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->base_image.win.mlx, vars->base_image.win.win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	cross_close_win(t_game *vars)
{
	mlx_destroy_window(vars->base_image.win.mlx, vars->base_image.win.win_ptr);
	exit(EXIT_SUCCESS);
}
