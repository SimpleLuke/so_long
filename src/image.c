/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:32:08 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 12:52:56 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This program contains code which creates minilibx images.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

t_img	new_file_img(char *path, t_win window);
t_img	new_img(int width, int height, t_win window);
void	put_pixel_img(t_img img, int x, int y, int color);
void	put_img_to_img(t_img dst, t_img src, int x, int y);

/* **************************************************************************
 * t_img	new_file_img(char *path, t_win window)
 *
 * Summary of the function:
 * 
 * This function create a t_img image from minilibx with a xpm file.
 *
 * Parameters : A xpm file path and a t_win struct.
 *
 * Return Value : It returns a t_img image.
 * **************************************************************************/
t_img	new_file_img(char *path, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_xpm_file_to_image(window.mlx, path, &image.w, &image.h);
	if (!image.img_ptr)
		print_error("File could not be read\n");
	else
		image.addr = mlx_get_data_addr(image.img_ptr,
				&(image.bpp), &(image.line_len), &(image.endian));
	return (image);
}

/* **************************************************************************
 * t_img	new_img(int width, int height, t_win window)
 *
 * Summary of the function:
 * 
 * This function create a t_img image from minilibx.
 *
 * Parameters : A width & height of the image and a t_win.
 *
 * Return Value : It returns a t_img image.
 * **************************************************************************/
t_img	new_img(int width, int height, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx, width, height);
	image.addr = mlx_get_data_addr(image.img_ptr,
			&(image.bpp), &(image.line_len), &(image.endian));
	image.w = width;
	image.h = height;
	return (image);
}

/* **************************************************************************
 * void	put_pixel_img(t_img img, int x, int y, int color)
 *
 * Summary of the function:
 * 
 * This function fills color in the pixel address. It won't fill any if 
 * the color is transparent or black.
 *
 * Parameters : A t_img image, the x & y axis and the color.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000 || color == 0)
		return ;
	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

/* **************************************************************************
 * unsigned int	get_pixel_img(t_img img, int x, int y)
 *
 * Summary of the function:
 * 
 * This function gets the pixel color from the t_img at (x, y).
 *
 * Parameters : A t_img image and the x & y axis.
 *
 * Return Value : It returns unsigned int.
 * **************************************************************************/
unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.line_len) + (x * img.bpp / 8))));
}

/* **************************************************************************
 * void	put_img_to_img(t_img dst, t_img src, int x, int y)
 *
 * Summary of the function:
 * 
 * This function copies src t_img to dst t_img.
 *
 * Parameters : A t_img of dst & src and the designated location of src.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
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
