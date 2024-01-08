/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:32:08 by llai              #+#    #+#             */
/*   Updated: 2024/01/08 13:35:55 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	new_file_img(char *path, t_game *game)
{
	t_img	image;

	image.img_ptr = mlx_xpm_file_to_image(game->mlx, path, &image.w, &image.h);
	if (!image.img_ptr)
		print_error("File could not be read\n");
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));
	return (image);
}
