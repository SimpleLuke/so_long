/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:18:56 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 21:02:47 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps reading and converting the map.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

bool	check_wall(t_game *game);
bool	check_comp(t_game *game);
int		count_comp(t_game *game, int row, int col);
bool	check_rec(t_game *game, char *map_line);
void	init_gamemap(t_game *game);

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
bool	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		while (j < game->width)
		{
			if ((i == 0 && game->map[i][j] != '1')
				|| (i == game->height - 1 && game->map[i][j] != '1'))
				return (false);
			if ((j == 0 && game->map[i][j] != '1')
				|| (j == game->width - 1 && game->map[i][j] != '1'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

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
bool	check_comp(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (count_comp(game, i, j))
				return (false);
		}
	}
	if (!game->comp.wall || !game->comp.space || !game->comp.collectible
		|| game->comp.map_exit != 1 || game->comp.player_start != 1)
	{
		ft_printf("Error: Invalid map componments\n");
		return (false);
	}
	return (true);
}

/* **************************************************************************
 * int	count_comp(t_game *game, int row, int col)
 *
 * Summary of the function:
 * 
 * This function reads the text file and stores the componments count
 * into game struct.
 *
 * Parameters : A pointer to t_game and row & col index.
 *
 * Return Value : It returns 1 when Invalid symbols present and
 *				  0 for success.
 * **************************************************************************/
int	count_comp(t_game *game, int row, int col)
{
	if (game->map[row][col] == '1')
		game->comp.wall++;
	else if (game->map[row][col] == '0')
		game->comp.space++;
	else if (game->map[row][col] == 'C')
		game->comp.collectible++;
	else if (game->map[row][col] == 'P')
		game->comp.player_start++;
	else if (game->map[row][col] == 'E')
	{
		game->comp.map_exit++;
		game->end_exit.x = col;
		game->end_exit.y = row;
		game->end_exit.points = 0;
		game->end_exit.is_end = false;
	}
	else
	{
		print_error("Error: Invalid componment symbol\n");
		return (1);
	}
	return (0);
}

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
bool	check_rec(t_game *game, char *map_line)
{
	if (ft_strlen(map_line) % game->width || game->height < 2)
	{
		print_error("Error: The map is not a rectangle\n");
		return (false);
	}
	return (true);
}

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
void	init_gamemap(t_game *game)
{
	int	i;

	i = -1;
	game->map = (char **)malloc(game->height * sizeof(char *));
	if (!game->map)
	{
		print_error("Error\nMemory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	while (++i < game->height)
	{
		game->map[i] = (char *)malloc(game->width * sizeof(char));
		if (!game->map[i])
		{
			print_error("Error\nMemory allocation failed.\n");
			exit(EXIT_FAILURE);
		}
	}
}
