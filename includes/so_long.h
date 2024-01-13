/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:09 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 13:45:27 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "image.h"
# include "sprite.h"
# include "animation.h"
# include "comp.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <time.h>

# define ESC_KEY 0xff1b
# define HEIGHT 32
# define WIDTH 32
# define FPS 16

typedef struct s_game
{
	int			width;
	int			height;
	int			steps;
	char		**map;
	t_player	player;
	t_enemy		enemy;
	t_img		base_image;
	t_texture	texture;
	t_comp		comp;
	t_animation	*animation;
	t_exit		end_exit;
}	t_game;

// Initialization
void	init_game(t_game *game);
t_win	new_window(int w, int h, char *str);

// Game
bool	is_end_game(t_game *game);

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
void	map_to_map(char **src, char **dst, t_game *game);
void	free_map_copy(char **map_copy, t_game *game);
void	put_comp(t_game *game, int i, int j);

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
t_animation	*slice_sprite(t_sprite s, t_sprite_slice slice, int frames, enum e_entity e);
void		destory_sprite(t_sprite s);
void	load_sprites(t_game *game);
void	sprite_to_list(t_game *game, t_win win);

// Animation
int		update(t_game *game);
void	update_animation(void *list_p, void *game_p);
void	check_enetity(t_animation *a, t_game *game, t_img *img);
void	render_enemy_sprite(t_game *game, t_img *img);
void	render_space_sprite(t_game *game);
void	render_collectible_sprite(t_game *game, t_img *img);
void	render_player_sprite(t_game *game, t_img *img);
// Draw shapes
// void	draw_circle(t_player *data, int center_x,
//	int center_y, int radius, int color);
// void	draw_square(t_player *data, int x,
//	int y, int size, int color);
// void	draw_grad_square(t_player *data, int x, int y, int size);
// void	generate_checked_texture(t_player *data, int width, int height);

// Color
int	create_trgb(int t, int r, int g, int b);

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

// Steps
void	put_steps_on_screen(t_game *game);

// Time
uint64_t	timestamp_in_ms(void);

// Debug
int		print_error(char *msg);

#endif // !SO_LONG_H
