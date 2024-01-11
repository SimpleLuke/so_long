/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:47:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/11 16:05:48 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdint.h>

uint64_t	timestamp_in_ms(void);
uint64_t	updated_at = 0;

int			fps = 16;

int	update(t_game *game)
{
	t_list	*list;

	// ft_printf("timestamp: %d\t update: %d\n", timestamp_in_ms(), updated_at);
	// ft_printf("left: %d\t right: %d\n", timestamp_in_ms() - updated_at, 999 / fps);
	if ((timestamp_in_ms() - updated_at) < (uint64_t)(1000 / fps))
		return (0);
	// ft_printf("YES\n");
	updated_at = timestamp_in_ms();
	list = game->texture.collectible_sprite.animations;
	if (!list)
		return (-1);
	// ft_lstiter(list, update_animation);
	if (game->map[game->player.location.y][game->player.location.x] == 'M' && !game->end_exit.is_end)
	{
		ft_printf("YOU LOST\n");
		game->end_exit.is_end = true;
	}
	ft_lstiter_param(list, update_animation, game);
	put_steps_on_screen(game);
	return (0);
}

void	render_collectible_sprite(t_game *game, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	if (game->map[game->player.location.y][game->player.location.x] == 'C')
	{
		game->end_exit.points += 1;
		game->map[game->player.location.y][game->player.location.x] = '0';
	}
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
			{
				// render_sprite(game, '0', i * 32, j * 32);
				put_img_to_img(game->base_image, game->texture.space, j * 32, i * 32);
				put_img_to_img(game->base_image, *img, j * 32, i * 32);
			}
				// render_sprite(game, 'C', i, j);
		}
	}
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
				put_img_to_img(game->base_image, game->texture.space, j * 32, i * 32);
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
			if (game->map[i][j] == '0' && i != game->player.location.y && j != game->player.location.x)
				put_img_to_img(game->base_image, game->texture.space, j * 32, i * 32);
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
	// if (a->_tmp_delay++ == a->delay)
	// {
		// a->_tmp_delay = 0;
	a->current_frame_num++;
	a->current_frame_num %= ft_lstsize(a->frames);
		// a->current_frame_num %= 6;
	list = ft_lstget(a->frames, a->current_frame_num);
	img = (t_img *)list->content;
		// put_img_to_img(game->base_image, *img, -1, 0);
		// mlx_put_image_to_window(game->mlx, game->win, game->base_image.img_ptr, 0, 0);
		// ft_printf("CALL: %d\n", a->current_frame_num);
		// ft_printf("FRAMES: %d\n", ft_lstsize(a->frames));
		// mlx_put_image_to_window(img->win.mlx, img->win.win_ptr, img->img_ptr, 0, 0);
	// render_space_sprite(game);
	if (a->entity == COLLECTIBLE)
		render_collectible_sprite(game, img);
	else if (a->entity == PLAYER_DOWN && game->player.position == DOWN)
		render_player_sprite(game, img);
	else if (a->entity == PLAYER_UP && game->player.position == UP)
		render_player_sprite(game, img);
	else if (a->entity == PLAYER_LEFT && game->player.position == LEFT)
		render_player_sprite(game, img);
	else if (a->entity == PLAYER_RIGHT && game->player.position == RIGHT)
		render_player_sprite(game, img);
	else if (a->entity == ENEMY_DOWN)
		render_enemy_sprite(game, img);
		// put_img_to_img(game->base_image, *img, 0, 0);
	mlx_put_image_to_window(img->win.mlx, img->win.win_ptr, game->base_image.img_ptr, 0, 0);
	// }
}
