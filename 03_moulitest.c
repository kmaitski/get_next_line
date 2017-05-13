/*
 * =====================================================================================
 *
 *       Filename:  03_moulitest.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/11/2017 14:39:29
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

int	main(void)
{
char 	*line;
int		out;
int		p[2];
char 	*str;
int		gnl_ret;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	ft_strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	write(1, str, ft_strlen(str));
	close(p[1]);
	dup2(out, 1);
	gnl_ret = get_next_line(p[0], &line);
	printf("%s", str);
}
