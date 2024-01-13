/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:32:21 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 13:39:23 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMP_H
# define COMP_H

# include "image.h"
# include "sprite.h"
# include <stdbool.h>

typedef struct s_comp
{
	int	space;
	int	wall;
	int	collectible;
	int	map_exit;
	int	player_start;
}	t_comp;

enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STAY
};

typedef struct s_plocation {
	int	x; int	y;
}	t_plocation;

typedef struct s_player
{
	t_img		sprite;
	enum e_direction	position;
	t_plocation	location;
}	t_player;

typedef struct s_enemy
{
	t_sprite			enemy_sprite;
	enum e_direction	position;
}	t_enemy;

typedef struct s_exit
{
	int	x;
	int	y;
	int	points;
	bool	is_end;
}	t_exit;


#endif // !COMP_H
