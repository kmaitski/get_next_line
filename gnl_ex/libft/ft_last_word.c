/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:46:53 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 21:07:53 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_last_word
 *  Description:  Takes a string and returns its last word. A word is a section
 *  			  of string delimited by spaces/tabs or by the start/end of the 
 *  			  string.
 * =============================================================================
 */
char	*ft_last_word(char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(str);
	while (str[i] < 33 && i)
		i--;
	if (!i)
		return (NULL);
	j = i;
	while (str[j] > 32 && j)
		j--;
	j++;
	return (ft_strsub(str, j, i - j + 1));
}		/* -----  end of function ft_last_word  ----- */
