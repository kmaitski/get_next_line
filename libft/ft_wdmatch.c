/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:47:22 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 21:15:48 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ft_wdmatch
 *  Description:  Takes two strings and checks whether it's possible to write the first
 *  			  string with characters from the second string, while respecting the
 *  			  order in which these characters appear in the second string. If it's
 *  			  possible, the function returns the string, otherwise it returns null.
 * =====================================================================================
 */
char	*ft_wdmatch(char *str1, char *str2)
{
	unsigned int	i;
	int				j;
	int				k;

	i = ft_strlen(str1);
	j = -1;
	k = -1;
	while (str1[++j])
	{
		while (str2[++k])
		{
			if (str1[j] == str2[k])
			{
				i--;
				break ;
			}
		}
	}
	if (i == 0)
		return (str1);
	else
		return (NULL);
}		/* -----  end of function ft_wdmatch  ----- */
