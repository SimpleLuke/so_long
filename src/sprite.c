/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:24:07 by llai              #+#    #+#             */
/*   Updated: 2024/01/10 10:30:47 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	new_sprite(char *name, char *file_path, t_win *win)
{
	t_img	img;

	img = new_file_img(file_path, *win);
	return ((t_sprite){NULL, ft_strdup(name), ft_strdup(file_path), img, img.w, img.h, 0});
}

void	add_frame(t_animation *a, t_sprite s, t_sprite_slice slice)
{
	t_img	*frame;
	int		i;
	int		j;

	frame = (t_img *)ft_calloc(sizeof(t_img), 1);
	if (!frame)
		return ;
	*frame = new_img(slice.width, slice.height, s.sprite_img.win);
	i = 0;
	while (i < slice.width)
	{
		j = 0;
		while (j < slice.height)
		{
			// put_pixel_img(*frame, slice.width - j, i, get_pixel_img(s.sprite_img, slice.x + j, slice.y + i));
			put_pixel_img(*frame, j, i, get_pixel_img(s.sprite_img, slice.x + j, slice.y + i));
			j++;
		}
		i++;
	}
	// mlx_put_image_to_window(frame->win.mlx, frame->win.win_ptr, frame->img_ptr, 0, 0);
	ft_lstadd_back(&a->frames, ft_lstnew(frame));
}

t_animation	*slice_sprite(t_sprite s, t_sprite_slice slice, int frames, int delay, enum e_entity e)
{
	int	i;
	t_animation	*a;

	a = (t_animation *)ft_calloc(sizeof(t_animation), 1);
	if (!a)
		return NULL;
	*a = (t_animation){NULL, slice.width, slice.height, delay, 0, 0, 0, 0, e};
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
	// ft_printf("HERE\n");
	// t_list *frame = a->frames;
	// while (frame != NULL)
	// {
	// 	ft_printf("%p\n", frame);
	// 	frame = frame->next;
	// }
	// ft_printf("list size:%d\n", ft_lstsize(a->frames));
	return (a);
}

void	destory_sprite(t_sprite s)
{
	free(s.name);
	free(s.file_path);
}
