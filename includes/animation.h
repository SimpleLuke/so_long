/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:59:00 by llai              #+#    #+#             */
/*   Updated: 2024/01/13 13:38:52 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "../libft/libft.h"
# include "comp.h"

typedef struct s_animation
{
	t_list			*frames;
	int				width;
	int				height;
	int				_tmp_delay;
	int				current_frame_num;
	long int		last_updated;
	long int		frame_count;
	enum e_entity	entity;
}	t_animation;

#endif // !ANIMATION_H
