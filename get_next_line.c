/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:40:25 by kmaitski          #+#    #+#             */
/*   Updated: 2017/05/18 12:39:42 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  intialize_line
 *  Description:  Intializes line and shrinks store
 * =====================================================================================
 */
static void	intializeLine(int newlineLocation, int length, char **store, char **line) {
	char	*tmp;

	if (newlineLocation > 0)
	{
		*line = ft_strsub(*store, 0, newlineLocation);
		newlineLocation++;
		tmp = ft_strsub(*store, newlineLocation, length - newlineLocation);
	}
	else if (newlineLocation == 0)
	{
		tmp = ft_strsub(*store, 1, length - 1);
		*line = ft_strnew(1);
	}
	else
	{
		*line = ft_strsub(*store, 0, length);
		tmp = NULL;
	}
	*store = tmp;
	free (tmp);
}		/* -----  end of function intialize_line  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_newline
 *  Description:  Returns the location of the newline character and -1 if none.
 * =====================================================================================
*/ 
static int	findNewline (char *store)
{
	int	newlineLocation;

	newlineLocation = 0;
	while (store[newlineLocation])
	{
		if (store[newlineLocation] == '\n')
			return (newlineLocation);
		newlineLocation++;
	}		
	return (-1);
}		 /* -----  end of function find_newline  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  read_into_store
 *  Description:  Reads from the file to the pointer store.
 * =====================================================================================
 */
void	readIntoStore (int fd, char **store, void *tmp) {
	int	readBytes;
	char	buffer[BUFF_SIZE];
	int 	storeBytes;

	storeBytes = 1;
	while (storeBytes) {
		readBytes = read(fd, buffer, BUFF_SIZE);
		storeBytes = readBytes;
		buffer[readBytes] = '\0';
		if (readBytes < 0)
			break ;
		else if (!*store) {
			tmp = ft_strdup(buffer);
			*store = (char *)tmp;
			ft_memdel(&tmp);
		}
		else if (storeBytes) {
			tmp = ft_strjoin(*store, buffer);
			*store = (char *)tmp;
			ft_memdel(&tmp);
		}
	}
}		/* -----  end of function read_into_store  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_next_line
 *  Description:  Returns a line ending in a new line that was read from a file
 *  			  descriptor.
 * =====================================================================================
 */
int	get_next_line (int fd, char **line) {
	static char	*store = NULL;
	int			newlineLocation;
	int			length;
	void		*tmp = NULL;

	if (fd < 0 || !line)
		return (-1);
	if (!store)
		readIntoStore(fd, &store, tmp);
	if (!store)
		return (-1);
	if (*store)
	{
		newlineLocation = findNewline(store);
		length = ft_strlen(store);
		intializeLine(newlineLocation, length, &store, line);
		return (1);
	}
	return (0);
}		/* -----  end of function get_next_line  ----- */
