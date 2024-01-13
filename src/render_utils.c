/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:09:08 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 20:10:39 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps rendering.
 *
 * ************************************************************************** */

# include "../includes/so_long.h"

void	put_comp(t_game *game, int i, int j);

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
void	put_comp(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		render_sprite(game, '1', i, j);
	else if (game->map[i][j] == '0')
		render_sprite(game, '0', i, j);
	else if (game->map[i][j] == 'C')
		render_sprite(game, '0', i, j);
	else if (game->map[i][j] == 'P')
	{
		render_sprite(game, 'P', i, j);
		game->player.location.x = j;
		game->player.location.y = i;
	}
	else if (game->map[i][j] == 'E')
		render_sprite(game, 'E', i, j);
	else if (game->map[i][j] == 'M')
		render_sprite(game, 'M', i, j);
}
