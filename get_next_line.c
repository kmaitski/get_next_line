/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:40:25 by kmaitski          #+#    #+#             */
/*   Updated: 2017/05/14 14:58:50 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  intialize_line
 *  Description:  Intializes line and shrinks store
 * =====================================================================================
 */
static int	intialize_line(int newline_location, int length, char **store, char **line)
{
	if (newline_location > 0)
	{
		*line = ft_strsub(*store, 0, newline_location);
		newline_location++;
		*store = ft_strsub(*store, newline_location, length - newline_location);
		return (1);
	}
	else if (newline_location == 0)
	{
		*store = ft_strsub(*store, 1, length - 1);
		*line = ft_strnew(1);
		return (1);
	}
	else
	{
		*line = ft_strsub(*store, 0, length);
		*store = NULL;
		return (1);
	}
}		/* -----  end of function intialize_line  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_newline
 *  Description:  Returns the location of the newline character and -1 if none.
 * =====================================================================================
 */
static int	find_newline (char *store)
{
	int	newline_location;

	newline_location = 0;
	while (store[newline_location])
	{
		if (store[newline_location] == '\n')
			return (newline_location);
		newline_location++;
	}		
	return (-1);
}		/* -----  end of function find_newline  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  read_into_store
 *  Description:  Reads from the file to the pointer store.
 * =====================================================================================
 */
static void	read_into_store (int fd, char **store)
{
	int	read_bytes;
	char	buffer[BUFF_SIZE];
	int	store_bytes;

	store_bytes = 1;
	while (store_bytes)
	{
		read_bytes = read(fd, buffer, BUFF_SIZE);
		store_bytes = read_bytes;
		buffer[store_bytes] = '\0';
		if (ft_strlen(*store) == 0)
			*store = ft_strdup(buffer);
		else
			*store = ft_strcat(*store, buffer);
	}
}		/* -----  end of function read_into_store  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_next_line
 *  Description:  Returns a line ending in a new line that was read from a file
 *  			  descriptor.
 * =====================================================================================
 */
int	get_next_line (int fd, char **line)
{
	static char	*store = NULL;
	int			newline_location;
	int			length;

	if (!store)
	{
		store = ft_strnew(1);
		read_into_store(fd, &store);
	}
	while (*store)
	{
		newline_location = find_newline(store);
		length = ft_strlen(store);
		return (intialize_line(newline_location, length, &store, line));
	}
	return (0);
}		/* -----  end of function get_next_line  ----- */
