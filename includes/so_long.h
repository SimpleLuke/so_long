/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:09 by llai              #+#    #+#             */
/*   Updated: 2024/01/03 19:11:37 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

#define ESC_KEY 0xff1b

typedef struct s_vars {
    void    *mlx;
    void    *win;
}   t_vars;

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

// Custom put pixel
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Draw shapes
void draw_circle(t_data *data, int center_x, int center_y, int radius, int color);
void draw_square(t_data *data, int x, int y, int size, int color);
void draw_grad_square(t_data *data, int x, int y, int size);
void generate_checked_texture(t_data *data, int width, int height);

// Color
int create_trgb(int t, int r, int g, int b);

// Window management
int esc_close_win(int keycode, t_vars *vars);
int cross_close_win(t_vars *vars);
#endif // !SO_LONG_H
