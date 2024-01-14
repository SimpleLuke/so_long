/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:46:04 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 15:56:47 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps to manipulate color.
 *
 * ************************************************************************** */

/* **************************************************************************
 * int	create_trgb(int t, int r, int g, int b)
 *
 * Summary of the function:
 * 
 * This function creates a hex integer based on trgb.
 *
 * Parameters : An integer of transparent, red, green and blue.
 *
 * Return Value : It returns an integer.
 * **************************************************************************/
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
