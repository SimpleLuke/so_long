/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:06:40 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 20:10:54 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps reading and converting the map.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

void	map_to_map(char **src, char **dst, t_game *game);
void	free_map_copy(char **map_copy, t_game *game);

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
void	map_to_map(char **src, char **dst, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			dst[i][j] = src[i][j];
	}
}

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
void	free_map_copy(char **map_copy, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->height)
		free(map_copy[i]);
	free(map_copy);
}
