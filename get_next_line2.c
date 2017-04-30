/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 10:37:16 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/30 14:29:18 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/******************************************************
**               funtion prototypes                 ***
*******************************************************/
unsigned int check_for_new_line(char *str);
void intialize_line(char *store, char **line);
int read_into_buffer(int fd, char *tmp, char **store);
int get_next_line(int fd, char **line);

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  check_for_new_line
 *  Description:  Check for a \n character and return the location.  Returns -1
 *  			  if not found.
 * =============================================================================
 */
unsigned int	check_for_new_line(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i + 1);
}		/* -----  end of function check_for_new_line  ----- */


/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  intialize_line
 *  Description:  Intialize line with store.
 * =============================================================================
 */
void			intialize_line(char *store, char **line)
{
	unsigned int	i;

	i = check_for_new_line(store);
	*line = ft_strsub(store, 0, i);
}		/* -----  end of function intialize_line  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  read_into_buffer
 *  Description:  Read from the file descriptor into the buffer.
 * =============================================================================
 */
int			read_into_buffer(int fd, char *tmp, char **store)
{
	int		read_bytes;
	char	buffer[BUFF_SIZE];

	while ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_bytes] = '\0';
		if (!tmp)
			tmp = ft_strdup(buffer);
		else
			tmp = ft_strjoin(tmp, buffer);
	}
	*store = ft_strdup(tmp);
	return (read_bytes);
}		/* -----  end of function read_into_buffer  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  get_next_line
 *  Description:  Returns a line ending in a new line that was read from a file
 *  			  descriptor (fd)
 * =============================================================================
 */
int				get_next_line(int fd, char **line)
{
	char	*tmp;
	int		read_bytes;
	char	*store;

	if (fd < 0 || !line)
		return (-1);
	tmp = ft_strnew(1);
	store = ft_strchr(tmp, '\n');
	if (!store)
	{
		tmp = ft_strnew(1);
		read_bytes = read_into_buffer(fd, tmp, &store);
	}
	{
		intialize_line(store, line);
		return (1);
	}
	if (!read_bytes)
		return (0);
}		/* -----  end of function get_next_line  ----- */
