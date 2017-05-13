/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:40:25 by kmaitski          #+#    #+#             */
/*   Updated: 2017/05/13 09:34:37 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  read_into_store
 *  Description:  Reads from the file to the pointer store.
 * =====================================================================================
 */
void	read_into_store (int fd, char **store)
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

	if (!store)
		store = ft_strnew(1);
	read_into_store(fd, &store);
	line = NULL;
	printf("%s", store);
	return (0);
}		/* -----  end of function get_next_line  ----- */
