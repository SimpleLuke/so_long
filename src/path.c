/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:35:32 by llai              #+#    #+#             */
/*   Updated: 2024/01/06 13:23:56 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"
#include <stdbool.h>

// Checking the boundaries
bool	is_safe(int i, int j, int rows, int cols)
{
	if (i >= 0 && i < rows && j >= 0 && j < cols)
		return (true);
	return (false);
}

// Returns true if there is a valid path.
bool	is_valid_path(t_game *game, int i, int j, bool **visited)
{
	bool	up;
	bool	left;
	bool	down;
	bool	right;

	if (is_safe(i, j, game->height, game->width) && game->map[i][j] != '1' && !visited[i][j])
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

bool	check_path(t_game *game)
{
	int		i;
	int		j;
	bool	**visited;
	bool	flag;

	i = 0;
	j = 0;
	visited = (bool **)malloc(game->height * sizeof(bool *));
	i = 0;
	while (i < game->height)
	{
		visited[i] = (bool *)malloc(game->width * sizeof(bool));
		ft_memset(visited[i], 0, sizeof(bool) * game->width);
		i++;
	}
	flag = false;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P' && !visited[i][j])
			{
				if (is_valid_path(game, i, j, visited))
				{
					flag = true;
					break ;
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < game->height)
		free(visited[i++]);
	free(visited);
	if (flag)
	{
		ft_printf("YES\n");
		return (true);
	}
	else
	{
		ft_printf("NO\n");
		return (false);
	}
}
