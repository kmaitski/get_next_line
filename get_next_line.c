/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:40:25 by kmaitski          #+#    #+#             */
/*   Updated: 2017/05/15 16:35:32 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  intialize_line
 *  Description:  Intializes line and shrinks store
 * =====================================================================================
 */
static int	intialize_line(int newline_location, int length, char **store, char **line)
{
	char	*tmp;

	tmp = *store;
	free(*store);
	if (newline_location > 0)
	{
		*line = ft_strsub(tmp, 0, newline_location);
		newline_location++;
		*store = ft_strsub(tmp, newline_location, length - newline_location);
	}
	else if (newline_location == 0)
	{
		*store = ft_strsub(tmp, 1, length - 1);
		*line = ft_strnew(1);
	}
	else
	{
		*line = ft_strsub(tmp, 0, length);
		*store = NULL;
	}
	return (1);
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
static char	*read_into_store (int fd)
{
	int	read_bytes;
	char	buffer[BUFF_SIZE];
	char	*store;
	char	*tmp;

	store = NULL;
	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buffer, BUFF_SIZE);
		buffer[read_bytes] = '\0';
		if (read_bytes < 0)
			break ;
		else if (!store)
			store = ft_strdup(buffer);
		else
		{
			tmp = store;
			free(store);
			store = ft_strjoin(tmp, buffer);
		}
	}
	return (store);
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

	if (fd < 0 || !line)
		return (-1);
	if (!store)
		store = read_into_store(fd);
	if (!store)
		return (-1);
	if (*store)
	{
		newline_location = find_newline(store);
		length = ft_strlen(store);
		return (intialize_line(newline_location, length, &store, line));
	}
	return (0);
}		/* -----  end of function get_next_line  ----- */
