/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:40:25 by kmaitski          #+#    #+#             */
/*   Updated: 2017/05/24 22:05:19 by kmaitski         ###   ########.fr       */
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
static void	intializeLine(int newlineLocation, int length, char **store, char **line) {
	char	*tmp;

	tmp = *store;
	if (newlineLocation > 0) {
		*line = ft_strsub(*store, 0, newlineLocation);
		newlineLocation++;
		*store = ft_strsub(*store, newlineLocation, length - newlineLocation);
	}
	else if (newlineLocation == 0) {
		*store = ft_strsub(*store, 1, length - 1);
		*line = ft_strnew(1);
	}
	else {
		*line = ft_strsub(*store, 0, length);
		*store = NULL;
	}
	free (tmp);
}		/* -----  end of function intialize_line  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_newline
 *  Description:  Returns the location of the newline character and -1 if none.
 * =====================================================================================
*/ 
static int	findNewline (char *store) {
	int	newlineLocation;

	newlineLocation = 0;
	while (store[newlineLocation]) {
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
void	readIntoStore (int fd, char **store, int *readBytes) {
	char	buffer[BUFF_SIZE];
	char	*tmp;

		*readBytes = read(fd, buffer, BUFF_SIZE);
		buffer[*readBytes] = '\0';
		if (!*store) {
			*store = ft_strdup(buffer);
			tmp = *store;
		}
		else if (*readBytes) {
			tmp = *store;
			*store = ft_strjoin(*store, buffer);
			free(tmp);
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
	int			readBytes;

	readBytes = 1;
	newlineLocation = -1;
	if (fd < 0 || !line)
		return (-1);
	while (readBytes > 0) {
		readIntoStore(fd, &store, &readBytes);
	}
	if (readBytes == -1)
		return (-1);
	if (*store)
	{
		length = ft_strlen(store);
		newlineLocation = findNewline(store);
		intializeLine(newlineLocation, length, &store, line);
//		printf("%s", *line);
		return (1);
	}
	return (0);
}		/* -----  end of function get_next_line  ----- */
