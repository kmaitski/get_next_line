/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 14:47:00 by kmaitski          #+#    #+#             */
/*   Updated: 2017/05/03 15:30:27 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/******************************************************
**               funtion prototypes                 ***
*******************************************************/
int find_newline (char *str);
int intialize_line (char *tmp, char **line, int fd);
int read_into_buffer (int fd, char **tmp);
int get_next_line (int fd, char **line);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_newline
 *  Description:  Return the spot of the new line.
 * =====================================================================================
 */
int	find_newline (char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}		/* -----  end of function find_newline  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  intialize_line
 *  Description:  Intialize the line.
 * =====================================================================================
 */
int	intialize_line (char *tmp, char **line, int fd)
{
	int	newline_location;
	int		len;

	newline_location = find_newline(tmp);
	len = ft_strlen(tmp);
	if (newline_location > 0)
		*line = ft_strsub(tmp, 0, newline_location);
	else if (newline_location == 0)
	{
		*line = NULL;
		tmp = ft_strsub(tmp, 1, len - ++newline_location);
	}
	else
	{
		read_into_buffer(fd, &tmp);
		intialize_line(tmp, line, fd);
	}
	return (newline_location);
}		/* -----  end of function intialize_line  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  read_into_buffer
 *  Description:  Read into the buffer and return the bytes read.
 * =====================================================================================
 */
int	read_into_buffer (int fd, char **tmp)
{
	int	read_bytes;
	char	buffer[BUFF_SIZE];
	int	return_bytes;

	read_bytes = read(fd, buffer, BUFF_SIZE);
	return_bytes = read_bytes;
	if (read_bytes)
	{
		buffer[read_bytes] = '\0';
		if (ft_strlen(*tmp) == 0)
			*tmp = ft_strdup(buffer);
		else
			*tmp = ft_strcat(*tmp, buffer);
	}
	return (return_bytes);
}		/* -----  end of function read_into_buffer  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_next_line
 *  Description:  Gets and returns a line from a file.
 * =====================================================================================
 */
int	get_next_line (int fd, char **line)
{
	static char	*tmp = NULL;
	int			read_bytes;
	int			newline_location;
	int			len;

	if (fd < 0 || !line)
		return (-1);
	read_bytes = 0;
	newline_location = -1;
	if (!tmp || (len = ft_strlen(tmp) == 0))
	{
		tmp = ft_strnew(1);
		read_bytes = read_into_buffer(fd, &tmp);
		if (!read_bytes)
			return (0);
	}
	if ((len = ft_strlen(tmp)) == 1)
	{
		free (tmp);
		free (line);
		return (0);
	}
	intialize_line(tmp, line, fd);
	tmp = ft_strchr(tmp, '\n');
	tmp++;
	return (1);
}		/* -----  end of function get_next_line  ----- */
