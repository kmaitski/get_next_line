/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:44:39 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/27 09:11:03 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/******************************************************
**               funtion prototypes                 ***
*******************************************************/
int get_next_line(const int fd, char **line);
static int find_new_line (char *str);

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  find_new_line
 *  Description:  Returns the spot where a \n character was found in a string or
 *  			  a -1 if there is no \n.
 * =============================================================================
 */
static int	find_new_line (char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return ((int)i);
	return (-1);
}		/* -----  end of function find_new_line  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  get_next_line
 *  Description:  Returns a line ending in a new line that was read from a file
 *  			  descriptor.
 * =============================================================================
 */
int 		get_next_line(const int fd, char **line)
{
	int		bytes_read;
	char	buffer[BUFF_SIZE];
	int		spot_of_newline;
	char	*tmp;

	if (fd < 0 || !line)
		return (-1);
	while ((bytes_read = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		spot_of_newline = find_new_line(buffer);
		*line = ft_strnew(bytes_read);
		if (spot_of_newline && spot_of_newline < --bytes_read)
		{
			tmp = ft_strsub(buffer, 0, ++spot_of_newline);
			ft_strcat(*line, tmp);
			free (tmp);
			return (1);
		}
		else
			ft_strcat(*line, buffer);
	}
	if (bytes_read == -1)
		return (-1);
	return (0);
}		/* -----  end of function get_next_line  ----- */
