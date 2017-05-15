/*
 * ==================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Driver for get next line
 *
 *        Version:  1.0
 *        Created:  04/26/2017 16:56:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin Maitski (KM), kevin.maitski@gmail.com
 *   Organization:  42
 *
 * ==================================================================================
 */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("textfile.txt", O_WRONLY);
	char *line;
	int	nbr;

	write(fd, "abc\n\n", 5);
	close(fd);
	fd = open("textfile.txt", O_RDONLY);
	nbr = get_next_line(42, &line);
	printf("%d", nbr);
//	while (get_next_line(-99, NULL) > 0)
//	{
//		printf("%s", line);
//		printf("%d", (int)ft_strlen(line));
//	}
}
