/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:10:30 by llai              #+#    #+#             */
/*   Updated: 2024/01/03 19:11:00 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int esc_close_win(int keycode, t_vars *vars)
{

    if (keycode == ESC_KEY)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(EXIT_SUCCESS);
    }
    return (0);
}

int cross_close_win(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(EXIT_SUCCESS);
}
