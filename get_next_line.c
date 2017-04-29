/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 10:37:16 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/29 12:53:47 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/******************************************************
**               funtion prototypes                 ***
*******************************************************/
unsigned int check_for_new_line(char *str);
void intialize_line(char *tmp, char *line);
int read_into_buffer(int fd, char *tmp);
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
 *  Description:  Intialize line with tmp.
 * =============================================================================
 */
void			intialize_line(char *tmp, char *line)
{
	unsigned int	i;

	i = check_for_new_line(tmp);
	line = ft_strsub(tmp, 0, i);
	tmp = ft_strdup(tmp, 0, ++i);
}		/* -----  end of function intialize_line  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  read_into_buffer
 *  Description:  Read from the file descriptor into the buffer.
 * =============================================================================
 */
int			read_into_buffer(int fd, char *tmp)
{
	int		read_bytes;
	char	buffer[BUFF_SIZE];

	while ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (!tmp)
			tmp = ft_strdup(buffer);
		else
			tmp = ft_strjoin(tmp, buffer);
	}
	if (read_bytes < 0)
		tmp = ft_strnew(1);
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

	if (fd < 0 || !line)
		return (-1);
	if (!tmp)
	{
		tmp = ft_strnew(1);
		read_bytes = read_into_buffer(fd, &tmp);
	}
	if (tmp)
	{
		intialize_line(&tmp, &line);
		return (1);
	}
	return (0);
}		/* -----  end of function get_next_line  ----- */
