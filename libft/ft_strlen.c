/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:50:37 by llai              #+#    #+#             */
/*   Updated: 2023/11/02 21:17:57 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 *  Description:
 *  It calculates the length of the string, 
 *  excluding the terminating null byte ('\0')
 *
 *  Return value:
 *  The number of bytes in the string s.
 *
 */

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++ != '\0')
		count++;
	return (count);
}
