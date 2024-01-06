/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:10:30 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 14:46:50 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_texture(t_game *game);
int		destory_game(t_game *game);
int		esc_close_win(int keycode, t_game *vars);
int		cross_close_win(t_game *vars);

void	free_texture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->texture.space);
}

int	destory_game(t_game *game)
{
	free_texture(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	esc_close_win(int keycode, t_game *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	cross_close_win(t_game *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}
