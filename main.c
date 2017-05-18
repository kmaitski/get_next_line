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

int	main(void) {
	int	fd = open("textfile.txt", O_WRONLY);
	char *line;
//	int	error_return;
	char	*str;
	int	len = 50;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while (len--)
		ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
//	printf("%d", (int)ft_strlen(str));
//	write(fd, str, ft_strlen(str));


//	write(fd, "mnopqrstuvwxyzab", 16);
//	write(fd, "efgh\n", 5);
//	write(fd, "ijkl\n", 5);
//	write(fd, "mnop\n", 5);
//	write(fd, "qrst\n", 5);
//	write(fd, "uvwx\n", 5);
//	write(fd, "yzab\n", 5);
	close(fd);
	fd = open("textfile.txt", O_RDONLY);
/*  			error tests 				*/
//	error_return = get_next_line(42, &line);
//	printf("%d", error_return);
	while (get_next_line(fd, &line) > 0) {
		printf("%s", line);
//		printf("%d", (int)ft_strlen(line));
		printf("%d", ft_strcmp(str, line));
	}
}
