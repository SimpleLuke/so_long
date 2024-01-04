/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:54:38 by llai              #+#    #+#             */
/*   Updated: 2024/01/04 11:55:14 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    my_mlx_pixel_put(t_player *player, int x, int y, int color)
{
    char    *dst;

    dst = player->addr + (y * player->line_length + x * (player->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
