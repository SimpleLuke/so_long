/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:32:19 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 21:07:51 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which reads a map from a text file and 
 *  	converts the value into the game struct.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

void	read_map(t_game *game, char *map_path);
char	*map_to_line(t_game *game, int fd);
int		convert_map(t_game *game, char *map_line);
bool	check_map(t_game *game, char *map_line);
void	free_lines(char *line, char *map_line, char *trim);

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
void	read_map(t_game *game, char *map_path)
{
	int		fd;
	char	*map_line;

	fd = open(map_path, O_RDONLY);
	map_line = map_to_line(game, fd);
	if (!convert_map(game, map_line) && !check_map(game, map_line))
	{
		free_lines(0, map_line, 0);
		print_error("Error\nThe map is not valid.");
		free_gamemap(game);
		exit(EXIT_FAILURE);
	}
	free_lines(0, map_line, 0);
	close(fd);
	return ;
}

/* **************************************************************************
 * char	*map_to_line(t_game *game, int fd)
 *
 * Summary of the function:
 * 
 * This function converts each newline in the text file into one line.
 * The result is stored with the pointer to map_line.
 * It sets up the width and height for the game as well.
 *
 * Parameters : A pointer to t_game, a file desciptor.
 *
 * Return Value : It returns a string of line.
 * **************************************************************************/
char	*map_to_line(t_game *game, int fd)
{
	char	*trim;
	char	*line;
	char	*map_line;

	line = "";
	map_line = ft_strdup("");
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			game->width = ft_strlen(line) - 1;
			trim = ft_strtrim(line, "\n");
			map_line = ft_strjoin_gnl(map_line, trim, game->width);
			game->height += 1;
			free_lines(line, 0, trim);
		}
	}
	return (map_line);
}

/* **************************************************************************
 * int	convert_map(t_game *game, char *map_line)
 *
 * Summary of the function:
 * 
 * This function converts a line of map into the game 2D map array.
 *
 * Parameters : A pointer to t_game, a string.
 *
 * Return Value : It returns a successful 0 code.
 * **************************************************************************/
int	convert_map(t_game *game, char *map_line)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = 0;
	init_gamemap(game);
	while (map_line[i] != '\0')
	{
		game->map[j][k] = map_line[i];
		i++;
		k++;
		if (k % game->width == 0)
		{
			j++;
			k = 0;
		}
	}
	return (0);
}

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
bool	check_map(t_game *game, char *map_line)
{
	if (!check_rec(game, map_line) || !check_comp(game)
		|| !check_wall(game))
		return (false);
	if (!check_path(game))
	{
		print_error("Error: Invalid path\n");
		return (false);
	}
	if (((double)game->comp.space / (game->height * game->width) * 100) > 40)
		put_enemy(game);
	return (true);
}

/* **************************************************************************
 * void	free_lines(char *line, char *map_line, char *trim)
 *
 * Summary of the function:
 * 
 * This function frees the memory allocation from the map reading.
 *
 * Parameters : A pointer to the line, map_line and trim.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	free_lines(char *line, char *map_line, char *trim)
{
	free(line);
	free(map_line);
	free(trim);
}
