/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:47:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 14:52:47 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which updates with mlx_loop_hook. It helps
 *  	run sprite animations.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"
#include <stdint.h>

int		update(t_game *game);
void	update_animation(void *list_p, void *game_p);

/* **************************************************************************
 * int	update(t_game *game)
 *
 * Summary of the function:
 * 
 * This function iterates throught the animations list and update animations.
 * It updates the steps string on the screen. If the player ran into enemy,
 * it sets the is_end to true, so key control direction will be disabled.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns 0 exit code.
 * **************************************************************************/
int	update(t_game *game)
{
	static uint64_t	updated_at = 0;
	t_list			*list;

	if ((timestamp_in_ms() - updated_at) < (uint64_t)(1000 / FPS))
		return (0);
	updated_at = timestamp_in_ms();
	list = game->texture.sprites.animations;
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

/* **************************************************************************
 * void	update_animation(void *list_p, void *game_p)
 *
 * Summary of the function:
 * 
 * This function iterates throught the frames in the animations. Then, 
 * it runs the sprite depends on the enetity condition.
 *
 * Parameters : A two void pointers for t_animation and t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
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
