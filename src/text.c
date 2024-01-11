/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:57:07 by llai              #+#    #+#             */
/*   Updated: 2024/01/11 16:16:08 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_steps_on_screen(t_game *game)
{
	char	*steps;
	char	*format;

	format = ft_strdup("STEPS:");
	steps = ft_itoa(game->steps);
	format = ft_strjoin_gnl(format, steps, ft_strlen(steps));
	mlx_string_put(game->base_image.win.mlx, game->base_image.win.win_ptr, ((game->end_exit.x) * 32 - 10), (game->end_exit.y + 1) * 32, create_trgb(0, 0, 0, 0), format);
	// mlx_string_put(game->base_image.win.mlx, game->base_image.win.win_ptr, 0, (1) * 32, create_trgb(0, 0, 0, 0), format);
	free(format);
	free(steps);
}
