/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:46:19 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 21:01:22 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_ulstr
 *  Description:  Takes a string and reverses the case of all its letters. Other
 *  			  characters remain unchanged.
 * =============================================================================
 */
char	*ft_ulstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		else if (*str >= 'a' && *str <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}		/* -----  end of function ft_ulstr  ----- */
