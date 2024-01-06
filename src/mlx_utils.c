/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:54:38 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 19:39:23 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    my_mlx_pixel_put(t_player *player, int x, int y, int color)
{
	(void)player;
	(void)x;
	(void)y;
	(void)color;
    // char    *dst;
    //
    // dst = player->addr + (y * player->line_length + x * (player->bits_per_pixel / 8));
    // *(unsigned int*)dst = color;
}
