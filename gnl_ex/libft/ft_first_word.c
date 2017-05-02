/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:46:35 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 21:08:25 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_first_word.c
 *  Description:  Takes a string and returns its first word. A word is a
 *  			  section of string delimited by spaces/tabs or by the start/end
 *  			  of the string.
 * =============================================================================
 */
char	*ft_first_word(char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i] < 33 && str[i])
		i++;
	if (!str[i])
		return (NULL);
	j = i;
	while (str[j] > 32 && str[j])
		j++;
	return (ft_strsub(str, i, j - i));
}		/* -----  end of function ft_first_word.c  ----- */
