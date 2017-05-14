/*
 * =====================================================================================
 *
 *       Filename:  main1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/14/2017 15:04:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin Maitski (KM), kevin.maitski@gmail.com
 *   Organization:  42
 *
 * =====================================================================================
 */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	gnl_ret = get_next_line(p[0], &line);
	printf("%s", line);
	printf("%d", ft_strcmp(line, "aaa"));
	printf("%d", gnl_ret);
}
