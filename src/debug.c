/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:26:17 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 15:36:42 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps to debug.
 *
 * ************************************************************************** */
#include "../includes/so_long.h"

/* **************************************************************************
 * int	print_error(char *msg)
 *
 * Summary of the function:
 * 
 * This function outputs message on stderr.
 *
 * Parameters : A string of message.
 *
 * Return Value : It returns the length of output text.
 * **************************************************************************/
int	print_error(char *msg)
{
	int	len;

	len = ft_strlen(msg);
	write(2, msg, len);
	return (len);
}
