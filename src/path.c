/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:35:32 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 21:04:46 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which walks through every cell on the map
 *  	to check if the map contains a valid path from start to end.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"
#include "../libft/libft.h"
#include <stdbool.h>

bool	check_path(t_game *game);
bool	is_valid_path(t_game *game, int i, int j, bool **visited);
void	init_visited(t_game *game, bool ***visited);
bool	is_safe(int i, int j, int rows, int cols);
void	free_visited(t_game *game, bool ***visited);

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
bool	check_path(t_game *game)
{
	int		i;
	int		j;
	bool	**visited;
	bool	flag;

	i = -1;
	flag = false;
	init_visited(game, &visited);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P' && !visited[i][j])
			{
				if (is_valid_path(game, i, j, visited))
				{
					flag = true;
					break ;
				}
			}
		}
	}
	free_visited(game, &visited);
	return (flag);
}

/* **************************************************************************
 * bool	is_safe(int i, int j, int rows, int cols)
 *
 * Summary of the function:
 * 
 * This function checks if it is out of boundary.
 *
 * Parameters : The current index of x and y. The game height and width.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_safe(int i, int j, int rows, int cols)
{
	if (i >= 0 && i < rows && j >= 0 && j < cols)
		return (true);
	return (false);
}

/* **************************************************************************
 * bool	is_valid_path(t_game *game, int i, int j, bool **visited)
 *
 * Summary of the function:
 * 
 * This function calls recursively to walk in 4 directions and
 * mark the cell as visited until it visits the exit. Or there is 
 * no exit after visiting all the avaible cells.
 *
 * Parameters : A pointer to t_game and index of x & y and a 2D 
 *				boolean array.
 *
 * Return Value : It returns true or false.
 * **************************************************************************/
bool	is_valid_path(t_game *game, int i, int j, bool **visited)
{
	bool	up;
	bool	left;
	bool	down;
	bool	right;

	if (is_safe(i, j, game->height, game->width)
		&& game->map[i][j] != '1' && !visited[i][j])
	{
		visited[i][j] = true;
		if (game->map[i][j] == 'E')
			return (true);
		up = is_valid_path(game, i - 1, j, visited);
		if (up)
			return (true);
		left = is_valid_path(game, i, j - 1, visited);
		if (left)
			return (true);
		down = is_valid_path(game, i + 1, j, visited);
		if (down)
			return (true);
		right = is_valid_path(game, i, j + 1, visited);
		if (right)
			return (true);
	}
	return (false);
}

/* **************************************************************************
 * void	init_visited(t_game *game, bool ***visited)
 *
 * Summary of the function:
 * 
 * This function create a 2D boolean array with the map size.
 *
 * Parameters : A pointer to t_game and a boolean 2D array.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	init_visited(t_game *game, bool ***visited)
{
	int	i;

	i = 0;
	*visited = (bool **)malloc(game->height * sizeof(bool *));
	while (i < game->height)
	{
		(*visited)[i] = (bool *)malloc(game->width * sizeof(bool));
		ft_memset((*visited)[i], 0, sizeof(bool) * game->width);
		i++;
	}
}

/* **************************************************************************
 * void	free_visited(t_game *game, bool ***visited)
 *
 * Summary of the function:
 * 
 * This function frees up the 2D boolean array.
 *
 * Parameters : A pointer to t_game and a boolean 2D array.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	free_visited(t_game *game, bool ***visited)
{
	int	i;

	i = 0;
	while (i < game->height)
		free((*visited)[i++]);
	free(*visited);
}
