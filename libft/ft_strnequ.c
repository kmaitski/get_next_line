/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:11:18 by kmaitski          #+#    #+#             */
/*   Updated: 2017/04/20 17:08:49 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strnequ
 *  Description:  Lexicographical comparison between s1 and s2 up to n characters
 *  			  or until a ’\0’ is reached. If the 2 strings are identical, the
 *  			  function returns 1, or 0 otherwise.
 * =====================================================================================
 */
int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	while (s1[i] == s2[i])
	{
		if ((!s1[i] && !s2[i]) || i == n - 1)
			return (1);
		i++;
	}
	return (0);
} 		/* -----  end of function ft_strnequ  ----- */
