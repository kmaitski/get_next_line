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
//	char *str;

//	str = (char *)malloc(sizeof(char) * 10000);

//	*str = '\0';
//	ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
//	ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
//	ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	write(fd, "aaa", 3);
	close(fd);
	fd = open("textfile.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s", line);
	}
}
