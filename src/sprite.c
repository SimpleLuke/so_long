/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:24:07 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 18:30:16 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	new_sprite(char *name, char *file_path, t_win *win)
{
	t_img	img;

	img = new_file_img(file_path, *win);
	return ((t_sprite){NULL, ft_strdup(name), ft_strdup(file_path),
		img, img.w, img.h, 0});
}

void	add_frame(t_animation *a, t_sprite s, t_sprite_slice slice)
{
	t_img	*frame;
	int		i;
	int		j;

	// frame = (t_img *)ft_calloc(1, sizeof(t_img));
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
	// mlx_destroy_image(frame->win.mlx, frame->img_ptr);
	// free(frame);
}

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

void	destory_sprite(t_sprite s)
{
	free(s.name);
	free(s.file_path);
}
