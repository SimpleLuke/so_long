/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:09 by llai              #+#    #+#             */
/*   Updated: 2024/01/08 15:29:22 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../includes/image.h"
# include <stdbool.h>

# define ESC_KEY 0xff1b
# define HEIGHT 32
# define WIDTH 32

enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct s_plocation
{
	int	x;
	int	y;
}	t_plocation;

typedef struct s_player
{
	t_img		sprite;
	int			position;
	t_plocation	location;
}	t_player;

typedef struct s_texture
{
	int		width;
	int		height;
	t_img	space;
	t_img	wall;
	t_img	collectible;
	t_img	map_exit;
	t_img	player_start;
}	t_texture;

typedef struct s_comp
{
	int	space;
	int	wall;
	int	collectible;
	int	map_exit;
	int	player_start;
}	t_comp;

typedef struct s_game
{
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	char		**map;
	t_player	player;
	t_img		base_image;
	t_texture	texture;
	t_comp		comp;
}	t_game;

// Initialization
void	init_game(t_game *game);

// Custom put pixel
void	my_mlx_pixel_put(t_player *data, int x, int y, int color);

// Map 
char	*read_map(t_game *game, char *map);
bool	check_path(t_game *game);
bool	check_rec(t_game *game, char *map_line);
bool	check_comp(t_game *game);
bool	check_wall(t_game *game);
int		convert_map(t_game *game, char *map_line);

// Render
t_img	new_file_img(char *path, t_game *game);
t_img	new_img(int width, int height, t_game *game);
void	put_img_to_img(t_img dst, t_img src, int x, int y);
void	render_sprite(t_game *game, char type, int row, int col);
void	render_image(t_game *game);
void	load_image(t_game *game);
void	load_map_image(t_game *game);
void	render_player(t_game *game);
void	load_player_image(t_game *game);

// Draw shapes
// void	draw_circle(t_player *data, int center_x,
//	int center_y, int radius, int color);
// void	draw_square(t_player *data, int x,
//	int y, int size, int color);
// void	draw_grad_square(t_player *data, int x, int y, int size);
// void	generate_checked_texture(t_player *data, int width, int height);

// Color
// int	create_trgb(int t, int r, int g, int b);

// Window management
int		destory_game(t_game *game);
int		esc_close_win(int keycode, t_game *vars);
int		cross_close_win(t_game *vars);

// player
int		keystroke(int keycode, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

// Debug
int		print_error(char *msg);

#endif // !SO_LONG_H
