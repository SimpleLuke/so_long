/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:13:22 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 13:47:23 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* **************************************************************************
 * void	push_swap(t_node *head, t_node *tail, int len)
 *
 * Summary of the function:
 * 
 * 	This function sorts the list and ouput the steps.
 * 	It excutes different sorting algorithms depends on the size
 * 	of the list.
 *
 * Parameters : The head node and the tail node and the length of the list.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	init_game(t_game *game)
{
	srand(time(NULL));
	game->steps = 0;
	game->width = 0;
	game->height = 0;
	game->comp.space = 0;
	game->comp.wall = 0;
	game->comp.collectible = 0;
	game->comp.map_exit = 0;
	game->comp.player_start = 0;
	game->player.position = DOWN;
}

t_win	new_window(int w, int h, char *str)
{
	void	*mlx;

	mlx = mlx_init();
	return ((t_win){mlx, mlx_new_window(mlx, w, h, str), w, h});
}
