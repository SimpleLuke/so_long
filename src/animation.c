/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:47:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/09 18:58:37 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update(t_game *game)
{
	t_list	*list;

	list = game->texture.collectible_sprite.animations;
	if (!list)
		return (1);
	// ft_lstiter(list, update_animation);
	ft_lstiter_param(list, update_animation, game);
	return (0);
}

void	render_collectible_sprite(t_game *game, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	if (game->map[game->player.location.y][game->player.location.x] == 'C')
		game->map[game->player.location.y][game->player.location.x] = '0';
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
				put_img_to_img(game->base_image, *img, j * 32, i * 32);
				// render_sprite(game, 'C', i, j);
		}
	}

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
	if (a->_tmp_delay++ == a->delay)
	{
		a->_tmp_delay = 0;
		a->current_frame_num++;
		a->current_frame_num %= ft_lstsize(a->frames);
		// a->current_frame_num %= 6;
		list = ft_lstget(a->frames, a->current_frame_num);
		img = (t_img *)list->content;
		// put_img_to_img(game->base_image, *img, 0, 0);
		// mlx_put_image_to_window(game->mlx, game->win, game->base_image.img_ptr, 0, 0);
		// ft_printf("CALL: %d\n", a->current_frame_num);
		// ft_printf("FRAMES: %d\n", ft_lstsize(a->frames));
		// mlx_put_image_to_window(img->win.mlx, img->win.win_ptr, img->img_ptr, 0, 0);
		render_collectible_sprite(game_p, img);
		// put_img_to_img(game->base_image, *img, 0, 0);
		mlx_put_image_to_window(img->win.mlx, img->win.win_ptr, game->base_image.img_ptr, 0, 0);
	}
}
