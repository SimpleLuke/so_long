/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:09 by llai              #+#    #+#             */
/*   Updated: 2024/01/11 12:38:10 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "image.h"
# include "sprite.h"
# include "animation.h"
# include <stdbool.h>

# define ESC_KEY 0xff1b
# define HEIGHT 32
# define WIDTH 32

enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STAY
};

typedef struct s_win
{
	void	*mlx;
	void	*win_ptr;
	int		width;
	int		height;
}	t_win;

typedef struct s_plocation {
	int	x;
	int	y;
}	t_plocation;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_player
{
	t_img		sprite;
	enum e_direction	position;
	t_plocation	location;
}	t_player;

typedef struct s_sprite
{
	t_list	*animations;
	char	*name;
	char	*file_path;
	t_img	sprite_img;
	int		width;
	int		height;
	int		z_index;
}	t_sprite;

typedef struct s_texture
{
	int		width;
	int		height;
	t_img	space;
	t_img	wall;
	t_img	collectible;
	t_img	map_exit;
	t_img	player_start;
	t_sprite	collectible_sprite;
}	t_texture;

typedef struct s_comp
{
	int	space;
	int	wall;
	int	collectible;
	int	map_exit;
	int	player_start;
}	t_comp;

enum e_entity
{
	COLLECTIBLE,
	PLAYER_UP,
	PLAYER_DOWN,
	PLAYER_RIGHT,
	PLAYER_LEFT,
	ENEMY_DOWN
};

typedef struct s_enemy
{
	t_sprite			enemy_sprite;
	enum e_direction	position;
}	t_enemy;

typedef struct s_animation
{
	t_list			*frames;
	int				width;
	int				height;
	int				delay;
	int				_tmp_delay;
	int				current_frame_num;
	long int		last_updated;
	long int		frame_count;
	enum e_entity	entity;
}	t_animation;

typedef struct sprite_slice
{
	int	x;
	int	y;
	int	width;
	int	height;
} t_sprite_slice;

typedef struct s_exit
{
	int	x;
	int	y;
	int	points;
	bool	is_end;
}	t_exit;

typedef struct s_game
{
	int			width;
	int			height;
	int			steps;
	// void		*mlx;
	// void		*win;
	char		**map;
	t_player	player;
	t_enemy		enemy;
	t_img		base_image;
	t_texture	texture;
	t_comp		comp;
	t_animation	*animation;
	t_exit		end_exit;
}	t_game;

typedef struct s_animator
{
	t_list	*animations;
	t_game	*game;
	t_img	*img;
}	t_animator;

// Initialization
void	init_game(t_game *game);
t_win	new_window(int w, int h, char *str);

// Custom put pixel
void	my_mlx_pixel_put(t_player *data, int x, int y, int color);

// Map 
char	*read_map(t_game *game, char *map);
void	render_map(t_game *game);
bool	check_path(t_game *game);
bool	check_rec(t_game *game, char *map_line);
bool	check_comp(t_game *game);
bool	check_wall(t_game *game);
int		convert_map(t_game *game, char *map_line);

// Render
t_img	new_file_img(char *path, t_win window);
t_img	new_img(int width, int height, t_win window);
void	put_img_to_img(t_img dst, t_img src, int x, int y);
void	put_pixel_img(t_img img, int x, int y, int color);
unsigned int	get_pixel_img(t_img img, int x, int y);
void	render_sprite(t_game *game, char type, int row, int col);
void	render_image(t_game *game);
void	load_image(t_game *game);
void	load_map_image(t_game *game);
void	render_player(t_game *game);
void	load_player_image(t_game *game);

// Sprite
t_sprite	new_sprite(char *name, char *file_path, t_win *win);
t_animation	*slice_sprite(t_sprite s, t_sprite_slice slice, int frames, int delay, enum e_entity e);
void		destory_sprite(t_sprite s);

// Animation
int		update(t_game *game);
void	update_animation(void *list_p, void *game_p);
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

// Enemy
void	put_enemy(t_game *game);
void	move_enemy(t_game *game);

// Debug
int		print_error(char *msg);

#endif // !SO_LONG_H
