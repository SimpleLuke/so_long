/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:33:09 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 20:51:05 by llai             ###   ########.fr       */
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
	// t_animation	*animation;
	t_exit		end_exit;
}	t_game;

/* ======================================================================= */
// Initialization - init.c
/* ======================================================================= */
/* **************************************************************************
 * void	init_game(t_game *game)
 *
 * Summary of the function:
 * 
 * 	This function initialises the game structure.
 *
 * Parameters : A pointer to a t_game type.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	init_game(t_game *game);

/* **************************************************************************
 * t_win	new_window(int w, int h, char *str)
 *
 * Summary of the function:
 * 
 * 	This function initialises the mlx pointer and the window pointer.
 *
 * Parameters : The width and height of the window and a string for The
 *				window name.
 *
 * Return Value : It returns a t_win struct.
 * **************************************************************************/
t_win	new_window(int w, int h, char *str);


/* ======================================================================= */
// Map 
// map.c
/* ======================================================================= */
/* **************************************************************************
 * char	*read_map(t_game *game, char *map_path)
 *
 * Summary of the function:
 * 
 * This function reads the text file and coverts the value into the game
 * struct. Before storing the values, it checks if the map is valid for 
 * the game.
 * If the map is not valid, it prints out the error and exit the programe.
 *
 * Parameters : A pointer to t_game and the path of a map.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	read_map(t_game *game, char *map_path);

/* **************************************************************************
 * bool	check_map(t_game *game, char *map_line)
 *
 * Summary of the function:
 * 
 * This function checks if the map is a valid map.
 * If it is, it will put enemy symbol in the map when the space ratio
 * is enough.
 *
 * Parameters : A pointer to t_game, a string.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
int		convert_map(t_game *game, char *map_line);

// map_utils.c
/* **************************************************************************
 * bool	check_wall(t_game *game)
 *
 * Summary of the function:
 * 
 * This function reads the text file and check if the map are
 * surrounded by the wall symbols.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	check_wall(t_game *game);

/* **************************************************************************
 * bool	check_comp(t_game *game)
 *
 * Summary of the function:
 * 
 * This function reads the text file and check if the map are
 * filled with componments symbols.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	check_comp(t_game *game);

/* **************************************************************************
 * bool	check_rec(t_game *game, char *map_line)
 *
 * Summary of the function:
 * 
 * This function reads the text file and check if the map is
 * a rectangle.
 *
 * Parameters : A pointer to t_game and a string of map line.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	check_rec(t_game *game, char *map_line);

/* **************************************************************************
 * void	init_gamemap(t_game *game)
 *
 * Summary of the function:
 * 
 * This function initialise the game map inside game stuct.
 * Exit if the memory allocation failed.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	init_gamemap(t_game *game);

/* ======================================================================= */
// path.c
/* ======================================================================= */
/* **************************************************************************
 * bool	check_path(t_game *game)
 *
 * Summary of the function:
 * 
 * This function finds out if there is valid path by walking through every
 * cell and mark it as visited. If all the asscessible cells are visited
 * yet still did not find the exit, then it proves there is not valid
 * path.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
bool	check_path(t_game *game);

/* ======================================================================= */
// map_utils2.c
/* ======================================================================= */
/* **************************************************************************
 * void	map_to_map(char **src, char **dst, t_game *game)
 *
 * Summary of the function:
 * 
 * This function copies the src map into dst map.
 *
 * Parameters : A pointer to t_game and the 2D char array of src and dst.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	map_to_map(char **src, char **dst, t_game *game);

/* **************************************************************************
 * void	free_map_copy(char **map_copy, t_game *game)
 *
 * Summary of the function:
 * 
 * This function frees the copied map.
 *
 * Parameters : A pointer to t_game and the 2D char array of copied map.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	free_map_copy(char **map_copy, t_game *game);

// Render - render.c
/* **************************************************************************
 * void	render_image(t_game *game)
 *
 * Summary of the function:
 * 
 * This function creates a base image as canvas. Then, it renders the 
 * map and player on the canvas. Finally, it puts the image to 
 * window.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_image(t_game *game);

/* **************************************************************************
 * void	render_map(t_game *game)
 *
 * Summary of the function:
 * 
 * This function puts the respective map tiles on the base image.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_map(t_game *game);

/* **************************************************************************
 * void	render_player(t_game *game)
 *
 * Summary of the function:
 * 
 * This function puts the player sprite on the base image based on 
 * the map symbol.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_player(t_game *game);

/* **************************************************************************
 * void	render_sprite(t_game *game, char type, int row, int col)
 *
 * Summary of the function:
 * 
 * This function puts the sprite image based on the type and location
 * to the base image.
 *
 * Parameters : A pointer to t_game, type character and row & col index.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	render_sprite(t_game *game, char type, int row, int col);

/* ======================================================================= */
// render_utils.c
/* ======================================================================= */
/* **************************************************************************
 * void	load_image(t_game *game)
 *
 * Summary of the function:
 * 
 * This function loads the map and player images.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	load_image(t_game *game);

/* **************************************************************************
 * void	load_map_image(t_game *game)
 *
 * Summary of the function:
 * 
 * This function loads the map tiles assets as image and store it in the 
 * game structure.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	load_map_image(t_game *game);

/* **************************************************************************
 * void	load_player_image(t_game *game)
 *
 * Summary of the function:
 * 
 * This function loads the player sprite assets as image and store it in the 
 * game structure.
 *
 * Parameters : A pointer to t_game.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	load_player_image(t_game *game);

/* **************************************************************************
 * void	put_comp(t_game *game, int i, int j)
 *
 * Summary of the function:
 * 
 * This function renders sprite according the to map symbol.
 *
 * Parameters : A pointer to t_game and the x and y axis.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	put_comp(t_game *game, int i, int j);

t_img	new_file_img(char *path, t_win window);
t_img	new_img(int width, int height, t_win window);
void	put_img_to_img(t_img dst, t_img src, int x, int y);
void	put_pixel_img(t_img img, int x, int y, int color);
unsigned int	get_pixel_img(t_img img, int x, int y);

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
// Game
bool	is_end_game(t_game *game);

// Custom put pixel
void	my_mlx_pixel_put(t_player *data, int x, int y, int color);

// Time
uint64_t	timestamp_in_ms(void);

// Destroy
void	free_gamemap(t_game *game);

// Debug
int		print_error(char *msg);

#endif // !SO_LONG_H
