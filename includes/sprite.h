/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:06:18 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 15:58:52 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "image.h"
# include "../libft/libft.h"

enum e_entity
{
	COLLECTIBLE,
	PLAYER_UP,
	PLAYER_DOWN,
	PLAYER_RIGHT,
	PLAYER_LEFT,
	ENEMY_DOWN
};

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
	int			width;
	int			height;
	t_img		space;
	t_img		wall;
	t_img		collectible;
	t_img		map_exit;
	t_img		player_start;
	t_sprite	sprites;
}	t_texture;

typedef struct sprite_slice
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_sprite_slice;

#endif // !SPRITE_H
