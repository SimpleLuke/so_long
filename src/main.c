/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:39 by llai              #+#    #+#             */
/*   Updated: 2024/01/03 19:12:44 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
#include <stdlib.h>

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	main(void)
{
    t_vars  vars;
    t_data  img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    // draw_square(&img, 300, 300, 500, 0x55FF0000);
    // draw_grad_square(&img, 800, 800, 100);
    // draw_circle(&img, 150, 150, 50, create_trgb(255, 0, 255, 0));
    // draw_circle(&img, 150, 150, 50, 0xFFFF0000);
    //generate_checked_texture(&img, 500, 500);
    //mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, esc_close_win, &vars);
    mlx_hook(vars.win, 17, 0, cross_close_win, &vars);
	mlx_loop(vars.mlx);
}
