/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:57:12 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 17:05:34 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strequ
 *  Description:  Lexicographical comparison between s1 and s2. If the 2 strings
 *  			  are identical the function returns 1, or 0 otherwise.
 * =============================================================================
 */
int	ft_strequ(char const *s1, char const *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i])
	{
		if (!s1[i] && !s2[i])
			return (1);
		i++;
	}
	return (0);
}	  /* -----  end of function ft_strequ  ----- */
