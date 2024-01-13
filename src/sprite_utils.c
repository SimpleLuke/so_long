/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:44:13 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 17:24:49 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sprite_to_list(t_game *game, t_win win)
{
	t_sprite		sprite;
	t_sprite_slice	slice;

	slice = (t_sprite_slice){0, 0, 32, 32};
	sprite = new_sprite("ball", "assets/collectible-sheet.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 6, COLLECTIBLE)));
	free(sprite.name);
	free(sprite.file_path);
	mlx_destroy_image(game->base_image.win.mlx, sprite.sprite_img.img_ptr);
	// mlx_destroy_image(game->base_image.img_ptr, sprite.sprite_img.img_ptr);
	sprite = new_sprite("enemy_down", "assets/enemy_down.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 2, ENEMY_DOWN)));
	free(sprite.name);
	free(sprite.file_path);
	mlx_destroy_image(game->base_image.win.mlx, sprite.sprite_img.img_ptr);
	// mlx_destroy_image(game->base_image.img_ptr, sprite.sprite_img.img_ptr);
}

void	player_sprite_to_list(t_game *game, t_win win)
{
	t_sprite		sprite;
	t_sprite_slice	slice;

	slice = (t_sprite_slice){0, 0, 32, 32};
	sprite = new_sprite("player_down", "assets/player_down.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 4, PLAYER_DOWN)));
	free(sprite.name);
	free(sprite.file_path);
	mlx_destroy_image(game->base_image.win.mlx, sprite.sprite_img.img_ptr);
	sprite = new_sprite("player_up", "assets/player_up.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 4, PLAYER_UP)));
	free(sprite.name);
	free(sprite.file_path);
	mlx_destroy_image(game->base_image.win.mlx, sprite.sprite_img.img_ptr);
	sprite = new_sprite("player_left", "assets/player_left.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 2, PLAYER_LEFT)));
	free(sprite.name);
	free(sprite.file_path);
	mlx_destroy_image(game->base_image.win.mlx, sprite.sprite_img.img_ptr);
	// mlx_destroy_image(game->base_image.img_ptr, sprite.sprite_img.img_ptr);
	sprite = new_sprite("player_right", "assets/player_right.xpm", &win);
	ft_lstadd_back(&game->texture.sprites.animations,
		ft_lstnew(slice_sprite(sprite, slice, 2, PLAYER_RIGHT)));
	free(sprite.name);
	free(sprite.file_path);
	mlx_destroy_image(game->base_image.win.mlx, sprite.sprite_img.img_ptr);
	// mlx_destroy_image(game->base_image.img_ptr, sprite.sprite_img.img_ptr);
}
void	load_sprites(t_game *game)
{
	t_win	win;

	win = game->base_image.win;
	player_sprite_to_list(game, win);
	sprite_to_list(game, win);
}

