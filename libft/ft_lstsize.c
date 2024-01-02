/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:06:25 by llai              #+#    #+#             */
/*   Updated: 2023/11/08 21:08:05 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * 	Description:
 * 	It counts the size of the list.
 *
 * 	Return value;
 * 	The number of nodes.
 */

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
