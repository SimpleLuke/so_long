/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:32:08 by llai              #+#    #+#             */
/*   Updated: 2024/01/09 18:25:24 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	new_file_img(char *path, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_xpm_file_to_image(window.mlx, path, &image.w, &image.h);
	if (!image.img_ptr)
		print_error("File could not be read\n");
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));
	return (image);
}

t_img	new_img(int width, int height, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx, width, height);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));
	image.w = width;
	image.h = height;
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	// ft_printf("COLOR:%X\n", color);
	if (color == (int)0xFF000000 || color == 0)
		return ;
	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_len) + (x * img.bpp / 8))));
}

void	put_img_to_img(t_img dst, t_img src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.w)
	{
		j = 0;
			while (j < src.h)
			{
				put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
				j++;
			}
		i++;
	}
}
