/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:47:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/12 17:32:04 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdint.h>

int	update(t_game *game)
{
	static uint64_t	updated_at = 0;
	t_list			*list;

	if ((timestamp_in_ms() - updated_at) < (uint64_t)(1000 / FPS))
		return (0);
	updated_at = timestamp_in_ms();
	list = game->texture.collectible_sprite.animations;
	if (!list)
		return (-1);
	if (game->map[game->player.location.y][game->player.location.x] == 'M'
		&& !game->end_exit.is_end)
	{
		ft_printf("YOU LOSE\n");
		game->end_exit.is_end = true;
	}
	ft_lstiter_param(list, update_animation, game);
	put_steps_on_screen(game);
	return (0);
}

void	render_enemy_sprite(t_game *game, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'M')
			{
				put_img_to_img(game->base_image,
					game->texture.space, j * 32, i * 32);
				put_img_to_img(game->base_image, *img, j * 32, i * 32);
			}
		}
	}
}

void	render_space_sprite(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == '0' && i != game->player.location.y
				&& j != game->player.location.x)
				put_img_to_img(game->base_image, game->texture.space,
					j * 32, i * 32);
		}
	}
}

void	render_player_sprite(t_game *game, t_img *img)
{
	int	x;
	int	y;

	x = game->player.location.x;
	y = game->player.location.y;
	put_img_to_img(game->base_image, game->texture.space, x * 32, y * 32);
	put_img_to_img(game->base_image, *img, x * 32, y * 32);
}

void	update_animation(void *list_p, void *game_p)
{
	t_game		*game;
	t_animation	*a;
	t_img		*img;
	t_list		*list;

	game = (t_game *)game_p;
	a = (t_animation *)list_p;
	if (!a)
		return ;
	a->current_frame_num++;
	a->current_frame_num %= ft_lstsize(a->frames);
	list = ft_lstget(a->frames, a->current_frame_num);
	img = (t_img *)list->content;
	check_enetity(a, game, img);
	mlx_put_image_to_window(img->win.mlx, img->win.win_ptr,
		game->base_image.img_ptr, 0, 0);
}
