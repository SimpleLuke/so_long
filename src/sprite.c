/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:24:07 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 13:26:54 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which creates sprites into slice and 
 *  	converts it into frames, then it adds in the animation list.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

t_sprite	new_sprite(char *name, char *file_path, t_win *win);
void		add_frame(t_animation *a, t_sprite s, t_sprite_slice slice);
t_animation	*slice_sprite(t_sprite s, t_sprite_slice slice,
						int frames, enum e_entity e);

/* **************************************************************************
 * t_sprite	new_sprite(char *name, char *file_path, t_win *win)
 *
 * Summary of the function:
 * 
 * This function creates new t_sprite from a xpm file.
 *
 * Parameters : A string of the sprite name, file path and t_win.
 *
 * Return Value : It returns a t_sprite struct.
 * **************************************************************************/
t_sprite	new_sprite(char *name, char *file_path, t_win *win)
{
	t_img	img;

	img = new_file_img(file_path, *win);
	return ((t_sprite){NULL, ft_strdup(name), ft_strdup(file_path),
		img, img.w, img.h, 0});
}

/* **************************************************************************
 * t_animation	*slice_sprite(t_sprite s, t_sprite_slice slice,
 *							int frames, enum e_entity e)
 *
 * Summary of the function:
 * 
 * This function creates a new t_animation, then it adds frames into
 * the frames list in t_animation. Finally, it returns a t_animation
 * for adding into the animation t_list in the t_sprite.
 *
 * Parameters : A t_sprite, t_sprite_slice, frames counts and 
 * which entity.
 *
 * Return Value : It returns a pointer to t_animation.
 * **************************************************************************/
t_animation	*slice_sprite(t_sprite s, t_sprite_slice slice,
						int frames, enum e_entity e)
{
	int			i;
	t_animation	*a;

	a = (t_animation *)malloc(sizeof(t_animation));
	if (!a)
		return (NULL);
	*a = (t_animation){NULL, slice.width, slice.height, 0, 0, 0, 0, e};
	i = 0;
	while (i < frames)
	{
		add_frame(a, s, slice);
		slice.x += slice.width;
		if (slice.x >= s.width)
		{
			slice.x = 0;
			slice.y += slice.height;
		}
		i++;
	}
	return (a);
}

/* **************************************************************************
 * void	add_frame(t_animation *a, t_sprite s, t_sprite_slice slice)
 *
 * Summary of the function:
 * 
 * This function creates a new t_img from the sprite based 
 * on the slice size. Then, it adds to animation frames list.
 *
 * Parameters : A pointer to t_animation, a t_sprite and t_sprite_slice.
 *
 * Return Value : It returns nothing.
 * **************************************************************************/
void	add_frame(t_animation *a, t_sprite s, t_sprite_slice slice)
{
	t_img	*frame;
	int		i;
	int		j;

	frame = (t_img *)malloc(sizeof(t_img));
	if (!frame)
		return ;
	*frame = new_img(slice.width, slice.height, s.sprite_img.win);
	i = 0;
	while (i < slice.width)
	{
		j = 0;
		while (j < slice.height)
		{
			put_pixel_img(*frame, j, i, get_pixel_img(s.sprite_img,
					slice.x + j, slice.y + i));
			j++;
		}
		i++;
	}
	ft_lstadd_back(&a->frames, ft_lstnew(frame));
}
