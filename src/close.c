/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:10:30 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 20:18:26 by llai             ###   ########.fr       */
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
	mlx_destroy_image(game->base_image.win.mlx,
		game->texture.collectible.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx,
		game->texture.player_start.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->texture.map_exit.img_ptr);
	mlx_destroy_image(game->base_image.win.mlx, game->player.sprite.img_ptr);
}

void	free_gamemap(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->height)
		free(game->map[i]);
	free(game->map);
}

void	destroy_sprite_image(void *ptr)
{
	t_img	*img;

	img = (t_img *)ptr;
	if (img->img_ptr && img->win.mlx)
	{
		ft_printf("IN:CALLED\n");
		mlx_destroy_image(img->win.mlx, img->img_ptr);
	}
}

void	destroy_animation(void *ptr)
{
	t_animation	*a;

	a = (t_animation *)ptr;
	if (!a)
		return ;
	ft_printf("CALLED\n");
	// ft_lstiter(a->frames, destroy_sprite_image);
	// ft_lstclear(&a->frames, free);
	// printf("HERE:%zu\n", sizeof(a->frames->content));
	// free(a->frames->next->content);
	ft_printf("Frames destroyed: \n");
}

void	destroy_animation_list(t_game *game)
{
	ft_lstclear(&game->texture.sprites.animations, free);
}

int	destory_game(t_game *game)
{
	free_images(game);
	free_gamemap(game);
	// destroy_animation(&game->texture.sprites.animations);
	// destroy_animation_list(game);
	mlx_destroy_window(game->base_image.win.mlx, game->base_image.win.win_ptr);
	free(game->base_image.win.mlx);
	exit(EXIT_SUCCESS);
}

int	esc_close_win(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		// mlx_destroy_window(game->base_image.win.mlx,
		// 	game->base_image.win.win_ptr);
		destory_game(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	cross_close_win(t_game *vars)
{
	mlx_destroy_window(vars->base_image.win.mlx, vars->base_image.win.win_ptr);
	exit(EXIT_SUCCESS);
}
