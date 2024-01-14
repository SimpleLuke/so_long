/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:17:48 by llai              #+#    #+#             */
/*   Updated: 2024/01/14 15:37:01 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
 *  Summary of File:                                                          
 *  
 *  	This file contains code which helps to calculate the elapsed time 
 *  	for animation based on FPS.
 *
 * ************************************************************************** */
#include <bits/types/struct_timeval.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdlib.h>

static uint64_t	gettimeofday_ms(void);
uint64_t		timestamp_in_ms(void);

/* **************************************************************************
 * static uint64_t	gettimeofday_ms(void)
 *
 * Summary of the function:
 * 
 * This function gets the current time in milliseconds.
 *
 * Parameters : Nothing.
 *
 * Return Value : It returns uint64_t as current time in milliseconds.
 * **************************************************************************/
static uint64_t	gettimeofday_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

/* **************************************************************************
 * uint64_t	timestamp_in_ms(void)
 *
 * Summary of the function:
 * 
 * This function calculates the elapsed time from last current time.
 *
 * Parameters : Nothing.
 *
 * Return Value : It returns uint64_t as elapsed time in milliseconds.
 * **************************************************************************/
uint64_t	timestamp_in_ms(void)
{
	static uint64_t	created_at = 0;

	if (created_at == 0)
		created_at = gettimeofday_ms();
	return (gettimeofday_ms() - created_at);
}
