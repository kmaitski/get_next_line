/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 10:37:16 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/28 10:44:14 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  read_into_buffer
 *  Description:  Read from the file descriptor into the buffer.
 * =============================================================================
 */
void	read_into_buffer (int fd, char **line)
{
	int	read_bytes;

	while ((read_bytes = read(
	return <+return_value+>;
}		/* -----  end of function read_into_buffer  ----- */
/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  get_next_line
 *  Description:  Returns a line ending in a new line that was read from a file
 *  			  descriptor (fd)
 * =============================================================================
 */
int		get_next_line (int fd, char **line)
{
	if (fd < 0 || !line)
		return (-1);
	read_into_buffer(fd, line);
	return (0);
}		/* -----  end of function get_next_line  ----- */
