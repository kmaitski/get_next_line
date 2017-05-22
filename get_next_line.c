/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:40:25 by kmaitski          #+#    #+#             */
/*   Updated: 2017/05/21 20:58:15 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	intialize_line(int newline_location, int length, char **store, char
		**line)
{
	char	*tmp;

	tmp = *store;
	if (newlineLocation > 0)
	{
		*line = ft_strsub(*store, 0, newlineLocation);
		newlineLocation++;
		*store = ft_strsub(*store, newlineLocation, length - newlineLocation);
	}
	else if (newlineLocation == 0)
	{
		*store = ft_strsub(*store, 1, length - 1);
		*line = ft_strnew(1);
	}
	else
	{
		*line = ft_strsub(*store, 0, length);
		*store = NULL;
	}
	free(tmp);
}

static int	find_newline(char *store)
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
}

static void	read_into_store(int fd, char **store, char *tmp)
{
	int		read_bytes;
	char	buffer[BUFF_SIZE];
	int		store_bytes;

	store_bytes = 1;
	while (store_bytes)
	{
		read_bytes = read(fd, buffer, BUFF_SIZE);
		store_bytes = read_bytes;
		buffer[read_bytes] = '\0';
		if (read_bytes < 0)
			break ;
		else if (!*store)
		{
			*store = ft_strdup(buffer);
		}
		else if (store_bytes)
		{
			tmp = *store;
			*store = ft_strjoin(*store, buffer);
			free(tmp);
		}
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*store = NULL;
	int			newline_location;
	int			length;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || !line)
		return (-1);
	if (!store)
		read_into_store(fd, &store, tmp);
	if (!store)
		return (-1);
	if (*store)
	{
		newline_location = find_newline(store);
		length = ft_strlen(store);
		intialize_line(newline_location, length, &store, line);
		return (1);
	}
	return (0);
}
