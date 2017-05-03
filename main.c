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
//	const int	fd = open("textfile.txt", O_RDWR);
	char *line;

//	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
	while (get_next_line(0, &line))
	{
		printf("%s", line);
	}
}
