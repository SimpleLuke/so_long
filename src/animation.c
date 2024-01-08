/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:47:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/08 20:53:06 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update(t_list *list)
{
	if (!list)
		return (1);
	ft_lstiter(list, update_animation);
	return (0);
}

void	update_animation(void *ptr)
{
	t_game		*game;
	t_animation	*a;
	t_img		*img;

	game = (t_game *)ptr;
	a = (t_animation *)game->animation;
	if (!a)
		return ;
	if (a->_tmp_delay++ == a->delay)
	{
		a->_tmp_delay = 0;
		a->current_frame_num++;
		a->current_frame_num %= ft_lstsize(a->frames);
		img = (t_img *)ft_lstget(a->frames, a->current_frame_num);
		// put_img_to_img(game->base_image, *img, 0, 0);
		// mlx_put_image_to_window(game->mlx, game->win, game->base_image.img_ptr, 0, 0);
		mlx_put_image_to_window(game->mlx, game->win, img->img_ptr, 0, 0);
	}
}
